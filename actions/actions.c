#include "actions.h"

findStudent(int id){
    for (int i = 0; i < StudentCount; i++){
        if (Students[i].id == id){
            return i;
        }
    }
    return -1; //return not valid[
}

insertDB(char *command){
    Student newStudent;
    int field = sscanf(command, "%d %49s %49s %f", &newStudent.id, newStudent.name, newStudent.programme, &newStudent.mark);

    if (field != 4){
        printf("Invalid Format!");
        return -1;
    }

    if (strlen(newStudent.name) == 0 || strlen(newStudent.programme) == 0 || newStudent.mark < 0){
        printf("No Data!");
        return -1;
    }
    
    if (StudentCount >= MAX_STUDENT){
        printf("Limit Reached.");
        return -1;
    }

    if (findStudent(newStudent.id) != -1) {
        printf("Student ID already exists.\n");
        return -1;
    }

    Students[StudentCount++] = newStudent;
    printf("Record with ID=%d added successfully.", newStudent.id);
    return 0;
}

void deleteDB(char *command){
    int id ;
    //DELETE ID=[id]
    sscanf(command, "ID=%d", &id);
    if(sscanf(command, "ID=%d", &id) !=1){
        printf("Invalid Format!");
        return;
    }

    int index = findStudent(id);
    if (index == -1){
        printf("Record does not exist.");
    }

    printf("Confirm Delete? (press Y) if not, (Press N)");
    char confirm[10];
    fgets(confirm, sizeof(confirm),stdin);
    confirm[strcspn(command,"\n")] = 0;

    if(strcmp(confirm, "Y") == 0 || strcmp(confirm,"y") == 0){
        for (int i = index; i < StudentCount; i++)
        {
            Students[i] = Students[i+1];
        }
        StudentCount--;
        printf("ID=%d has been deleted successfully.", id);
    }
    else{
        printf("Delete Cancelled");
    }    
}

updateDB(char *command){
    Student updateStudent;
    int field = sscanf(command, "%d %49[^ ] %49[^ ] %f", &updateStudent.id, updateStudent.name, updateStudent.programme, &updateStudent.mark);
    if (field != 4){
        printf("Invalid Format!");
        return -1;
    }
    if (strlen(updateStudent.name) == 0 || strlen(updateStudent.programme) == 0 || updateStudent.mark < 0){
        printf("Invalid Data!");
        return -1;
    }
    
    
    int index = findStudent(updateStudent.id);
    if (index == -1){
        printf("Record does not exist.");
        return -1;
    }

    Students[index] = updateStudent;
    printf("Record with ID=%d updated successfully.", updateStudent.id);
    return 0;
}

void queryDB(char *command){
    int id;
    sscanf(command, "%d", &id);

    int index = findStudent(id);
    Student *s = &Students[index];
    if (index == -1){
        printf("Record does not exist");
        return;
    }
    else{
        printf("Student found");
        printf("ID: %d, Name:%s. Programme: %s, Mark: %.2f", s->id, s->name, s->programme, s->mark);
    }
}
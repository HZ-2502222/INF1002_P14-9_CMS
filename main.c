#include <common.h>
#include "actions/actions.h"
#include "display/display.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

Student Students[MAX_STUDENT];
int StudentCount = 0;
char command[MAX_LINE];


int main(){
    printf("Type Command:");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0;  //removes break line from fgets

    if (strcmp(command, "OPEN") == 0){
        openDB();
    }
    else if (strcmp(command, "SAVE") == 0){
        saveDB();
    }
    else if (strncmp(command, "INSERT", 6) == 0){
        insertDB(command + 7);
    }
    else if (strncmp(command, "DELETE", 6) == 0){
        deleteDB(command + 7);
    }
    else if (strncmp(command, "UPDATE", 6) == 0)
    {
        updateDB(command + 7);
    }
    else if (strncmp(command, "QUERY", 6) == 0)
    {
        queryDB(command + 7);
    }
    else if (strcmp(command, "SHOWALL") == 0){
        showAll();
    }
    else{
        printf("Invalid Command!");
    }

    return 0;
}
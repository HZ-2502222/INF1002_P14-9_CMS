#include "display.h"

void showAll(char *command){
    if (StudentCount == 0){
        printf("No records found in database");
        return;
    }
    
    printf("%-10s %-15[^ ] %-15[^ ] %-10s\n", "ID", "Name", "Programme", "Mark");
    for (int i = 0; i < StudentCount; i++){
        printf("%-10d %-15[^ ] %-15[^ ] %-10.2f\n", Students[i].id, Students[i].name, Students[i].programme, Students[i].mark);
    }
}

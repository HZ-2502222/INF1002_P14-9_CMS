#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENT 100
#define MAX_LINE 256
#define FILENAME  "CMS.txt" //database file

//4 variables

typedef struct{
    int id;
    char name[50];
    char programme[50];
    float mark;
} Student;

//name of table, structure of table, max num of entries
extern Student Students[MAX_STUDENT];
extern int StudentCount;

#endif // !COMMON_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_PROFS 6
#define NUMBER_COURSES 10

int numProfsTeachingNCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char profNames[NUMBER_PROFS][30]);
int numProfsTeachingNLevelCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, int courseID[NUMBER_COURSES], char profNames[NUMBER_PROFS][30]);
int coursesWithNProfs(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char courseNames[NUMBER_COURSES][50]);
float avgNumCourses(char data[NUMBER_PROFS][NUMBER_COURSES]);
int getCourseName (int courseNum, int courseID[NUMBER_COURSES], char cNameFound [50], char courseNames[NUMBER_COURSES][50]);
int getCourseNum (char cName [50], int courseID[NUMBER_COURSES], int * cNumFound, char courseNames[NUMBER_COURSES][50]);

void    readCourseProfData (char filename [50], char courseNames[NUMBER_COURSES][50], char profNames[NUMBER_PROFS][30], int courseID[NUMBER_COURSES]);
void readData (char [], char data[NUMBER_PROFS][NUMBER_COURSES]);

void generateReport(char data[NUMBER_PROFS][NUMBER_COURSES],int courseID[NUMBER_COURSES],char courseNames[NUMBER_COURSES][50],char profNames[NUMBER_PROFS][30]);

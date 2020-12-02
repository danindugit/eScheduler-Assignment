/************************marasingheDaninduA3.c**************
Student Name: Danindu Marasinghe Email Id: dmarasin@uoguelph.ca
Due Date: Course Name: CIS 1300
 I have exclusive control over this submission via my password.
 By including this statement in this header comment, I certify that:
 1) I have read and understood the University policy on academic
 integrity;
 2) I have completed the Computing with Integrity Tutorial on
 Moodle; and
 3) I have achieved at least 80% in the Computing with Integrity
 Self Test.
I assert that this work is my own. I have appropriately acknowledged
any and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared
by me specifically for this course.
 **********************************************************/

#include "givenA3.h"

int main (int argc, char* argv[]){
    int i;
    int j;
    char filename1[50];
    char filename2[50];
    char courseNames[NUMBER_COURSES][50];
    char profNames [NUMBER_PROFS][30];
    int courseID [NUMBER_COURSES];
    char data[NUMBER_PROFS][NUMBER_COURSES];

    if(argc != 3){
        //if incorrect number of command line args
        printf("Usage: ./a.out courses.txt data.txt");
        return -1;
    }

    //get filename from 2nd command line arg and call rad CourseProfData with it 
    strcpy(filename1, argv[1]);
    readCourseProfData(filename1, courseNames, profNames, courseID);

    strcpy(filename2, argv[2]);
    readData(filename2, data);

    // //test readCourseProfData
    // for (i = 0; i < NUMBER_COURSES; i++)
    // {
    //     printf("%d: %s\n", courseID[i], courseNames[i]);
    // }
    // for (i = 0; i < NUMBER_PROFS; i++)
    // {
    //     printf("%s\n", profNames[i]);
    // }
    
    // //test readData
    // for (i = 0; i < NUMBER_PROFS; i++)
    // {
    //     printf("{");
    //     for (j = 0; j < NUMBER_COURSES; j++)
    //     {
    //         printf("%c, ", data[i][j]);
    //     }
    //     printf("}\n");
    // }
    

    return 0;
}

void readCourseProfData(char filename [50], char courseNames[NUMBER_COURSES][50], char profNames[NUMBER_PROFS][30], int courseID[NUMBER_COURSES]) {
    int i;
    FILE* inFile = NULL;

    inFile = fopen(filename, "r");
    if(inFile == NULL){
        printf("Could not open file %s\n", filename);
    }

    //loop to read course names
    for (i = 0; i < NUMBER_COURSES; i++)
    {
        fgets(courseNames[i], 50, inFile);

        //eliminate end-of-line char
        if(courseNames[i][strlen(courseNames[i]) - 1] == '\n'){
            courseNames[i][strlen(courseNames[i]) - 1] = '\0';
        }
    }
    //loop to read prof names
    for (i = 0; i < NUMBER_PROFS; i++)
    {
        fgets(profNames[i], 30, inFile);

        //eliminate end-of-line char
        if(profNames[i][strlen(profNames[i]) - 1] == '\n'){
            profNames[i][strlen(profNames[i]) - 1] = '\0';
        }
    }
    //loop to read courseID's
    for (i = 0; i < NUMBER_COURSES; i++)
    {
        fscanf(inFile, "%d", &courseID[i]);
    }   

    fclose(inFile); 
}

void readData(char filename[50], char data[NUMBER_PROFS][NUMBER_COURSES]){
    int i;
    int j;
    char strin[NUMBER_PROFS][NUMBER_COURSES];

    FILE* inFile = NULL;

    inFile = fopen(filename, "r");
    if(inFile == NULL){
        printf("Could not open file %s\n", filename);
    }

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        fscanf(inFile, "%s", strin[i]);
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            data[i][j] = strin[i][j];
        }        
    }

    fclose(inFile);
}
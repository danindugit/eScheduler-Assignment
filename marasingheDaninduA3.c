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

/******
 readCourseProfData: reads data from courses.txt
 In: variables for name of file, course names, prof names, and course ID's
 Out: None
 Post: Scans data from courses.txt and assigns corresponding values to arrays
*******/
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

/******
 readData: reads data from data.txt
 In: variables for name of file, data 2d array
 Out: None
 Post: Scans data from data.txt and assigns corresponding values to indices of data array
*******/
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
            data[i][j] = tolower(strin[i][j]);
        }        
    }
}

/******
 numProfsTeachingNCourses: counts number of profs teaching n courses
 In: variables for data 2d array, number of courses, prof names, 
 Out: int for number of profs teaching n courses
 Post: Prints professors that teach n courses and number of those profs
*******/
int numProfsTeachingNCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char profNames[NUMBER_PROFS][30]){
    int i;
    int j;
    int counterProfs, counterCourses;
    counterProfs = 0;

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        counterCourses = 0;
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            if(data[i][j] == 'y'){
                counterCourses++;
            }
        }
        if(counterCourses >= n){
            counterProfs++;
            printf("Professor %s teaches %d or more courses a year\n", profNames[i], n);
        }        
    }
    
    printf("\nNumber of profs teaching more than n courses = %d\n", counterProfs);

    return counterProfs;
}

/******
 numProfsTeachingNLevelCourses: counts number of profs teaching n-level courses only
 In: variables for data 2d array, level of courses, course ids, prof names 
 Out: int for number of profs teaching n-level courses
 Post: Prints professors that teach n-level courses and number of those profs
*******/
int numProfsTeachingNLevelCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, int courseID[NUMBER_COURSES], char profNames[NUMBER_PROFS][30]){
    int counter;
    int i;
    int j;
    int isTeaching[NUMBER_PROFS];
    int isTeachingAny[NUMBER_PROFS];

    counter = 0;

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            if(data[i][j] == 'y')
            {
                if(courseID[j] / 1000 != n){
                    isTeaching[i] = 0;
                    break;
                }
            }
            isTeaching[i] = 1;
        }    
        //loop again to check if the prof is teaching no courses
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            if(data[i][j] == 'y'){
                isTeachingAny[i] = 1;
                break;
            }
            isTeachingAny[i] = 0;
        }
        
        if(isTeaching[i] == 1 && isTeachingAny[i] == 1){
            counter++;
            printf("Professor %s teaches only %d000 level courses\n", profNames[i], n);
        }    
    }

    printf("Number of profs teaching n-level courses = %d\n", counter);

    return counter;
}

/******
 coursesWithNProfs: counts courses with n profs
 In: variables for data 2d array, n, course names 
 Out: int for number of courses with n profs
 Post: Prints courses that have n profs and number of those courses
*******/
int coursesWithNProfs(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char courseNames[NUMBER_COURSES][50]){
    int i;
    int j;
    int numProfs[NUMBER_COURSES];
    int numCourses;

    numCourses = 0;

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        numProfs[i] = 0;
        for (j = 0; j < NUMBER_PROFS; j++)
        {
            if(data[j][i] == 'y'){
                numProfs[i]++;
            }
        }
    }

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        if(numProfs[i] == n){
            numCourses++;
            printf("%s is taught by %d profs\n", courseNames[i], n);
        }
    }

    printf("Number of courses taught by n professors = %d\n", numCourses);
    
    return numCourses;
}

/******
 avgNumCourses: calculates avg courses per prof
 In: variables for data 2d array
 Out: float average courses per prof
*******/
float avgNumCourses(char data[NUMBER_PROFS][NUMBER_COURSES]){
    int i;
    int j;
    int numY;
    float avg;

    numY = 0;

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            if(data[i][j] == 'y'){
                numY++;
            }
        }        
    }

    avg = (float)numY/NUMBER_PROFS;
    
    return avg;    
}

/******
 getCourseName: gets course name given id
 In: variables for course id input, course ids, the name found, course names
 Out: boolean int for whether the course is found or not
*******/
int getCourseName (int courseNum, int courseID[NUMBER_COURSES], char cNameFound [50], char courseNames[NUMBER_COURSES][50]){
    int i;

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        if(courseID[i] == courseNum){
            //course found
            strcpy(cNameFound, courseNames[i]);
            return 1;
        }
    }
    //course not found
    return 0;
}

/******
 getCourseNum: gets course id given name
 In: variables for course name input, course ids, the id found, course names
 Out: boolean int for whether the course is found or not
*******/
int getCourseNum (char cName [50], int courseID[NUMBER_COURSES], int * cNumFound, char courseNames[NUMBER_COURSES][50]){
    int i;

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        if(strcmp(courseNames[i], cName) == 0){
            //course found
            *cNumFound = courseID[i];
            return 1;
        }
    }
    //course not found
    return 0;
}

/******
 generateReport: generates report of all course data
 In: variables for all necessary lists
 Out: none
 Post: prints report
*******/
void generateReport(char data[NUMBER_PROFS][NUMBER_COURSES],int courseID[NUMBER_COURSES],char courseNames[NUMBER_COURSES][50],char profNames[NUMBER_PROFS][30]){
    int i;
    int j;
    int numProfs[NUMBER_COURSES];
    char names[NUMBER_PROFS*10][30];
    int profCounter; //variable to count how many profs have been printed so far for the current course on loop

    //loop to get the the number of profs teaching each course
    for (i = 0; i < NUMBER_COURSES; i++)
    {
        numProfs[i] = 0;
        for (j = 0; j < NUMBER_PROFS; j++)
        {
            if(data[j][i] == 'y'){
                numProfs[i]++;
            }
        }        
    }
    

    printf("*************************\n");

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        printf("%d.\tCourse No: CIS%d\n", i+1, courseID[i]);
        printf("\tCourse Name: %s\n", courseNames[i]);
        printf("\n\tTaught by: ");
        if(numProfs[i] == 0){
            //if there are no profs for this course, print none
            printf("None\n\n");
            continue;
        }
        //initialize profCounter to 0
        profCounter = 0;
        //loop to print prof names teaching the course
        for (j = 0; j < NUMBER_PROFS; j++)
        {
            //otherwise, check if this prof teach the ith course and add commas and ands based on numProfs[i]
            if(data[j][i] == 'y'){
                //if this prof is teaching the course, print their name
                printf("%s", profNames[j]);
                if(profCounter == (numProfs[i] - 2)){
                //if this is the second last prof teaching the course, print and
                printf(" and ");
                }
                else if(profCounter < (numProfs[i] - 1)){
                //otherwise if this isnt the last prof teaching this course, print a comma 
                printf(", ");
                }
                profCounter++;
            }            
        }
        printf("\n\n");        
    }
    printf("*************************\n");
}
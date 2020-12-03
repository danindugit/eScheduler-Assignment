/************************marasingheDaninduA3Main.c**************
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

int main(int argc, char* argv[]){
    int i;
    int j;
    char filename1[50];  //name for courses.txt
    char filename2[50];  //name for data.txt
    //arrays for course names, prof names, course ID's, and a 2D list for all data
    char courseNames[NUMBER_COURSES][50];
    char profNames [NUMBER_PROFS][30];
    int courseID [NUMBER_COURSES];
    char data[NUMBER_PROFS][NUMBER_COURSES];

    int option;  //user's menu option
    //variables for task 3
    int numPTeachingNC;
    int numCoursesTask3;
    //variables for task 4
    int level;
    int numPTeachingNLevelC;
    //variables for task 5
    int numProfsForCourse;
    int cWithNP;
    //variables for task 7
    int id;
    char cNameFound[50];
    int foundTask7;
    //variables for task 8
    char name [30];
    int cNumFound;
    int foundTask8;

    //initialize
    option = 0;

    if(argc != 3){
        //if incorrect number of command line args
        printf("Usage: ./a.out courses.txt data.txt");
        return -1;
    }

    //get filename from 2nd command line arg and call readCourseProfData with it 
    strcpy(filename1, argv[1]);
    readCourseProfData(filename1, courseNames, profNames, courseID);
    //get filename from 3nd command line arg and call readData with it 
    strcpy(filename2, argv[2]);
    readData(filename2, data);

    do{
    //loop through these commands until user enters an exit option
    printf("***************************\n");
    printf("Enter a choice from the menu displayed below:\n");
    printf("3 for Task 3 - count and print all profs teaching n courses\n");
    printf("4 for Task 4 - count and print all profs teaching only n-level courses\n");
    printf("5 for Task 5 - count and print all courses taught by n profs\n");
    printf("6 for Task 6 - find and print the average number of courses taught by a prof this year\n");
    printf("7 for Task 7 - search for course name, given its ID\n");
    printf("8 for Task 8 - search for course ID, given its name\n");
    printf("9 for Task 9 (additional functionality) - generate a report\n");
    printf("Enter 10 to exit\n");
    //prompt for user menu option
    scanf("%d", &option);
    getchar();

    if(option == 3){
        printf("TASK 3:\n");
        //prompt for number of courses
        printf("Number of courses?\n");
        scanf("%d", &numCoursesTask3);
            
        numPTeachingNC = numProfsTeachingNCourses(data, numCoursesTask3, profNames);
    }
    else if(option == 4){
        printf("TASK 4:\n");
        //prompt for level of course
        printf("Level of Course?\n");
        scanf("%d", &level);

        numPTeachingNLevelC = numProfsTeachingNLevelCourses(data, level, courseID, profNames);
    }
    else if(option == 5){
        printf("TASK 5:\n");
        //prompt for number of profs for a course
        printf("Number of profs for a course?\n");
        scanf("%d", &numProfsForCourse);

        cWithNP = coursesWithNProfs(data, numProfsForCourse, courseNames);
    }
    else if(option == 6){
        printf("TASK 6:\n");
        //display average
        printf("Average number of courses taught by a prof = %.2f\n", avgNumCourses(data));
    }
    else if(option == 7){
        printf("TASK 7:\n");
        //prompt for id
        printf("Search for which course id?\n");
        scanf("%d", &id);

        foundTask7 = getCourseName(id, courseID, cNameFound, courseNames);

        if(foundTask7 == 1){
            //found
            printf("Course name for %d is %s\n", id, cNameFound);
        }
        else{
            //not found
            printf("Course name not found for %d\n", id);
        }
    }
    else if(option == 8){
        printf("TASK 8:\n");
        //prompt for name of course
        printf("Search for which course name?\n");
        fgets(name, 30, stdin);

        //eliminate end-of-line char
        if(name[strlen(name) - 1] == '\n'){
            name[strlen(name) - 1] = '\0';
        }

        foundTask8 = getCourseNum(name, courseID, &cNumFound, courseNames);

        if(foundTask8 == 1){
            //found
            printf("Course ID for %s is %d\n", name, cNumFound);
        }
        else{
            //not found
            printf("Course ID not found for %s\n", name);
        }
    }
    else if(option == 9){
        printf("TASK 9:\n");
        generateReport(data, courseID, courseNames, profNames);
    }
    else{
        //exit option, exit out of program
        break;
    }
    } while(option > 2 && option < 10);

}
/*
    Created by Victor Colome on 04/27/2022.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This program creates a database of students, allowing the user to
    create, read, and delete students from the database. The database is
    implemented using a linked list, with each student being a node in the list.
    The program also allows the user to read from a file to initialize the database.

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------------
typedef struct {
  char *name;
  char *id;
  double gpa;
  int creditHours;
} Student;

typedef struct StudentNode {
  Student *pStudent;
  struct StudentNode *pNext;
} StudentNode;

typedef struct {
  StudentNode *pIDList;
  StudentNode *pHonorRollList;
  StudentNode *pAcademicProbationList;
  StudentNode *pFreshmanList;
  StudentNode *pSophomoreList;
  StudentNode *pJuniorList;
  StudentNode *pSeniorList;
} Database;
//-----------------------------------------------------------------------------------
// Free memory of all students in each database
void deleteDatabase(Database *pDatabase) {
  StudentNode *pCurrent;
  StudentNode *pNext;

  pCurrent = pDatabase->pHonorRollList;
  while (pCurrent != NULL) {
    pNext = pCurrent->pNext;
    free(pCurrent);
    pCurrent = pNext;
  }

  pCurrent = pDatabase->pAcademicProbationList;
  while (pCurrent != NULL) {
    pNext = pCurrent->pNext;
    free(pCurrent);
    pCurrent = pNext;
  }

  pCurrent = pDatabase->pFreshmanList;
  while (pCurrent != NULL) {
    pNext = pCurrent->pNext;
    free(pCurrent);
    pCurrent = pNext;
  }

  pCurrent = pDatabase->pSophomoreList;
  while (pCurrent != NULL) {
    pNext = pCurrent->pNext;
    free(pCurrent);
    pCurrent = pNext;
  }

  pCurrent = pDatabase->pJuniorList;
  while (pCurrent != NULL) {
    pNext = pCurrent->pNext;
    free(pCurrent);
    pCurrent = pNext;
  }

  pCurrent = pDatabase->pSeniorList;
  while (pCurrent != NULL) {
    pNext = pCurrent->pNext;
    free(pCurrent);
    pCurrent = pNext;
  }

  pCurrent = pDatabase->pIDList;
  while (pCurrent != NULL) {
    pNext = pCurrent->pNext;
    free(pCurrent->pStudent->name);
    free(pCurrent->pStudent->id);
    free(pCurrent->pStudent);
    free(pCurrent);
    pCurrent = pNext;
  }
  // Free memory of database itself
  free(pDatabase);
}
//-----------------------------------------------------------------------------------
// Displays all students within a database
void displayList(StudentNode *pHead) {
  while (pHead != NULL) {
    printf("%s:\n", pHead->pStudent->name);
    printf("\tID - %s\n", pHead->pStudent->id);
    printf("\tGPA - %0.2f\n", pHead->pStudent->gpa);
    printf("\tCredit Hours - %d\n", pHead->pStudent->creditHours);
    pHead = pHead->pNext;
  }
}
//-----------------------------------------------------------------------------------
// Frees a student node from all databases, as well as the node itself
void freeStudent(Database *pDatabase, char *studentID) {
  // Unlink StudentNode from pIDList
  StudentNode *pCurrentDB = pDatabase->pSeniorList;
  StudentNode *pPrev = NULL;
  while (pCurrentDB != NULL) {
    if (strcmp(pCurrentDB->pStudent->id, studentID) == 0) {
      if (pPrev == NULL) {
        pDatabase->pSeniorList = pCurrentDB->pNext;
      } else {
        pPrev->pNext = pCurrentDB->pNext;
      }
      free(pCurrentDB);
      break;
    }
    pPrev = pCurrentDB;
    pCurrentDB = pCurrentDB->pNext;
  }
  // Unlink StudentNode from pHonorRollList
  pCurrentDB = pDatabase->pHonorRollList;
  pPrev = NULL;
  while (pCurrentDB != NULL) {
    if (strcmp(pCurrentDB->pStudent->id, studentID) == 0) {
      if (pPrev == NULL) {
        pDatabase->pHonorRollList = pCurrentDB->pNext;
      } else {
        pPrev->pNext = pCurrentDB->pNext;
      }
      free(pCurrentDB);
      break;
    }
    pPrev = pCurrentDB;
    pCurrentDB = pCurrentDB->pNext;
  }
  // Unlink StudentNode from pAcademicProbationList
  pCurrentDB = pDatabase->pAcademicProbationList;
  pPrev = NULL;
  while (pCurrentDB != NULL) {
    if (strcmp(pCurrentDB->pStudent->id, studentID) == 0) {
      if (pPrev == NULL) {
        pDatabase->pAcademicProbationList = pCurrentDB->pNext;
      } else {
        pPrev->pNext = pCurrentDB->pNext;
      }
      free(pCurrentDB);
      break;
    }
    pPrev = pCurrentDB;
    pCurrentDB = pCurrentDB->pNext;
  }
  // Unlink StudentNode from pFreshmanList
  pCurrentDB = pDatabase->pFreshmanList;
  pPrev = NULL;
  while (pCurrentDB != NULL) {
    if (strcmp(pCurrentDB->pStudent->id, studentID) == 0) {
      if (pPrev == NULL) {
        pDatabase->pFreshmanList = pCurrentDB->pNext;
      } else {
        pPrev->pNext = pCurrentDB->pNext;
      }
      free(pCurrentDB);
      break;
    }
    pPrev = pCurrentDB;
    pCurrentDB = pCurrentDB->pNext;
  }
  // Unlink StudentNode from pSophomoreList
  pCurrentDB = pDatabase->pSophomoreList;
  pPrev = NULL;
  while (pCurrentDB != NULL) {
    if (strcmp(pCurrentDB->pStudent->id, studentID) == 0) {
      if (pPrev == NULL) {
        pDatabase->pSophomoreList = pCurrentDB->pNext;
      } else {
        pPrev->pNext = pCurrentDB->pNext;
      }
      free(pCurrentDB);
      break;
    }
    pPrev = pCurrentDB;
    pCurrentDB = pCurrentDB->pNext;
  }
  // Unlink StudentNode from pJuniorList
  pCurrentDB = pDatabase->pJuniorList;
  pPrev = NULL;
  while (pCurrentDB != NULL) {
    if (strcmp(pCurrentDB->pStudent->id, studentID) == 0) {
      if (pPrev == NULL) {
        pDatabase->pJuniorList = pCurrentDB->pNext;
      } else {
        pPrev->pNext = pCurrentDB->pNext;
      }
      free(pCurrentDB);
      break;
    }
    pPrev = pCurrentDB;
    pCurrentDB = pCurrentDB->pNext;
  }
  // Unlink StudentNode from pSeniorList
  pCurrentDB = pDatabase->pIDList;
  pPrev = NULL;
  while (pCurrentDB != NULL) {
    if (strcmp(pCurrentDB->pStudent->id, studentID) == 0) {
      if (pPrev == NULL) {
        pDatabase->pIDList = pCurrentDB->pNext;
      } else {
        pPrev->pNext = pCurrentDB->pNext;
      }
      free(pCurrentDB->pStudent->id);
      free(pCurrentDB->pStudent->name);
      free(pCurrentDB->pStudent);
      free(pCurrentDB);
      break;
    }
    pPrev = pCurrentDB;
    pCurrentDB = pCurrentDB->pNext;
  }
}
//-----------------------------------------------------------------------------------
// Searches for student based on student ID
Student *searchList(StudentNode *pIDList, char *studentID) {
  while (pIDList != NULL) {
    if (strcmp(pIDList->pStudent->id, studentID) == 0) {
      return pIDList->pStudent;
    }
    pIDList = pIDList->pNext;
  }
  return 0;
}
//-----------------------------------------------------------------------------------
// Creates a StudentNode for an individual student
StudentNode *createStudentNode(Student *pNewStudent) {
  StudentNode *pNewStudentNode = malloc(sizeof(StudentNode));
  pNewStudentNode->pStudent = pNewStudent;
  pNewStudentNode->pNext = NULL;
  return pNewStudentNode;
}
//-----------------------------------------------------------------------------------
// Adds student to Database alphanumerically by ID
void addStudentByID(StudentNode **pDatabaseType, Student *pNewStudent) {
  StudentNode *pNewStudentNode = createStudentNode(pNewStudent);
  pNewStudentNode->pNext = NULL;
  StudentNode *pCurrent = *pDatabaseType;
  StudentNode *pPrev = NULL;

  while (pCurrent != NULL &&
         strcmp(pNewStudentNode->pStudent->id, pCurrent->pStudent->id) > 0) {
    pPrev = pCurrent;
    pCurrent = pCurrent->pNext;
  }
  if (pPrev == NULL) {
    pNewStudentNode->pNext = *pDatabaseType;
    *pDatabaseType = pNewStudentNode;
  } else {
    pNewStudentNode->pNext = pCurrent;
    pPrev->pNext = pNewStudentNode;
  }
}
//-----------------------------------------------------------------------------------
// Adds student to Database in ascending order by GPA
void addStudentByGPA(StudentNode **pDatabaseType, Student *pNewStudent) {
  StudentNode *pNewStudentNode = createStudentNode(pNewStudent);
  pNewStudentNode->pNext = NULL;
  StudentNode *pCurrent = *pDatabaseType;
  StudentNode *pPrev = NULL;

  while (pCurrent != NULL &&
         pNewStudentNode->pStudent->gpa > pCurrent->pStudent->gpa) {
    pPrev = pCurrent;
    pCurrent = pCurrent->pNext;
  }

  if (pPrev == NULL) {
    pNewStudentNode->pNext = *pDatabaseType;
    *pDatabaseType = pNewStudentNode;
  } else {
    pNewStudentNode->pNext = pCurrent;
    pPrev->pNext = pNewStudentNode;
  }
}
//-----------------------------------------------------------------------------------
// Adds student to Database in ascending order by name
void addStudentByName(StudentNode **pDatabaseType, Student *pNewStudent) {
  StudentNode *pNewStudentNode = createStudentNode(pNewStudent);
  pNewStudentNode->pNext = NULL;
  StudentNode *pCurrent = *pDatabaseType;
  StudentNode *pPrev = NULL;

  while (pCurrent != NULL && strcmp(pNewStudentNode->pStudent->name,
  pCurrent->pStudent->name) > 0) {
    pPrev = pCurrent;
    pCurrent = pCurrent->pNext;
  }

  if (pPrev == NULL) {
    pNewStudentNode->pNext = *pDatabaseType;
    *pDatabaseType = pNewStudentNode;
  } else {
    pNewStudentNode->pNext = pCurrent;
    pPrev->pNext = pNewStudentNode;
  }
}
//-----------------------------------------------------------------------------------
// Adds student to their proper databases depending on Student data
void addStudentToDatabase(Database *pDatabase, Student *pNewStudent) {
  addStudentByID(&pDatabase->pIDList, pNewStudent);
  if (pNewStudent->gpa >= 3.5) {
    addStudentByGPA(&pDatabase->pHonorRollList, pNewStudent);
  }
  if (pNewStudent->gpa < 2.0) {
    addStudentByGPA(&pDatabase->pAcademicProbationList, pNewStudent);
  }
  if ((pNewStudent->creditHours >= 0) && (pNewStudent->creditHours < 30)) {
    addStudentByName(&pDatabase->pFreshmanList, pNewStudent);
  }
  if ((pNewStudent->creditHours >= 30) && (pNewStudent->creditHours < 60)) {
    addStudentByName(&pDatabase->pSophomoreList, pNewStudent);
  }
  if ((pNewStudent->creditHours >= 60) && (pNewStudent->creditHours < 90)) {
    addStudentByName(&pDatabase->pJuniorList, pNewStudent);
  }
  if (pNewStudent->creditHours >= 90) {
    addStudentByName(&pDatabase->pSeniorList, pNewStudent);
  }
}
//-----------------------------------------------------------------------------------
// Reads in user file and initializes database with file data
Database initDatabase(Database *pDatabase, char filename[81]) {

  FILE *filePtr =
      fopen(filename, "r"); // "r" means we open the file for reading
  // Check that the file was able to be opened
  if (filePtr == NULL) {
    printf("Error: could not open %s for reading\n", filename);
    exit(-1);
  }
  // Read each word from file, and print them one by one
  char studentName[81];
  char studentID[81];
  double studentGPA;
  int studentCreditHrs;

  // skip first line of file
  char line[100];
  fgets(line, sizeof(line), filePtr);
  printf("\n");

  char inputString[81];
  char *token;
  const char s[2] = ",";
  Student *pNewStudent;
  StudentNode *pHead = NULL;
  StudentNode *pNewStudentNode = NULL;
  StudentNode *pTempStudentNode = NULL;

  // Split file by "," delimiter, assign values to respective fields in Student
  // struct
  while (fgets(inputString, sizeof(inputString), filePtr)) {
    pNewStudent = malloc(sizeof(Student));

    token = strtok(inputString, s); // Read in name
    strcpy(studentName, token);
    pNewStudent->name = malloc(strlen(studentName) + 1);
    strcpy(pNewStudent->name, studentName);

    token = strtok(NULL, s); // Read in ID
    strcpy(studentID, token);
    pNewStudent->id = malloc(strlen(studentID) + 1);
    strcpy(pNewStudent->id, studentID);

    token = strtok(NULL, s); // Read in GPA
    studentGPA = atof(token);
    pNewStudent->gpa = studentGPA;

    token = strtok(NULL, s); // Read in credit hours
    studentCreditHrs = atoi(token);
    pNewStudent->creditHours = studentCreditHrs;

    addStudentToDatabase(pDatabase, pNewStudent);
  }

  printf("\n");
  // Close the file
  fclose(filePtr);

  return *pDatabase;
}
//-----------------------------------------------------------------------------------
// Creates a new student based on input data and adds it to the database
void createStudent(Database *pDatabase) {
  char studentName[81];
  char studentID[81];
  double studentGPA;
  int studentCreditHrs;
  Student *pNewStudent;
  pNewStudent = malloc(sizeof(Student));

  printf("Enter the name of the new student: ");
  fgets(studentName, 81, stdin);
  studentName[strcspn(studentName, "\n")] = '\0';
  pNewStudent->name = malloc(strlen(studentName) + 1);
  strcpy(pNewStudent->name, studentName);

  printf("Enter the ID of the new student: ");
  scanf("%s", studentID);
  studentID[strcspn(studentID, "\n")] = '\0';
  pNewStudent->id = malloc(strlen(studentID) + 1);
  strcpy(pNewStudent->id, studentID);

  printf("Enter the GPA of the new student: ");
  scanf("%lf", &studentGPA);
  pNewStudent->gpa = studentGPA;

  printf("Enter the credit hours of the new student: ");
  scanf("%d", &studentCreditHrs);
  pNewStudent->creditHours = studentCreditHrs;

  addStudentToDatabase(pDatabase, pNewStudent);
  Student *foundStudent = searchList(pDatabase->pIDList, studentID);
  if (foundStudent == 0) {
    printf("Student creation unsuccessful %s.\n", studentID);
  } else {
    printf("Successfully added the following student to the database!\n");
    printf("%s:\n", foundStudent->name);
    printf("\tID - %s\n", foundStudent->id);
    printf("\tGPA - %0.2f\n", foundStudent->gpa);
    printf("\tCredit Hours - %d", foundStudent->creditHours);
  }
  printf("\n\n");
}
//-----------------------------------------------------------------------------------
// Provides user with options for displaying information from database
void readDatabase(Database *pDatabase) {
  printf("\nSelect one of the following: \n");
  printf("\t1) Display the head (first 10 rows) of the database\n");
  printf("\t2) Display students on the honor roll, in order of their GPA\n");
  printf(
      "\t3) Display students on academic probation, in order of their GPA\n");
  printf("\t4) Display freshmen students, in order of their name\n");
  printf("\t5) Display sophomore students, in order of their name\n");
  printf("\t6) Display junior students, in order of their name\n");
  printf("\t7) Display senior students, in order of their name\n");
  printf("\t8) Display the information of a particular student\n");
  int readChoice;
  bool isValid = false;

  while (isValid == false) {
    printf("Your choice --> ");
    scanf("%d", &readChoice);
    if ((readChoice != 1) && (readChoice != 2) && (readChoice != 3) &&
        (readChoice != 4) && (readChoice != 5) && (readChoice != 6) &&
        (readChoice != 7) && (readChoice != 8)) {
      printf("Sorry, that input was invalid. Please try again.\n");
    } else {
      isValid = true;
    }
  }
  switch (readChoice) {
  case 1:
    if (pDatabase->pIDList == NULL) {
      printf("There are no students matching that criteria.\n\n");
    } else {
      int i = 0;
      StudentNode *pCurrent = pDatabase->pIDList;
      while (i < 10 && pCurrent != NULL) {
        printf("%s:\n", pCurrent->pStudent->name);
        printf("\t\tID - %s\n", pCurrent->pStudent->id);
        printf("\t\tGPA - %0.2f\n", pCurrent->pStudent->gpa);
        printf("\t\tCredit Hours - %d\n", pCurrent->pStudent->creditHours);
        pCurrent = pCurrent->pNext;
        i++;
      }
    }
    break;
  case 2:
    if (pDatabase->pHonorRollList == NULL) {
      printf("There are no students matching that criteria.\n\n");
    } else {
      displayList(pDatabase->pHonorRollList);
    }
    break;
  case 3:
    if (pDatabase->pAcademicProbationList == NULL) {
      printf("There are no students matching that criteria.\n\n");
    } else {
      displayList(pDatabase->pAcademicProbationList);
    }
    break;
  case 4:
    if (pDatabase->pFreshmanList == NULL) {
      printf("There are no students matching that criteria.\n\n");
    } else {
      displayList(pDatabase->pFreshmanList);
    }
    break;
  case 5:
    if (pDatabase->pSophomoreList == NULL) {
      printf("There are no students matching that criteria.\n\n");
    } else {
      displayList(pDatabase->pSophomoreList);
    }
    break;
  case 6:
    if (pDatabase->pJuniorList == NULL) {
      printf("There are no students matching that criteria.\n\n");
    } else {
      displayList(pDatabase->pJuniorList);
    }
    break;
  case 7:
    if (pDatabase->pSeniorList == NULL) {
      printf("There are no students matching that criteria.\n\n");
    } else {
      displayList(pDatabase->pSeniorList);
    }
    break;
  case 8:
    printf("Enter the id of the student to find: ");
    char studentID[81];
    bool foundID = false;
    scanf(" %s", studentID);
    while (getchar() != '\n');
    Student *foundStudent = searchList(pDatabase->pIDList, studentID);
    if (foundStudent == 0) {
      printf("Sorry, there is no student in the database with the id %s.\n",
             studentID);
    } else {
      printf("%s:\n", foundStudent->name);
      printf("\t\tID - %s\n", foundStudent->id);
      printf("\t\tGPA - %0.2f\n", foundStudent->gpa);
      printf("\t\tCredit Hours - %d\n", foundStudent->creditHours);
    }
    break;
  }
  printf("\n\n");
}

// Function to export the list of students to a CSV file
void writeDatabaseList(StudentNode *pList, const char *listName) {
    if (pList == NULL) {
        printf("The %s list is empty.\n", listName);
        return;
    }

    char fileName[256];
    printf("Enter the name for the CSV file (without extension): ");
    scanf("%255s", fileName);
    strcat(fileName, ".csv");

    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Name,ID,GPA,Credit Hours\n");

    StudentNode *current = pList;
    while (current != NULL) {
        fprintf(file, "%s,%s,%.2f,%d\n",
                current->pStudent->name,
                current->pStudent->id,
                current->pStudent->gpa,
                current->pStudent->creditHours);
        current = current->pNext;
    }

    fclose(file);
    printf("The %s list has been exported to %s\n", listName, fileName);
}

void exportDatabase(Database *pDatabase) {
    int choice;
    printf("\nChoose a list to export:\n");
    printf("1. ID List\n");
    printf("2. Honor Roll List\n");
    printf("3. Academic Probation List\n");
    printf("4. Freshman List\n");
    printf("5. Sophomore List\n");
    printf("6. Junior List\n");
    printf("7. Senior List\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            writeDatabaseList(pDatabase->pIDList, "ID");
            break;
        case 2:
            writeDatabaseList(pDatabase->pHonorRollList, "Honor Roll");
            break;
        case 3:
            writeDatabaseList(pDatabase->pAcademicProbationList, "Academic Probation");
            break;
        case 4:
            writeDatabaseList(pDatabase->pFreshmanList, "Freshman");
            break;
        case 5:
            writeDatabaseList(pDatabase->pSophomoreList, "Sophomore");
            break;
        case 6:
            writeDatabaseList(pDatabase->pJuniorList, "Junior");
            break;
        case 7:
            writeDatabaseList(pDatabase->pSeniorList, "Senior");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}
//-----------------------------------------------------------------------------------
// Searches for a student based on ID number inputted by user and deletes that
// StudentNode from the database
void deleteStudent(Database *pDatabase) {
  printf("Enter the id of the student to be removed: ");
  char studentID[81];
  scanf(" %s", studentID);
  while (getchar() != '\n')
    ;
  Student *foundStudent = searchList(pDatabase->pIDList, studentID);
  if (foundStudent == 0) {
    printf("Sorry, there is no student in the database with the id %s.",
           studentID);
  } else {
    freeStudent(pDatabase, studentID);
  }
  printf("Successfully deleted the student from the database!\n");
  printf("\n\n");
}
//-----------------------------------------------------------------------------------
// Provides menu options for various actions related to the studen database
void mainMenu(Database *pDatabase) {
  char menuChoice;
  bool isValid = false;

  while (isValid == false) {
    printf(
        "\nEnter: \t\tC to create a new student and add them to the database,\n");
    printf("\t\tR to read from the database,\n");
    printf("\t\tE to export a list from the database,\n");
    printf("\t\tD to delete a student from the database, or\n");
    printf("\t\tX to exit the program.\n");
    printf("Your choice --> ");
    scanf(" %c", &menuChoice);
    while (getchar() != '\n')
      ;
    if ((menuChoice != 'C') && (menuChoice != 'R') && (menuChoice != 'E') &&(menuChoice != 'D') &&
        (menuChoice != 'X')) {
      printf("Invalid option. Try again.\n\n");
    } else {
      isValid = true;
    }
  }
  switch (menuChoice) {
  case 'C':
    createStudent(pDatabase);
    mainMenu(pDatabase);
    break;
  case 'R':
    readDatabase(pDatabase);
    mainMenu(pDatabase);
    break;
  case 'E':
  exportDatabase(pDatabase);
  mainMenu(pDatabase);
  break;
  case 'D':
    deleteStudent(pDatabase);
    mainMenu(pDatabase);
    break;
  case 'X':
    deleteDatabase(pDatabase);
    printf("Exiting...\n");
    exit(0);
    break;
  }
}
//-----------------------------------------------------------------------------------
// Provides options for how to proceed with database (empty or initialized)
void programStart(Database *pDatabase) {
  printf("\nWelcome to the Student Database!\n");

  printf("Enter E to start with an empty database, \n");
  printf("or F to start with a database that has information on students from "
         "a file.\n");

  char startChoice;
  bool isValid = false;

  while (isValid == false) {
    printf("Your choice --> ");
    scanf(" %c", &startChoice);
    while (getchar() != '\n')
      ;
    if ((startChoice != 'E') && (startChoice != 'F')) {
      printf("Sorry, that input was invalid. Please try again.\n");
    } else {
      isValid = true;
    }
  }
  switch (startChoice) {
  case 'E':
    mainMenu(pDatabase);
    break;
  case 'F':
    printf("Enter the name of the file you would like to use: ");
    char filename[81];
    scanf("%s", filename);
    initDatabase(pDatabase, filename);
    mainMenu(pDatabase);
    break;
  }
}
//-----------------------------------------------------------------------------------
int main() {
  Database *pDatabase = malloc(sizeof(Database));
  pDatabase->pIDList = NULL;
  pDatabase->pHonorRollList = NULL;
  pDatabase->pAcademicProbationList = NULL;
  pDatabase->pFreshmanList = NULL;
  pDatabase->pSophomoreList = NULL;
  pDatabase->pJuniorList = NULL;
  pDatabase->pSeniorList = NULL;
  programStart(pDatabase);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_EMAIL_LEN = 50;
int INITIAL_STUDENTS = 10;
int RETAINED_STUDENTS = 6;

char** allocateEmails(int numStudents);
void readEmails(char** emails, int numStudents);
void displayEmails(char** emails, int numStudents);
char** resizeEmails(char** emails, int oldSize, int newSize);
void freeEmails(char** emails, int numStudents);

int main() {
    int numStudents = INITIAL_STUDENTS;

    char** emails = allocateEmails(numStudents);

    printf("Enter email addresses for %d students (Max 49 characters each):\n", numStudents);
    readEmails(emails, numStudents);

    printf("\nStored Email Addresses:\n");
    displayEmails(emails, numStudents);

    printf("\nReducing the list to only %d students...\n", RETAINED_STUDENTS);
    emails = resizeEmails(emails, numStudents, RETAINED_STUDENTS);
    numStudents = RETAINED_STUDENTS;

    printf("\nUpdated Email Addresses:\n");
    displayEmails(emails, numStudents);

    freeEmails(emails, numStudents);

    return 0;
}

char** allocateEmails(int numStudents) {
    char** emails = (char**)malloc(numStudents * sizeof(char*));
    if (emails == NULL) {
        perror("Failed to allocate memory for email pointers");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numStudents; i++) {
        emails[i] = (char*)malloc(MAX_EMAIL_LEN * sizeof(char));
        if (emails[i] == NULL) {
            perror("Failed to allocate memory for email string");
            exit(EXIT_FAILURE);
        }
    }

    return emails;
}

void readEmails(char** emails, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: ", i + 1);
        fgets(emails[i], MAX_EMAIL_LEN, stdin);
        
        // Remove newline character if present
        size_t len = strlen(emails[i]);
        if (emails[i][len - 1] == '\n') {
            emails[i][len - 1] = '\0';
        }
    }
}

void displayEmails(char** emails, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: %s\n", i + 1, emails[i]);
    }
}

char** resizeEmails(char** emails, int oldSize, int newSize) {
    if (newSize > oldSize) {
        fprintf(stderr, "New size must be less than or equal to old size.\n");
        return emails;
    }

    for (int i = newSize; i < oldSize; i++) {
        free(emails[i]);
    }

    char** resized = (char**)realloc(emails, newSize * sizeof(char*));
    if (resized == NULL) {
        perror("Failed to reallocate memory for resized email array");
        // Since emails still points to valid memory, we return it
        return emails;
    }

    return resized;
}

void freeEmails(char** emails, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        free(emails[i]);
    }
    free(emails);
}

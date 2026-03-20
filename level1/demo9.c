/*Write a modular C program to perform the following tasks using file handling functions:
i.	Read the details of n students from the user and store them in an array of structures.
ii.	Write the array of structures to a text (ASCII) file using fprintf().
iii.	Read the data back from the ASCII file into a second array using fscanf() and display it.
iv.	Display the array of structures.
Function prototype:
void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, constchar *filename);
int readFromTextFile(Student students[], constchar *filename);
void printStudents(Student students[], int n);*/
#include <stdio.h>
typedef struct 
{
    int id;
    char name[50];
    float marks;
} Student;
void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

int main() 
{
    int n, count;
    char filename[] = "students.txt";
    printf("Enter number of students: ");
    scanf("%d", &n);
    Student students1[100], students2[100];
    inputStudents(students1, n);
    writeToTextFile(students1, n, filename);
    count = readFromTextFile(students2, filename);
    printf("\nData read from file:\n");
    printStudents(students2, count);
    return 0;
}
void inputStudents(Student students[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter details of student %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}
void writeToTextFile(Student students[], int n, const char *filename) 
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++) 
    {
        fprintf(fp, "%d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].marks);
    }

    fclose(fp);
    printf("\nData written to file successfully.\n");
}
int readFromTextFile(Student students[], const char *filename) 
{
    FILE *fp = fopen(filename, "r");
    int i = 0;

    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return 0;
    }

    while (fscanf(fp, "%d %s %f",
                  &students[i].id,
                  students[i].name,
                  &students[i].marks) != EOF) 
    {
        i++;
    }

    fclose(fp);
    return i; 
}
void printStudents(Student students[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

/*Write a modular C program to perform the following tasks using file handling functions:
i.	Read the details of n students from the user and store them in an array of structures
ii.	Write the array of structures to a binary file using fwrite().
iii.	Read the binary file into a second array of structures using fread().
iv.	Display the array of structures.
Function prototype:
void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, constchar *filename);
int readFromBinaryFile(Student students[], constchar *filename);
void printStudents(Student students[], int n);*/
#include <stdio.h>
typedef struct 
{
    int id;
    char name[50];
    float marks;
} Student;
void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

int main() 
{
    int n, count;
    char filename[] = "students.dat";
    Student students1[100], students2[100];
    printf("Enter number of students: ");
    scanf("%d", &n);
    inputStudents(students1, n);
    writeToBinaryFile(students1, n, filename);
    count = readFromBinaryFile(students2, filename);
    printf("\nData read from binary file:\n");
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
void writeToBinaryFile(Student students[], int n, const char *filename) 
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }
    fwrite(students, sizeof(Student), n, fp);
    fclose(fp);
    printf("\nData written to binary file successfully.\n");
}
int readFromBinaryFile(Student students[], const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return 0;
    }
    int count = fread(students, sizeof(Student), 100, fp);
    fclose(fp);
    return count;  
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
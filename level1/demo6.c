/*Develop a modular C program to manage an integer array using dynamic memory allocation. You must implement specific functions to allocate, initialize, display, and safely deallocate memory. This task ensures proficiency in preventing memory leaks and managing dangling pointers.
Function prototype:
int* create_array(int n);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);*/

#include <stdio.h>
#include <stdlib.h>

int* create_array(int n);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);

int main() 
{
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = create_array(n);
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    initialize_array(arr, n);
    printf("Array elements are:\n");
    print_array(arr, n);
    delete_array(&arr);
    if (arr == NULL) {
        printf("Memory successfully deallocated. Pointer is NULL.\n");
    }

    return 0;
}
int* create_array(int n) 
{
    int *arr;
    arr = (int*)malloc(n * sizeof(int));
    return arr;
}
void initialize_array(int *arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void print_array(int *arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void delete_array(int **arr) 
{
    if (*arr != NULL) 
    {
        free(*arr);     
        *arr = NULL;   
    }
}


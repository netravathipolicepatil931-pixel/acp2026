#include <stdio.h>

typedef struct 
{
    float length;
    float width;
    float area;
} Rectangle;


void input(int n, Rectangle rects[n]);
void calculate_area(int n, Rectangle rects[n]);
int findLargestArea(int n, Rectangle rects[n]);
void output(int largestIndex, Rectangle rects[]);

int main()
{
    int n, largestIndex;

    printf("Enter the number of rectangles: ");
    scanf("%d", &n);

    Rectangle rects[n];

    input(n, rects);
    calculate_area(n, rects);
    largestIndex = findLargestArea(n, rects);
    output(largestIndex, rects);

    return 0;
}


void input(int n, Rectangle rects[n])
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter length and width of rectangle %d: ", i + 1);
        scanf("%f %f", &rects[i].length, &rects[i].width);
    }
}

void calculate_area(int n, Rectangle rects[n])
{
    for(int i = 0; i < n; i++)
    {
        rects[i].area = rects[i].length * rects[i].width;
    }
}


int findLargestArea(int n, Rectangle rects[n])
{
    int largestIndex = 0;

    for(int i = 1; i < n; i++)
    {
        if(rects[i].area > rects[largestIndex].area)
        {
            largestIndex = i;
        }
    }

    return largestIndex;
}


void output(int largestIndex, Rectangle rects[])
{
    printf("\nRectangle with the largest area:\n");
    printf("Length = %.2f\n", rects[largestIndex].length);
    printf("Width = %.2f\n", rects[largestIndex].width);
    printf("Area = %.2f\n", rects[largestIndex].area);
}
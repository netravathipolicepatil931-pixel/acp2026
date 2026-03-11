#include <stdio.h>
#include <string.h>

typedef struct 
{
    int flight_number;
    char destination[50];
    int available_seats;
} Flight_t;
void readFlights(int n, Flight_t f[]);
void searchByDestination(int n, Flight_t f[], char searchDest[]);

int main() 
{
    int n = 4;
    Flight_t flights[4];
    char searchDest[50];

    readFlights(n, flights);

    printf("\nEnter destination to search: ");
    scanf("%s", searchDest);

    searchByDestination(n, flights, searchDest);

    return 0;
}

void readFlights(int n, Flight_t f[]) 
{
    int i;

    printf("Enter details of %d flights:\n", n);
    for (i = 0; i < n; i++) 
    {
        printf("\nFlight %d\n", i + 1);

        printf("Enter flight number: ");
        scanf("%d", &f[i].flight_number);

        printf("Enter destination: ");
        scanf("%s", f[i].destination);

        printf("Enter available seats: ");
        scanf("%d", &f[i].available_seats);
    }
}


void searchByDestination(int n, Flight_t f[], char searchDest[]) 
{
    int i, found = 0;

    for (i = 0; i < n; i++) 
    {
        if (strcmp(f[i].destination, searchDest) == 0) 
        {
            printf("\nFlight available to %s\n", searchDest);
            printf("Flight Number: %d\n", f[i].flight_number);
            printf("Available Seats: %d\n", f[i].available_seats);
            found = 1;
        }
    }

    if (!found) 
    {
        printf("\nNo flight available to %s\n", searchDest);
    }
}
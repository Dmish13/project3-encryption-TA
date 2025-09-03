// Daniel Misherky
// U93099650
// This program tries to identify the TA that is not assigned
// given a list of TAs that are already assigned.
#include <stdio.h>
#include <malloc.h>

int main()
{
    int num, not_assigned; // num is for the number of TAs, not_assigned refers to TA that is not assigned
    printf("Enter number of TAs:");
    scanf("%d", &num); // user inputs number of TAs
    int *assigned = malloc(num*sizeof(int)); // initializes an array of TAs assigned
    int *counts = malloc(num*sizeof(int)); // initializes an array for the set of all TAs
    printf("Enter TAs already assigned:");
    for(int i = 0; i<num-1; i++) // makes sure there is one less TA than total needed
    {
        scanf("%d",&assigned[i]); // user inputs all TAs assigned
    }
    for(int i = 1; i<=num; i++) // for loop used to add values of 1 to num into array counts
    {
        counts[i-1] = i; // i-1 is used since index is always one less than real position
        for(int j = 0; j<num; j++) // inner for loop used to check value in counts to every value in assigned
        {
            if(counts[i-1] == assigned[j])
            {
                counts[i-1] = 0; // sets number in counts to 0 if there is a number in assigned that number in counts is equal to
            }
        }
    }
    for(int i = 0; i<num; i++) // goes through counts again
    {
        if(counts[i]!=0) // checks if number in counts is not equal to zero
        {
            not_assigned = counts[i]; // not_assigned becomes set to that counts number if it is because it means that there was no match in the array assigned
        }
    }

    printf("TA has not been assigned: %d", not_assigned); // displays the TA that has not been assigned
    printf("\n"); // adds a new line at the end of the program

    return 0;
}
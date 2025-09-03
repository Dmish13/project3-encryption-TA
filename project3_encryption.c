// Daniel Misherky
// U93099650
// This program takes a number given by the user and encrypts it
// using the index of the matching number in an encrytion
// array also given by the user.
#include <stdio.h>
#include <malloc.h>
void encrypt(int digits[], int encrypted[],  int n, int encryption_array[]); // initializes the encrypt function
int main()
{
    int num_digits, num1; // num_digits for number of digits the number is, num1 for the number user inputs
    printf("Enter the number of digits:");
    scanf("%d", &num_digits); // user inputs number of digits
    int *num= malloc(num_digits*sizeof(int)); // initializes an array of digits given the number of digits

    if (!num) {
        printf("Allocation failed!\n");
        return 1;
    }


    printf("Enter the number:");
    scanf("%d", &num1); // user inputs number that is being encrypted
    for(int i = num_digits-1; i>=0 && num1>0; i--) // for loop going in reverse order
    {
        num[i] = num1%10; // adds the last digit of num first since that is what getting the remainder after dividing by 10 does
        num1 /= 10; // divides num by 10 so the next iteration gets the digit before the last digit
    }
    
    int encryption[10]; // initilzes the encryption array user will be giving

    printf("Enter the encryption array:");
    for(int i = 0; i<10; i++)
    {
        if (scanf("%d", &encryption[i]) != 1) {
            printf("Invalid input for encryption array.\n");
            exit(1);
        } // adds the numbers user gives into encryption array
    }

    int *encrypted = malloc(num_digits*sizeof(int)); // initializes the array for digits of the new encrypted number

    if (!encrypted) {
        printf("Allocation failed!\n");
        free(num);
        return 1;
    }

    encrypt(num, encrypted, num_digits, encryption); // calls the function encrypt

    free(num);
    free(encrypted);

    return 0;


}
void encrypt(int digits[], int encrypted[], int n, int encryption_array[]) // takes an array of digits of a number, an array for the digits of the encrypted number, the length of the array of digits, and the encryption array used
{
    for(int i = 0; i<n; i++) // for loop goes through the length of array digits
    {
        for(int j = 0; j<10; j++) // inner for loop goes through the length of encryption array
        {
            if(digits[i] == encryption_array[j]) // checks the digit in digits to every digit in encryption_array
            {
                encrypted[i] = j; // if they are equal the index of the encryption array becomes the value of the new encrypted number
            }
        }
    }
    printf("Encrypted Number: ");
    for(int i = 0; i<n; i++) // for loop goes through the length of the encrypted number
    {
        printf("%d", encrypted[i]); // displays encrypted number
    }
}
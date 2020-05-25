// 1. Prompt user to input a key (an int) as argv[1]
// 2. Prompt user for plaintext
// 3. Program converts plaintext to cipher using converted argv[1]

// #include <cs50.h>
// #include <cs50.c>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare function prototype
void caesar(int ninit);

int main(int argc, char *argv[])
{
    
    // If argc is not equal to 2 or the strtol converts the key and returns 0
    if (argc != 2)
    {
        // %li is placeholder for a long integer
        puts("./caesar key");
        {
            // Exit program if no key is provided
            exit(0);
        }
    }
    // This code will only run if argc == 2
    else
    {
        // Convert string to long with strtol
	// Assign this value to the key
        // str to long(string, endpointer, base 
	// 10 is decimal base system
        long key = strtol(argv[1], NULL, 10);
	    if (key != 0)
	    {
            caesar(key);
	    }
        else
        {
            puts("./caesar key");
            {
                // Exit program if key is not a number
                exit(0);
            }
        }
    }
}
    
// n is equal to the key
void caesar(int ninit)
{

    // Declare variable which will be modulo of n (thus preventing any number above 26 from return an ASCII character larger than 122)
    int n;

    // Perform check on value of ninit. If ninit is greater than 26, return the modulo
    n = ninit % 26;

    // Declare array of chars (string) with max length 100. This array of chars will be used to store the user input
    char s[100];
    
    // Prompt User for input
    printf("plaintext:  ");    
    fgets(s, sizeof(s), stdin);

    // Declare length of string to give count for loop
    int len = strlen(s);
    // printf("Length of string is: %d\n", len);

    // Print answer (which will be created by the loop)
    printf("ciphertext: ");

    // Loop efficiently by declaring n before the second parameter
    for (int i = 0; i < len; i++)
    {
        // Is the ith character of s a lowercase character?
        // Lowercase letters in ASCII are between 97 and 122
        if (s[i] >= 'a' && s[i] <= 'z' && s[i] + n < 123)
        {
            // If it is lowercase, print out the ith character but minus 32 from it
            // This is because the uppercase is 32 digits lower
            printf("%c", s[i] + n);
        }
        // If lowercare and bigger then 122
        if (s[i] >= 'a' && s[i] <= 'z' && s[i] + n > 122)
        {
            // If it is lowercase, print out the ith character but minus 32 from it
            // This is because the uppercase is 32 digits lower
            printf("%c", s[i] + n - 26);
        }
        if (s[i] >= 'A' && s[i] <= 'Z' && s[i] + n < 91) 
        {
            printf("%c", s[i] + n);
        }
        if (s[i] >= 'A' && s[i] <= 'Z' && s[i] + n > 90) 
        {
            printf("%c", s[i] + n - 26);
        }
        // If space, don't add key, and return a space
        if (s[i] == ' ' | s[i] == ',')
        {
            printf("%c", s[i]);
        }
        else
        {
            // Skip if char is not a letter or a space
        }
    }
    // After printing the result of the loop (i.e. the ciphertext), print a newline
    printf("\n");

}


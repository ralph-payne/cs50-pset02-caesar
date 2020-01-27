/* ----- CAESAR -----

--- Remaining Tasks ---
Check to see if argv is an integer. If is integer, run the program caesar. if it is not, exit. Currently, because the program does not have this feature, it fails the [$ ./caesar HELLO] test

--- Bugs ---
Will not work if the key is greater than 26 + i [could fix this by adding another variable?] - Nice to have. Probably not necessary?

--- ASCII Information ---
Numbers 0 to 9 are ASCII values 48 (0) to 57 (9)
Uppercase A has ASCII value 65 in decimal. So for Z ,the value is 90 in decimal.
Lowercase a has ASCII value 97 in decimal. So for z ,the value is 122 in decimal.

--- TESTS ---
Test01: Passed
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP

Test02: Passed
$ ./caesar 13
plaintext:  hello, world
ciphertext: uryyb, jbeyq
Notice that neither the comma nor the space were “shifted” by the cipher. Only rotate alphabetical characters!

Test03: Passed
$ ./caesar 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar

----- VALIDATIONS -----
Test04:
$ ./caesar HELLO
Usage: ./caesar key

Test05: Passed (as there is validation to check the number of argc (argument count)
Or really doesn’t cooperate?
$ ./caesar
Usage: ./caesar key

Test06: Passed (as there is validation to check the number of argc (argument count)
Or even…
$ ./caesar 1 2 3
Usage: ./caesar key
*/

#include <cs50.h>
#include <cs50.c>
#include <stdio.h>
#include <string.h>

// Declare function prototype
void caesar(int ninit);

int main(int argc, char *argv[])
{

    // Convert string to long with strtol. Assign this value to the key
    // string to long(string, endpointer, base [10 is decimal base system])
    long key = strtol(argv[1], NULL, 10);
    printf("Output after processed with strtol %lu\n", key);
    
    // If argc is not equal to 2 or the strtol converts the key and returns 0
    if (argc != 2 || key == 0)
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
        caesar(key);
    }
    
}
    
// n is equal to the key
void caesar(int ninit)
{

    // Declare variable which will be modulo of n (thus preventing any number above 26 from return an ASCII character larger than 122)
    int n;

    // Perform a cleanup on the key. You want to remove any character that is not an uppercase or a lowercare.
    // You want to create a new array (i.e. a string)
    // You want to run a loop which scans each character
    // If the character falls in the range that is legit, you add it to a new array
    // If the character does not fall into a range that is legit, you don't add it to the array

    // Perform check on value of ninit. If ninit is greater than 26, return the modulo
    n = ninit % 26;
    printf("modulus of ninit is ");
    printf("%d\n", n);

    // Declare array of chars (string) with max length 100. This array of chars will be used to store the user input
    char s[100];
    
    // Prompt User for input
    printf("plaintext: ");    
    fgets(s, sizeof(s), stdin);

    // Declare length of string to give count for loop
    int len = strlen(s);
    printf("Length of string is: %d\n", len);

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
        // Skip if char is not a letter or a space
        else
        {
            printf("");
        }
    }
    // After printing the result of the loop (i.e. the ciphertext), print a newline
    printf("\n");

}

/* ----- Notes on C ----- *//*
int puts(const char *str) 
The C library function writes a string to stdout up to but not including the null character. A newline character is appended to the output.

------ argc and argv ------
argc refers to the number of arguments passed
argv[] is a pointer array which points to each argument passed to the program.

----- Overflow and Underflow -----
Overflow is when the absolute value of the number is too high for the computer to represent it.
Underflow is when the absolute value of the number is too close to zero for the computer to represent it.
You can get overflow with both integers and floating point numbers. You can only get underflow with floating point numbers.
To get an overflow, repeatedly multiply a number by ten. To get an underflow repeatedly divide it by ten.

----- Printing String from User -----
The gets() function can also be to take input from the user. However, it is removed from the C standard. It's because gets() allows you to input any length of characters. Hence, there might be a buffer overflow.

----- printf or puts ------
puts is simpler than printf but be aware that puts appends a newline.
If you do not want a newline, you can fputs your string to stdout or use printf
It is generally dangerous (and conceptually wrong) to pass a dynamic string as a single argument of printf
puts(mystr) and printf(mystr) will often give you the same result (except for the added newline). However, if your string contains control characters (%) there will be an issue
*/



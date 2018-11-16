/*
     Brandon West
     Assignment 1

     This program takes in an input sentence from the user and seperates it into lengths
     and inputs the lenghts into a on the screen orgainzed into boxes from 1 to 20
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function prototypes for arrays (void):
void getWords ( char sentence [ ], int wordCount [] ); // put into this a variable that will recieve the getWords
void printWords ( int wordCount[ ]);  // function printing the total arrays into table

int main ( void ) //start main
{
    // iniitalize the variables
    char inputArray [ 20000 ] = {0}; // array that is going to be sent to get the sentence strings
    int wordCount [ 20000 ] = {0}; // array for counting the words.

    puts ( "Welcome! This is a program that will count the number of words, seperate, and total the letter amount in a table!" );
    puts ( "Please enter your first sentence! To end your input and get the results, hit enter." );
    puts ( "" );

    getWords ( inputArray, wordCount );    // function call to get the sentence word count
    printWords ( wordCount );              // function call to print the total in table

    puts ( "" );
    puts ( "Thank you for using, this program. Good-bye." ); //  Good bye statement

} // end main

/*
     This function gets the words and measures the length of the word
*/
void getWords ( char sentence [ ], int wordCount [] )
{
    int length = 0, i = 0; // This is my letter counter

    fgets ( sentence, 20000, stdin ); // user enters string
    puts ( "" );

    while ( sentence[i] != '\0' ) //while loop for word length counting and ending at null token
    {
        if ( sentence [i] == '\'') //itteration for if there is an aposterphe
        {
            i++;
            length++;
            continue;
        }
        else if ( isalpha( sentence [i] ) ) //itteration for the length of a word
        {
            length++;
        }
        else if ( !isalpha( sentence [i] ) ) //itteration to array when there are no letters
        {
            wordCount [ length ]++;
            length = 0;
        }
        else    // to continue through the while loop when completed.
            continue;

        i++; //itteration for index to get to NULL token
    }// end while loop for sentence isn't a space
} // end getWords function

/*
     This prints out the length of the words, and how many occured
*/
void printWords ( int wordCount [ ] ) // function definition for printing table
{
    //int i = 0; // count for print array

    puts ( "         Word Length|Occurrences" );
    puts ( "        -------------------------" );

    for ( int i = 1; i < 21; i++ )  // For loop for the table boxes
    {
         puts ( "        |           |           |" );
        printf ( "        |    %2d     |     %d     |", i, wordCount[ i ] );
        puts ( "" );
        puts ( "        |___________|___________|");
    }// end for loop
} // end printWords function

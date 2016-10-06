/*
 * chutes_ladders.h
 * Chutes and Ladders
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 3
 * Due 10/19/2016
 *
 */

// Library Include Statements
#include <stdio.h>    /* for file utils and putc */
#include <stdlib.h>   /* for random number generation */
#include <time.h>     /* for seeding the random number generator */

// Function Prototypes
/* print the current board setup to the log file after each round of turns */
void output(FILE *, char *, char *, char *);
/* move the player pointers according to their roll and the value of the square they land on */
char *move(char *, char *, char *, int);
/* find the nearest haven when a player lands on a 'B' or an 'F' */
char *findHaven(char *, char *, char);

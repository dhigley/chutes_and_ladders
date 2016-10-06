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
void output(FILE *, char *, char *, char *);
char *move(char *, char *, char *, int);

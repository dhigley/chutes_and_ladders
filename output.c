/*
 * output.c
 * Chutes and Ladders
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 3
 * Due 10/19/2016
 *
 */

#include "chutes_ladders.h"

/* output: print the current game board setup to the file */
void output(FILE *fp, char *board, char *p1, char *p2) {
  char *current = board; /* point current to the beginning for the board array */

  /* iterate through the board and write chars to the file replace '1'
   * for the position of p1 and '2' for the position of p2 */
  while (*current != '\0') {
    if (current == p1) {
      putc('1', fp);
    }
    else if (current == p2) {
      putc('2', fp);
    }
    else
      putc(*current, fp);
    current++;
  }

  putc('\n', fp); /* write end of line char to advance to the next line */
}

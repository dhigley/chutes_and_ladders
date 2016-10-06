/*
 * main.c
 * chutes and ladders
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 3
 * Due 10/19/2016
 *
 */

#include <stdio.h>

void output(FILE *, char *, char *, char *);

int main(void) {
  // file variables
  FILE *fp = fopen("game_log.txt", "ab+");   /* open the file for writing board setup */

  // variables for the board and player pointers
  char board[100]="  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";
  char *p1 = board, *p2 = board;        /* pointer for players 1 and 2 */

  // TEST output
  output(fp, board, p1, p2);

  fclose(fp);     /* close the file */
}

/* output: print the current game board setup to the file */
void output(FILE *fp, char *board, char *p1, char *p2) {
  char *current = board; /* point current to the beginning for the board array */

  /* iterate through the board and write chars to the file replace '1'
   * for the position of p1 and '2' for the position of p2 */
  while (*current != '\0') {
    if (current == p1) {
      putc('1', fp);
      printf("p1 found\n");
    }
    else if (current == p2) {
      putc('2', fp);
      printf("p2 found\n");
    }
    else
      putc(*current, fp);
    current++;
  }

  putc('\n', fp); /* write end of line char to advance to the next line */
}

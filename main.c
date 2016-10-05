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

void output(FILE *, char *);

int main(void) {
  // file variables
  FILE *fp = fopen("game_log.txt", "ab+");   /* open the game log file for writing */

  // variables for the board and player pointers
  char board[100]="  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";
  int *p1;        /* pointer for player 1 */
  int *p2;        /* pointer for player 2 */

  // manually move the player pointers

  // TEST output
  output(fp, board);

  fclose(fp);     /* close the file */
}

/* output: print the current game board setup to the file */
void output(FILE *fp, char *board) {
  char *current = board;   /* point current to the beginning for the board array */

  while (*current != '\0') {
    putc(*current, fp);
    current++;
  }

  putc('\n', fp); /* advance to the next line */

}

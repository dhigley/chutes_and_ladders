/*
 * main.c
 * Chutes and Ladders
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 3
 * Due 10/19/2016
 *
 */

#include "chutes_ladders.h"

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


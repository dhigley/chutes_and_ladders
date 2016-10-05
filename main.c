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

int main(void) {
  // file variables
  FILE *fp = fopen("game_log.txt", "ab+");   /* open the game log file for writing */

  int *p1;        /* pointer for player 1 */
  int *p2;        /* pointer for player 2 */

  char board[100]="  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";

  fclose(fp);     /* close the file */
}

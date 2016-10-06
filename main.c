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
  FILE *fp = fopen("game_log.txt", "ab+");   /* open the file for writing board setup */
  srand(time(0));   /* seed the random number generator */

  // variables for the board and player pointers
  char board[100]="  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";
  char *p1, *p2;        /* pointer for players 1 and 2 */
  p1 = board;           /* start players at the beginning of the board */
  p2 = board;

  // move players until one reaches the end of the board
  while (p1 <= board + 100 || p2 <= board + 100) {
    p1 = move(p1, p2, board, 1);
    p2 = move(p2, p1, board, 2);

    // write move results to the log file
    output(fp, board, p1, p2);
  }
  /* printf("%c\n", *p1); */
  /* printf("%c\n", *p2); */

  fclose(fp);     /* close the file */
}

/* move: roll the dice and move the player pointer to its new position on the board */
char *move(char *player, char *viewer, char *board, int player_id) {
  // random die roll
  int roll;
  roll = rand() % 6 + 1;

  return player += roll;
}

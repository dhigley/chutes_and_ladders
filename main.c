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
  FILE *fp = fopen("game_log.txt", "w");   /* open the file for writing board setup */
  srand(time(0));   /* seed the random number generator */

  // variables for the board and player pointers
  char board[100]="  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";
  char *p1, *p2;        /* pointer for players 1 and 2 */
  p1 = board;           /* start players at the beginning of the board */
  p2 = board;

  // move players until one reaches the end of the board
  while (p1 <= board + 99 && p2 <= board + 99) {
    p1 = move(p1, p2, board, 1);
    p2 = move(p2, p1, board, 2);

    // write move results to the log file
    output(fp, board, p1, p2);
  }

  fclose(fp);     /* close the file */
}

/* move: roll the dice and move the player pointer to its new position on the board */
char *move(char *player, char *viewer, char *board, int player_id) {
  // random die roll
  int roll;
  char *destination, instruction; /* where to move the pointer and what the instruction is */

  roll = rand() % 6 + 1;        /* dice roll */
  destination = player + roll;  /* current player's new destination address */

  // print results of the dice roll
  printf("%s rolled a %d ", (player_id == 1) ? "You:" : "Me: ", roll);

  if (destination < board + 100) {  /* if the destination is still on the board */
    instruction = *destination;     /* read the value at the destination go get the instruction */
    if (instruction == 'B') {       /* player found a 'B' */
      printf(" moving backward to haven ... ");
      /* findHaven(); */
    }
    else if (instruction == 'F') {  /* player found an 'F' */
      printf(" moving forward to haven ... ");
      /* findHaven(); */
    }
    else if (instruction >= 97 && instruction < 110) {   /* player found a chute */
      printf(" landed an chute ... moving %d ...", instruction - 110);
      /* chuteLadder() */
    }
    else if (instruction > 110 && instruction <= 122) {   /* player found a ladder */
      printf(" landed an ladder ... moving %d ...", instruction - 110);
      /* chuteLadder() */
    }
  }

  if (destination == viewer) {
    destination -= 1;
    printf(" collision! ... moving back one square ...");
  }

  printf(" now at %ld\n", destination - board);
  return destination;
}

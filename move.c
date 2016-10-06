/*
 * move.c
 * Chutes and Ladders
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 3
 * Due 10/19/2016
 *
 */
#include "chutes_ladders.h"

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
      findHaven(board, destination, instruction);
      printf(" moving backward to haven ... ");
    }
    else if (instruction == 'F') {  /* player found an 'F' */
      findHaven(board, destination, instruction);
      printf(" moving forward to haven ... ");
    }
    else if (instruction >= 97 && instruction < 110) {   /* player found a chute */
      /* chuteLadder() */
      printf(" landed an chute ... moving %d ...", instruction - 110);
    }
    else if (instruction > 110 && instruction <= 122) {   /* player found a ladder */
      /* chuteLadder() */
      printf(" landed an ladder ... moving %d ...", instruction - 110);
    }
  }

  if (destination == viewer) {
    destination -= 1;
    printf(" collision! ... moving back one square ...");
  }

  printf(" now at %ld\n", destination - board);
  return destination;
}

/* findHaven: determines the nearest haven to move to depending on if the player landed on a 'B' or an 'F' */
char *findHaven(char *board, char *current, char instruction) {

}

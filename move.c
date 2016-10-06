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
  char *destination, instruction; // where to move the pointer and what the instruction is

  roll = rand() % 6 + 1;        // the dice roll
  destination = player + roll;  // current player's new destination address

  // print results of the dice roll
  printf("%s rolled a %d ", (player_id == 1) ? "You:" : "Me: ", roll);

  if (destination < board + 100) {  // if the destination is still on the board
    instruction = *destination;     // read the value at the destination to get the instruction

    if (destination == viewer) {
      destination -= 1;
      printf(" collision! ... moving back one square ...");
    }
    else if (instruction == 'B') {       // player found a 'B'
      destination = findHaven(board, destination, instruction);
      printf(" moving backward to haven ... ");
    }
    else if (instruction == 'F') {  // player found an 'F'
      destination = findHaven(board, destination, instruction);
      printf(" moving forward to haven ... ");
    }
    else if (instruction >= 97 && instruction < 110) {   // player found a chute
      /* chuteLadder() */
      printf(" landed an chute ... moving %d ...", instruction - 110);
    }
    else if (instruction > 110 && instruction <= 122) {   // player found a ladder
      /* chuteLadder() */
      printf(" landed an ladder ... moving %d ...", instruction - 110);
    }
  }

  printf(" now at %ld\n", destination - board);
  return destination;
}

/* findHaven: determines the nearest haven to move to depending on if the player landed on a 'B' or an 'F' */
char *findHaven(char *board, char *current_pointer, char instruction) {
  char *updated_pointer;         // the adjusted dest based on the instruction
  updated_pointer = current_pointer; // used the original dest as the starting point

  // decode the instruction and iterate through the loop F/B to find the nearest 'H'
  if (instruction == 'F') {
    // move the update pointer up to the next available haven
    for (updated_pointer = current_pointer; updated_pointer < board + 100 && *updated_pointer != 'H'; updated_pointer++) {
      // put the updated pointer back to current if a forward 'H' cannot be found
      if (updated_pointer == board + 99) {
        updated_pointer = current_pointer;
      }
    }
    // replace the current 'H' with a '_' so it cannot be reused
    if (*updated_pointer == 'H')
      *updated_pointer = '_';
  }
  else if (instruction == 'B') {
    // move the updated pointer back to the previous available haven
    for (updated_pointer = current_pointer; updated_pointer > board && *updated_pointer != 'H'; updated_pointer--) {
      // pointer move
    }
    // replace the current 'H' with a '_' so it cannot be reused
    if (*updated_pointer == 'H')
      *updated_pointer = '_';
  }

  return updated_pointer;
}

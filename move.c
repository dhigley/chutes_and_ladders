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

    if (destination == viewer) {    // check for player collision after move
      destination -= 1;
      printf(" collision! ... moving back one square ...");
    }
    else if (instruction == 'B' || instruction == 'F') { // check tile for 'F' or 'B'
      destination = findHaven(board, destination, instruction);
    }
    else if (instruction >= 97 && instruction <= 122) { // check if tile is chute or ladder
      /* destination = chuteLadder(board, destination, instruction); */
    }
  }

  printf(" now at %ld\n", destination - board);
  return destination;
}

/* chuteLadder: moves a player forward or backward a set amount of tiles depending on the value of the tile they land on */
char *chuteLadder(char *board, char *current_pointer, char instruction) {
  char *updated_pointer;         // the adjusted dest based on the instruction
  updated_pointer = current_pointer; // used the original dest as the starting point

  return updated_pointer;
}

/* findHaven: moves a player forward or backward to the nearest haven depending on if they landed on a 'F' or a 'B' */
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

    printf(" moving forward to haven ...");
  }
  else if (instruction == 'B') {
    // move the updated pointer back to the previous available haven
    for (updated_pointer = current_pointer; updated_pointer > board && *updated_pointer != 'H'; updated_pointer--) {
      // pointer move
    }
    // replace the current 'H' with a '_' so it cannot be reused
    if (*updated_pointer == 'H')
      *updated_pointer = '_';

    printf(" moving backward to haven ...");
  }

  return updated_pointer;
}

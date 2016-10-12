/*
 * main.c
 * Chutes and Ladders
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 3
 * Due 10/19/2016
 *
 * Chutes and Ladders game. The while loop in main continues to call move on each
 * player's pointer and prints the results of each round of moves to a file until
 * one of the pointers reaches the end of the board (board + 100). Move generates
 * a random number from 1 to 6, moves the players pointer forward that many
 * tiles, and checks the contents of the tile. Landing on an 'F' or a 'B' calls
 * the findHaven function, moves the player either forward or backward depending
 * on the value to the nearest available haven, designated 'H', and replaces the
 * 'H' with a '_' so the haven cannot be used again. Landing a lowercase letter
 * calls the chuteLadder function. The chuteLadder function takes the ascii value
 * of the character found on the tile and subtracts it form 110 and moves the
 * player the resulting number of spaces the player moves. Positive values move
 * the player forward and negative values move the player backwards (landing on
 * an 'n' does nothing as the ascii value for n = 110. The letter that was landed
 * on is then changed to a '*' so that it cannot be used again. The results of
 * every roll and the number of spaces moved is printed to the console. Once a
 * players pointer reaches the end of the board (board + 100) the winner is
 * declared and the game is terminated.
 *
 */
#include "chutes_ladders.h"

int main(void) {
  FILE *fp = fopen("game_log.txt", "w");   // open the file for writing board setup
  srand(time(0));   // seed the random number generator

  // variables for the board and player pointers
  char board[100]="  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";
  char *p1, *p2;        // pointer for players 1 and 2
  p1 = board;           // start players at the beginning of the board
  p2 = board;

  // advance players down the board with the move function until one reaches the end
  while (p1 < board + 100 && p2 < board + 100) {  // while neither player has won
    // player 1 moves
    p1 = move(p1, p2, board, 1);          // move player 1
    if (p1 >= board + 100)                // if player 1 wins
      printf("You won the game\n");       // let them know

    // player 2 moves
    if (p1 < board + 100) {               // if player 1 has not won the game
      p2 = move(p2, p1, board, 2);        // move player 2
      if (p2 >= board + 100)              // if player 2 wins
        printf("I won the game\n");       // let them know
    }

    // write move results to the log file
    output(fp, board, p1, p2);
  }

  fclose(fp);     // close the file
}

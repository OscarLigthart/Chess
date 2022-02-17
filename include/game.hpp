/**
 *  Header file of the game class
 */

#ifndef GAME_H
#define GAME_H

#include <board.hpp>
#include <piece.hpp>
#include <legal_move_generator.hpp>


class Game
  {
    public:
    Board* board;
    LegalMoveGenerator* lgm;
    int turn = 1; // 1 for white and 0 for black
    std::vector<Moves> moves; // keep track of the valid moves in the current game state


    /**
     *  Constructor
     */    
    Game(Board &board);

    /**
     *  Function to process clicked squares on the board
     *  @param selectedPiece (piece) the piece that has been selected to move
     *  @param y the clicked rank of the board
     *  @param x the clicked file of the board
     */
    void process(Piece* selectedPiece, int y, int x);

    /**
     *  Function to check whether the game is over given the current board configuration
     */
    void checkGameOver();
};

#endif
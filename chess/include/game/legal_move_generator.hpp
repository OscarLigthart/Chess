/**
 *  Header of the legal move generator
 *  This class takes the board and decides all the valid moves for one player
 */

#ifndef LEGAL_MOVE_GENERATOR
#define LEGAL_MOVE_GENERATOR

#include <board.hpp>
#include <game/moves.hpp>
#include <array>
#include <vector>


class LegalMoveGenerator 
  {
    public:
    Board* board;

    /**
     *  Constructor
     */    
    LegalMoveGenerator(Board &board);

    /**
     *  Method to generate all possible moves given a board configuration
     *  for the white or black player
     *  @param turn (int) 0 for black's turn and 1 for white's turn
     */
    std::vector<Moves> generate(int turn);

    /**
     *  Method that generates the moves of all pieces considering a board configuration
     *  The moves yielded by this function ignore checks and castling
     *  @param turn (int) 0 for black's turn and 1 for white's turn
     */
    std::vector<Moves> generateAllPieceMoves(int turn);

    /**
     *  Method that generate all the moves of a single piece of the board
     *  @param piece (Piece) the piece for which the moves should be generated
     */
    std::vector<Move> generateSinglePieceMoves(Piece* piece);

    /**
     *  Method to look for checks given a certain board configuration
     *  !! IMPORTANT !! This function will only be called on pseudoboards
     *  @param turn (int) the player's turn
     */
    bool lookForChecks(int turn);

    /**
     *  Method that checks if the player has castling rights given a certain
     *  board configuration
     *  @param turn (int) the player's turn
     */ 
    std::vector<Moves> checkCastling(int turn);

    /**
     *  Method that checks whether the short castling move is available
     *  Takes as input the king and the king side rook of a particular player
     *  @param king (Piece) the king that will move
     *  @param rook (Piece) the rook on the king side
     */
    bool validateCastlingMove(Piece* king, Piece* rook, int turn, std::string side);

    /**
     *  Method to print all the available moves of the current board configurations
     *  Mainly used for debugging
     *  @param turn (int) 0 for black's turn and 1 for white's turn
     */
    void printMoves(int turn);    
};

#endif
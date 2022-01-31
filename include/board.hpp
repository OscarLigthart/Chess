/**
 *  Header file of the board
 */

#ifndef BOARD
#define BOARD

#include <piece.hpp>
#include <moves.hpp>


class Board 
  {
    public:

    int size = 56; // required for cutting out the pieces 
    int piece_size = 100; // 800/8

    // sprites
    sf::Sprite f[32];
    sf::Sprite boardSprite;
    sf::Texture figures;

    // pieces
    std::vector <Piece*> pieces;
    
    // board engine layout
    int board[8][8] = {
        { -1,-2,-3,-4,-5,-3,-2,-1 },
        { -6,-6,-6, 0,-6,-6,-6,-6 },
        {  0, 0, 0, -6, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  6, 6, 6, 6, 6, 6, 6, 6 },
        {  1, 2, 3, 4, 5, 3, 2, 1 }
    };  
    int oldBoard[8][8]; // memory for the last configuration

    /**
     *  Constructor
     */    
    Board();

    /**
     *  Method to build the pieces to the board
     */
    void buildPieces();

    /**
     *  Method to perform a single move on the board
     *  @param move (Move) the move struct object holding all info to make the move
     */
    void move(Move move);

    /**
     *  Method to undo a given move on the board
     *  @param move (Move) the move struct object holding all info to make the move
     */
    void undo(Move move);

    /**
     *  Method to remove a piece from the board
     *  @param p (Piece) the piece object to be removed from the board
     */
    void removePiece(Piece* p);

    /**
     *  Method to print the board
     */ 
    void print();
};

#endif

/**
 *  Header file of the board
 */

#ifndef BOARD_H
#define BOARD_H

#include <piece.hpp>
#include <game/moves.hpp>


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
    // int board[8][8] = {
    //     { 0,-2,0,-4,-5,0,-2,-1 },
    //     { -6,-6,-6, -6,-6,-6,-6,-6 },
    //     {  0, 2, 3, 4, 0, 0, 0, 0 },
    //     {  0, 0, 0, 0, 0, 6, 0, 0 },
    //     {  0, 0, -1, -3, 0, -3, 0, 0 },
    //     {  0, 0, 0, 6, 6, 3, 2, 0 },
    //     {  6, 6, 6, 0, 0, 0, 6, 6 },
    //     {  1, 0, 0, 0, 5, 0, 0, 1 }
    // };  

    int board[8][8] = {
        { -1,-2,0,-4,-5,-3,-2,-1 },
        { -6,-6,-6, -6,-6,-6,-6,-6 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, -3, 0 },
        {  0, 2, 3, 4, 6, 0, 0, 0 },
        {  6, 6, 6, 6, 0, 6, 6, 6 },
        {  1, 0, 0, 0, 5, 3, 2, 1 }
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
     *  @param pseudo (bool) determine whether this is an actual or a pseudo move
     */
    void move(Move move, bool pseudo);

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

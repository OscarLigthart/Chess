/**
 *  Header file of the board
 */

#ifndef BOARD
#define BOARD

#include <piece.hpp>


class Board 
  {
    public:

    int size = 56; // required for cutting out the pieces 
    int piece_size = 100; // 800/8

    // sprites
    sf::Sprite f[32];
    sf::Sprite boardSprite;

    // pieces
    std::vector <Piece*> pieces;
    
    // board engine layout
    int board[8][8] = {
        { -1,-2,-3,-4,-5,-3,-2,-1 },
        { -6,-6,-6,-6,-6,-6,-6,-6 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  0, 0, 0, 0, 0, 0, 0, 0 },
        {  6, 6, 6, 6, 6, 6, 6, 6 },
        {  1, 2, 3, 4, 5, 3, 2, 1 }
    };  

    /**
     *  Constructor
     */    
    Board();

    /**
     *  Method to build the pieces to the board
     */
    void buildPieces();

    /**
     *  Method to find if a requested move is a valid move
     *  Requests a clicked piece as input argument
     */
    void getValidMoves();
    

    /**
     *  Method to draw the board. Starts by drawing an empty board,
     *  then starts putting the pieces on there. 
     */
    void draw(void);

};

#endif

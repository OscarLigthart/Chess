#include <iostream>
#include <GLFW/glfw3.h>

class Board 
  {
    public:
    Board ( )
    {
        std::cout << "Board constructed\n";

    }

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
     *  Method to find if a requested move is a valid move
     *  Requests a clicked piece as input argument
     */
    void getValidMoves(){

    }
    

    /**
     *  Method to draw the board. Starts by drawing an empty board,
     *  then starts putting the pieces on there. 
     */
    void draw(void) {


    }

  };

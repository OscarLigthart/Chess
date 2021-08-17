#include <iostream>
#include <GLFW/glfw3.h>

class ChessBoard 
  {
    public:
    ChessBoard ( )
    {
        std::cout << "Board constructed\n";

    }

    int board[8][8] = {0};    

    /**
     *  Method to draw the board. Starts by drawing an empty board,
     *  then starts putting the pieces on there. 
     */
    void draw(void) {

        bool white = false;
        
        int n = 8; // 8 squares
        float sw = 2.0/8.0, sh = 2.0/8.0; //square width and height respectively
        //for each width and height draw a rectangle with a specific color
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {

                //oscillate the color per square of the board
                if(white)
                    glColor3f(1, 1, 1);
                else
                    glColor3f(0, 0, 0);
                white = !white;
                
                //draw a rectangle in the ith row and jth column
                glRectf(i*sw - 1, j*sh - 1, (i+1)*sw - 1, (j+1)*sh - 1);
                
            }
            white = !white; //switch color at end of row
        }


    }

  };

#include <iostream>
// #include <GLFW/glfw3.h>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <piece.cpp>
#include <pieces/pawn.cpp>
#include <pieces/bishop.cpp>
#include <pieces/king.cpp>
#include <pieces/knight.cpp>
#include <pieces/queen.cpp>
#include <pieces/rook.cpp>
#include <vector>
#include <cmath>


int size = 56; // required for cutting out the pieces 
int piece_size = 100; // 800/8
sf::Sprite f[32];
std::vector <Piece*> pieces;

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

void pieceBuilder()
{
    int k=0;
    for (int i=0;i<8;i++)
      for (int j=0;j<8;j++)
        {
            int n = board[i][j];
            if (!n) continue;

            int pieceId = abs(n) - 1;
            int player = n > 0 ? 1 : 0;
            
            // initialize the piece
            Piece* piece;

            switch(pieceId) {
                case 0:
                    {
                        piece = new Rook(player);
                        break;
                    }
                case 1: 
                    {
                        piece = new Knight(player);
                        break;
                    }
                case 2:
                    { 
                        piece = new Bishop(player);
                        break;
                    }
                case 3: 
                    {
                        piece = new Queen(player);
                        break;
                    }
                case 4: 
                    {   
                        piece = new King(player);
                        break;
                    }
                case 5: 
                    {
                        piece = new Pawn(player);
                        break;
                    }
            }

            // place piece correctly
            piece->setSpritePosition(piece_size*j, piece_size*i);
            piece->setPosition(i, j);

            // add to vector
            pieces.push_back(piece);
        }
}


int main() {
    // Declare and create a new render-window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

    sf::Texture b, figures;
    b.loadFromFile("../img/board.png");    
    figures.loadFromFile("../img/pieces.png");
    sf::Sprite Board(b);
    sf::Sprite Figures(figures);

    Board.setScale(0.8f, 0.8f);
    for (int i=0; i<32; i++) {
        f[i].setTexture(figures);
        f[i].setScale(1.8f, 1.65f);
    }

    pieceBuilder();

    bool moving = false;
    float dx=0, dy=0;
    int n=0;
    int p=-1;

    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {

        // get mouse position
        sf::Vector2i pos = sf::Mouse::getPosition(window);

        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();

            // check which square has been pressed
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left)
                {

                    // figure out which board coordinates
                    int x = float(pos.x)/800 * 8;
                    int y = float(pos.y)/800 * 8;

                    // pick up the piece
                    if (!moving){

                        // do something if there is a piece there
                        // find out which piece it is as well
                        n = board[y][x];

                        // check which piece is placed there
                        for (int i=0; i<32; i++) {
                            if (pieces[i]->getPosition()[0] == y && pieces[i]->getPosition()[1] == x) {
                                p = i;

                                std::cout << "Clicked\n";

                                break;
                            }
                        };

                        // indicate we start moving
                        if (n) 
                        {
                            moving = !moving;    
                        }

                    // put down the piece
                    }
                    else {
                        // update the board
                        board[y][x] = n;

                        // move the piece to the center of the square
                        pieces[p]->move(y, x);
                        

                        // reset
                        p = -1;
                        moving = !moving;
                    }

                }

            // place it on top of the mouse if we're in moving state
            if (moving && p > -1) pieces[p]->setSpritePosition(pos.x - piece_size/2, pos.y - piece_size/2);

        }

        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Draw some graphical entities
        window.draw(Board);
        for (int i=0; i<32; i++) window.draw(pieces[i]->getSprite());

        // End the current frame and display its contents on screen
        window.display();
    }
}


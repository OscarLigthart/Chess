#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <board.hpp>
#include <game.hpp>
#include <game/legal_move_generator.hpp>
#include <interface.hpp>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>


/**
 *  Main function
 *  Here we open the SFML window and initialize all classes
 *  we need to correctly run the game
 */
int main() {
    
    // Declare and create a new render-window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

    // initialize the board
    Board board;

    // initialize board texture
    sf::Texture b;
    b.loadFromFile("../img/board.png");  
    board.boardSprite.setTexture(b);
    board.boardSprite.setScale(0.66666666f, 0.66666666f); 
    
    // initialize the interface
    Interface interface;

    // initialize the game class
    Game game = Game(board);

    // create vector buffer for piece position
    std::vector<std::array<int,2>> positionBuffer;

    /**
     *  The main loop
     *  As long as the window is open this code will keep running
     */
    while (window.isOpen())
    {

        // get mouse position
        sf::Vector2i pos = sf::Mouse::getPosition(window);

        /**  
         *  Here we process user input in the form of mouse clicks 
         *  The clicks are processed into board squares and depending on
         *  whether a piece is present at the square, the information is 
         *  sent to the game for further process
         */
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
                    
                    // figure out which board coordinates are clicked
                    int x = float(pos.x)/800 * 8;
                    int y = float(pos.y)/800 * 8;

                    // if we're not already moving a piece we should process the input
                    // to determine which piece is clicked
                    if (!interface.moving) {
                        interface.processInput(board, x, y, game.turn);
                    }
                    // if we are moving then this click means we're putting a piece somewhere
                    else {

                        // let the game process the requested move 
                        // this is where the magic happens, the move is checked and if it's valid it's performed
                        game.process(interface.selectedPiece, y, x);

                        // reset the interface so we can process the next click
                        interface.reset();
                    }
                }
        }

        /** 
         *  Place it on top of the mouse if we're in moving state
         *  We implement a small buffer here to create a sense of "drag" when picking up the piece
         *  this gives the player a feel as if the piece carries some weight, making it more realistic
         */
        if (interface.moving) {

            // add position to buffer
            std::array<int,2> posElement = {pos.x - board.piece_size/2, pos.y - board.piece_size/2};
            positionBuffer.push_back(posElement);
            
            // only start moving if the buffer has filled up a bit
            if (positionBuffer.size() > 3) {

                // move the position to the buffer element
                interface.selectedPiece->setSpritePosition(positionBuffer.front()[0], positionBuffer.front()[1]);

                // remove the element at the beginning of the buffer
                positionBuffer.erase(positionBuffer.begin());
            }
        } else positionBuffer = {}; // clear the position buffer if we are not moving

        /**
         *  Draw the board after running all processes
         */
        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Draw some graphical entities
        window.draw(board.boardSprite);
        for (int i=0; i<board.pieces.size(); i++) window.draw(board.pieces[i]->getSprite());

        // End the current frame and display its contents on screen
        window.display();

        // now sleep for a bit to get a specific framerate (around 60fps)
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
}

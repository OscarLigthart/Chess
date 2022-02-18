#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <board.hpp>
#include <game.hpp>
#include <game/legal_move_generator.hpp>
#include <interface.hpp>
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


int main() {
    // Declare and create a new render-window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

    // initialize the board
    Board board;

    // initialize textures
    sf::Texture b, figures;
    b.loadFromFile("../img/board.png");  

    board.figures.loadFromFile("../img/pieces.png");    
    board.boardSprite.setTexture(b);
    board.boardSprite.setScale(0.66666666f, 0.66666666f); 
    
    // initialize the interface
    Interface interface;

    // initialize the game class
    Game game = Game(board);

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

            // place it on top of the mouse if we're in moving state
            if (interface.moving) {
                interface.selectedPiece->setSpritePosition(pos.x - board.piece_size/2, pos.y - board.piece_size/2);
            }
        }

        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Draw some graphical entities
        window.draw(board.boardSprite);
        for (int i=0; i<board.pieces.size(); i++) window.draw(board.pieces[i]->getSprite());

        // End the current frame and display its contents on screen
        window.display();
    }
}

/**
 *  Implementation of the game engine
 * 
 *  The engine is the place where everything comes together
 *  end-to-end, it will process the clicked file all the way up
 *  to checking the validity of the move and making it happen
 */


#include <engine.hpp>
#include <interface.hpp>
#include <board.hpp>
#include <legal_move_generator.hpp>

Engine::Engine(Board &board) {
    
    // inherit the board
    this->board = board;

    // initialize the legal move generator
    this->lgm = LegalMoveGenerator(board);

}

/**
 *  Function to process clicked squares on the board
 *  @param y the clicked rank of the board
 *  @param x the clicked file of the board
 */
void Engine::process(int y, int x) {

    // do something if there is a piece there
    // find out which piece it is as well
    this->square = this->board.board[y][x];

    // check which piece is placed there
    for (int i=0; i<32; i++) {
        if (board.pieces[i]->getPosition()[0] == y && board.pieces[i]->getPosition()[1] == x) {
            this->selectedPiece = board.pieces[i];

            // insert this piece at the start and remove it from the list
            board.pieces.push_back(board.pieces[i]);
            board.pieces.erase(board.pieces.begin() + i);
            
            break;
        }
    };

    for (int i=0; i<32; i++) std::cout << board.pieces[i]->notation << ' ';

    // indicate we start moving, if we have a piece on the square
    if (this->square) 
    {
        this->moving = !this->moving;    
    }
}

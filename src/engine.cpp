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

Engine::Engine(Board* board) {
    
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

    // check the turn

    // the interface needs the turn
}

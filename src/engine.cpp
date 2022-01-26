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
#include <moves.hpp>
#include <legal_move_generator.hpp>

Engine::Engine(Board &board) {
    
    // inherit the board
    this->board = &board;

    // initialize the legal move generator
    this->lgm = new LegalMoveGenerator(board);

}

/**
 *  Function to process clicked squares on the board
 *  @param y the clicked rank of the board
 *  @param x the clicked file of the board
 */
void Engine::process(Piece* selectedPiece, int y, int x) {

    // check the turn
    std::vector<Moves> moves = this->lgm->generate(this->turn);

    // the requested move should be in the valid moves
    for (int i=0; i<moves.size(); i++) {
        
        // print the moves
        // todo need to have a better ID for every piece
        continue;
    }
}

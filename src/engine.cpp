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
#include <iostream>
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

    // get the square on the board the piece was originally at
    int square = this->board->board[selectedPiece->y][selectedPiece->x];
    
    // check the turn
    std::vector<Moves> moves = this->lgm->generate(this->turn);

    // the requested move should be in the valid moves
    for (int i=0; i<moves.size(); i++) {
        
        // print the moves
        // todo need to have a better ID for every piece
        if (moves[i].pieceId == selectedPiece->id) {
            
            // check if any of the moves is valid
            for (int j=0; j<moves[i].moves.size(); j++) {

                if (moves[i].moves[j][0] == y && moves[i].moves[j][1] == x){
                    
                    // here we should actually make the move
                    // update the board with the piece position
                    this->board->board[y][x] = square;

                    // old square should be zero, as there will no longer be a piece
                    this->board->board[selectedPiece->y][selectedPiece->x] = 0;

                    // check for capture here
                    // need to call remove on the captured piece

                    // make the move for the piece
                    selectedPiece->move(y, x);

                    // set the other turn
                    this->turn = !turn;

                    // stop here
                    return;
                }
            }
        }
    }

    // if we made it this far we have to move the piece back, as it was no legal move
    selectedPiece->move(selectedPiece->y, selectedPiece->x);
}

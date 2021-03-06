/**
 *  Implementation of the Pawn
 */

#include <iostream>
#include <pieces/pawn.hpp>


/**
 *  Constructor
 */ 
Pawn::Pawn(int player, int id, int rank, int file) {

    // determine which player is handled to get the color
    std::string color = player == 0 ? "black" : "white";

    // set the texture here
    this->figures.loadFromFile("../img/pieces/" + color + "/pawn.png");

    // set the texture here
    this->sprite.setTexture(this->figures);
    this->sprite.setScale(0.66f, 0.66f);

    // set player
    this->player = player;  
    this->id = id;
    this->notation = "";

    // set playervalue, for the pawns movement direction we need this value
    this->playerValue = player == 1 ? -1 : 1;  

    // set position
    this->y = rank;
    this->x = file;
}

/**
 *  Method that retrieves all moves for this piece
 *
 *  @return list of arrays depicting a diagonal in coordinates
 */ 
std::vector<std::array<int, 2>> Pawn::getMoves(int board[8][8]) {

    // depending on the player we have different directions in y-value
    // which is depicted as -1 or 1 in this->playerValue
    std::vector<std::array<int,2>> directions = {
        {this->playerValue, 1},
        {this->playerValue, -1},
        {this->playerValue, 0},
    };

    // pawns can move two places if they haven't already
    if (!this->has_moved) {
        directions.push_back(std::array<int,2> {2 * this->playerValue, 0});
    }

    // initialize valid move list
    std::vector<std::array<int,2>> moves;

    // set the current position to the actual position
    std::array<int,2> start = {this->y, this->x};

    // loop over the directions
    for (int i=0; i<directions.size(); i++) {

        // take current position and add the direction
        std::array<int,2> new_move = {start[0] + directions[i][0], start[1] + directions[i][1]};

        // start by checking for out of bounds
        bool outOfBounds = this->checkOutOfBounds(new_move[1], new_move[0]);

        // skip this loop if we are out of bounds
        if (outOfBounds) { continue; }

        // retrieve the piece that is placed on the square of the new move
        int square = board[new_move[0]][new_move[1]];

        // for the forward directions, we can't capture
        if (directions[i][1] == 0) {

            // check for collisions
            std::array<bool, 2> collision = this->checkCollision(new_move, square);

            // add the move if it doesn't collide
            if (!collision[0]) { moves.push_back(new_move); }
            else { break; }
        }
        // for the sideways directions, we should check for captures,
        // we can only make the move if it's a capture
        else {
            
            // check for 
            std::array<bool, 2> collision = this->checkCollision(new_move, square);

            // add the move if it will capture an opponent's piece
            if (collision[1]) { moves.push_back(new_move); }
        }      
    }

    // the total set of valid moves
    return moves;
}

void Pawn::setSpritePosition(int x, int y) { 

    // set the sprite position
    this->sprite.setPosition(x, y); 
}

void Pawn::setPosition(int y, int x) {

    // check if the new y and x are not on the starting file to determine if this piece has moved
    int startFile = this->player == 1 ? 6 : 1;
    if (y == startFile) {
        this->has_moved = false;
    }
    else {
        this->has_moved = true;
    }

    // move the piece
    this->y = y;
    this->x = x;
}


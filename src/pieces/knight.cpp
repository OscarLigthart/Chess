/**
 *  Implementation of the knight piece
 */

#include <iostream>
#include <pieces/knight.hpp>


/**
 *  Constructor
 */
Knight::Knight(int player) {
    
    // let the world know we're creating a knight
    std::cout << "Creating Knight\n";

    // set the texture here
    this->figures.loadFromFile("../img/pieces.png");
    // set the texture here
    this->sprite.setTexture(this->figures);

    // std::cout << this->size;
    this->sprite.setTextureRect( sf::IntRect(this->size*1, this->size*player, this->size, this->size)); 
    this->sprite.setScale(1.8f, 1.65f);   
}

bool Knight::isValidMove(int y, int x) {

    // get difference in movement
    int dy = std::abs(this->y - y);
    int dx = std::abs(this->x - x);

    // difference should be one and both should be lower than 3
    if ((dx == 2 || dx == 1) && (dy == dx % 2 + 1)) {
        return true;
    } else {
        return false;
    }   
}

/**
 *  Method that retrieves all moves for this piece
 *
 *  @return list of arrays depicting a diagonal in coordinates
 */ 
std::vector<std::array<int, 2>> Rook::getMoves(int board[8][8]) {

    // generate the directions to move in
    int directions[8][2] = {
        {1,2}, {2,1},
        {2,-1}, {1,-2},
        {-2,-1}, {-1,-2}
        {-2,1}, {-1,2}
    };

    // initialize valid move list
    std::vector<std::array<int,2>> moves;

    // set the current position to the actual position
    std::array<int,2> start = {this->y, this->x};

    // loop over diagonals
    for (int i=0; i<8; i++) {

        // take current position and add the direction
        std::array<int,2> new_move = {start[0] + directions[i][0], start[1] + directions[i][1]};

        // start by checking for out of bounds
        bool outOfBounds = this->checkOutOfBounds(new_move[1], new_move[0]);

        // skip this loop if we are out of bounds
        if (outOfBounds) { continue; }
        
        // retrieve the piece that is placed on the square of the new move
        int square = board[new_move[0]][new_move[1]];

        // check for collisions
        bool collision = this->checkCollision(moves, new_move, square);

        // if we collided we should stop
        if (collision) { break; }

        // if we reach this we can add the move to the total moves
        moves.push_back(new_move);
    }

    // the total set of valid moves
    return moves;
}


void Knight::setSpritePosition(int x, int y) { 

    // change sprite position
    this->sprite.setPosition(x, y); 
}

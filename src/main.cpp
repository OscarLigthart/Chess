#include <iostream>
// #include <GLFW/glfw3.h>
#include <SFML/Graphics.hpp>
#include <time.h>

int size = 56; // required for cutting out the pieces 
int piece_size = 100; // 800/8
sf::Sprite f[32];
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

int pieces_board[8][8] = {
    {  1, 2, 3, 4, 5, 6, 7, 8 },
    {  9,10,11,12,13,14,15,16 },
    {  0, 0, 0, 0, 0, 0, 0, 0 },
    {  0, 0, 0, 0, 0, 0, 0, 0 },
    {  0, 0, 0, 0, 0, 0, 0, 0 },
    {  0, 0, 0, 0, 0, 0, 0, 0 },
    {  17,18,19,20,21,22,23,24 },
    {  25,26,27,28,29,30,31,32 }
};

void loadPosition()
{
    int k=0;
    for (int i=0;i<8;i++)
      for (int j=0;j<8;j++)
        {
            int n = board[i][j];
            if (!n) continue;
            int x = abs(n) - 1;
            int y = n>0?1:0;
            f[k].setTextureRect( sf::IntRect(size*x, size*y, size, size));
            f[k].setPosition(piece_size*j, piece_size*i);
            k++;
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

    loadPosition();

    bool moving = false;
    float dx=0, dy=0;
    int n=0;
    int p=0;

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
                        p = pieces_board[y][x];
                        std::cout << p << std::endl;

                        if (n) 
                        {
                            moving = !moving;    
                        }

                    // put down the piece
                    }
                    else {
                        
                        pieces_board[y][x] = p;
                        board[y][x] = n;
                        f[p-1].setPosition(piece_size*x, piece_size*y);
                        moving = !moving;
                    }

                }

            // place it on top of the mouse if we're in moving state
            if (moving && p > 0) f[p-1].setPosition(pos.x - piece_size/2, pos.y - piece_size/2);

        }

        
        
        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Draw some graphical entities
        window.draw(Board);
        for (int i=0; i<32; i++) window.draw(f[i]);

        // End the current frame and display its contents on screen
        window.display();
    }
}
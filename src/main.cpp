#include <GLFW/glfw3.h>
#include <SFML/Graphics.hpp>
#include <time.h>

// int size = 56;
// sf::Sprite f[32];
// int board[8][8] = {
//     { -1,-2,-3,-4,-5,-3,-2,-1 },
//     { -6,-6,-6,-6,-6,-6,-6,-6 },
//     {  0, 0, 0, 0, 0, 0, 0, 0 },
//     {  0, 0, 0, 0, 0, 0, 0, 0 },
//     {  0, 0, 0, 0, 0, 0, 0, 0 },
//     {  0, 0, 0, 0, 0, 0, 0, 0 },
//     {  6, 6, 6, 6, 6, 6, 6, 6 },
//     {  1, 2, 3, 4, 5, 3, 2, 1 }
// };

// int main()
// {
//     sf::RenderWindow game(sf::VideoMode(640, 640), "Chess");
//     sf::Texture t1,t2;
//     t1.loadFromFile("img/pieces.png");
//     t2.loadFromFile("img/board.png");
//     // sf::Sprite s;
//     sf::Sprite sBoard(t2);
//     // s.setTexture(t1);

//     while (game.isOpen()) {

//         game.clear();
//         game.draw(sBoard);
//         game.display();

//     }
// }

int main() {
    // Declare and create a new render-window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

    sf::Texture b;
    b.loadFromFile("img/board.png");
    sf::Sprite Board(b);

    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear the whole window before rendering a new frame
        window.clear();
        
        // Draw some graphical entities
        window.draw(Board);

        // End the current frame and display its contents on screen
        window.display();
    }
}
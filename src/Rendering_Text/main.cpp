#include<SFML/Graphics.hpp>

// Main Window and FPS
int width = 800, height = 600;
int fps = 120;
std::string title = "Rendering Text";

int main() {
    // Create Window and Set FPS
    sf::RenderWindow win(sf::VideoMode(width, height), title, sf::Style::Default);
    win.setFramerateLimit(fps);

    // Fonts
    // Merchant Copy
    sf::Font merchant_copy;
    merchant_copy.loadFromFile("assets/fonts/Merchant Copy.ttf");

    // Texts
    sf::Text text;
    text.setFont(merchant_copy);
    text.setString("Hello World!");

    // Main Loop
    while(win.isOpen()) {
        // Event Loop
        sf::Event event;
        while(win.pollEvent(event)) {
            // Close Button to Quit
            if(event.type == sf::Event::Closed) {
                win.close();
            }

            // Escape Key to Quit
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                win.close();
            }
        }

        // Clear Screen
        win.clear(sf::Color::Black);

        // Draw Here
        win.draw(text);

        // Display Everything on Screen
        win.display();
    }

    return 0;
}

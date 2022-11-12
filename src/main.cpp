#include<iostream>
#include<SFML/Graphics.hpp>

// Function Prototypes
void keyboardInput(sf::Sprite &sprite);

// Main Window
int width = 800, height = 600;
std::string title = "GAME";

// Player
float speed = 2;
sf::Vector2f playerPos(100,100);
sf::Vector2f playerScale(0.5,0.5);

// FPS 
int fps = 120;

int main() {
    // Create Main Window
    sf::RenderWindow win(sf::VideoMode(width, height), title, sf::Style::Default);

    // Set FPS
    win.setFramerateLimit(fps);

    // Player Texture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("gfx/player.png");

    // Player Sprite
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(playerPos);
    playerSprite.setScale(playerScale);

    // Main Loop
    while(win.isOpen()) {
        // Poll Events
        sf::Event event;
        while(win.pollEvent(event)) {
            // Quit Game
            if(event.type == sf::Event::Closed) {
                win.close();
            }

             // Escape Key to Exit
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                win.close();
            }
        }

        // Keyboard Input
        keyboardInput(playerSprite);

        // Clear Screen
        win.clear(sf::Color::Black);

        // Draw Here
        win.draw(playerSprite);

        // Display Everything
        win.display();
    }

    return 0;
}

void keyboardInput(sf::Sprite &sprite) {
    // Right Arrow Key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            playerPos.x += speed;
            sprite.setPosition(playerPos);
    }
    
    // Left Arrow Key
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        playerPos.x -= speed;
        sprite.setPosition(playerPos);
    }

    // Up Arrow Key
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        playerPos.y -= speed;
        sprite.setPosition(playerPos);
    }

    // Down Arrow Key
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        playerPos.y += speed;
        sprite.setPosition(playerPos);
    }
}

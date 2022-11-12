#include<iostream>
#include<SFML/Graphics.hpp>

/*
    Created By: Voxi0
    This is a simple example of SFML. It's just a trollface texture bouncing around the screen using Pixel
    Perfect Collisions (Recommended to not use normally). Even though it's a really bad idea using Pixel
    Perfect Collision, it is easy to implement as long as we know the sizes and stuff accurately.

    Hopefully you will understand how this code works after reading it. I recommend you try to understand what's
    going on instead of swiping my code if you're a beginner.
*/

// Main Window
int width = 800, height = 600;
std::string title = "GAME";

// Player
float xVel = 2, yVel = 2;
sf::Vector2f playerPos(50,50);
sf::Vector2f playerScale(0.5, 0.5);

// FPS 
int fps = 120;

int main() {
    // Create Main Window
    sf::RenderWindow win(sf::VideoMode(width, height), title, sf::Style::Default);

    // Set FPS
    win.setFramerateLimit(fps);

    // Textures
    // Player Texture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("gfx/player.png");
    int playertextureSize = 128;

    // Sprites
    // Player Sprite
    sf::Sprite playerSprite(playerTexture);
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

        // Physics
        // X-Velocity
        if(playerPos.x < 0 || playerPos.x > width - playertextureSize) xVel = -xVel;

        // Y-Velocity
        if(playerPos.y < 0 || playerPos.y > height - playertextureSize) yVel = -yVel;

        // Clear Screen
        win.clear(sf::Color::Black);

        // Draw Here
        win.draw(playerSprite);

        // Set Position According to X and Y Vel
        playerPos.x += xVel;
        playerPos.y += yVel;
        playerSprite.setPosition(playerPos);

        // Display Everything
        win.display();
    }

    return 0;
}

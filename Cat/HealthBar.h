#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class HealthBar{

    public:
    HealthBar();
    int getHealth();
    void setHealt(int a);
    float HealthRatio;
    int maxHealth;
    void draw (sf::RenderTarget) const;
    void setPosition(float x, float y);

    int health;
    sf::RectangleShape outline;
    sf::RectangleShape bar;
    sf::Sprite heart;
    sf::Texture heart_pic;             
    void update(); 
};


﻿#include "Piece.h"

// Constructor
Piece::Piece(Color color, sf::Vector2i position)
    : color(color), position(position) {}

// Destructor
Piece::~Piece() {}

// Draw method
void Piece::draw(sf::RenderWindow& window) {
    // TODO: Check if in window.draw() this check isn't already present
    if (!texture.getSize().x || !texture.getSize().y) {
        return;
    }
    window.draw(sprite);
}
// TODO: Maybe no need for snapping like this, just set chessPos = squarePos
void Piece::snapToGrid()
{
    sprite.setPosition(position.x * tileSize, position.y * tileSize);
}

// Get position
sf::Vector2i Piece::getPosition() const { return position; }

// Set position
void Piece::setPosition(sf::Vector2i newPosition) { position = newPosition; }

Color Piece::getColor() const { return color; }

// Load texture
bool Piece::loadTexture(const std::string& filename) {
    if (!texture.loadFromFile(filename)) {
        std::cerr << "Error loading texture: " << filename << std::endl;
        return false;
    }
    sprite.setTexture(texture);
    return true;
}



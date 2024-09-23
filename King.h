#pragma once
#include "Piece.h"

// King piece class
class King : public Piece {
public:
    King(Color color, sf::Vector2i position);

    bool isValidMove(sf::Vector2i newPosition, sf::Vector2i position, Piece* targetPiece) const override;
};
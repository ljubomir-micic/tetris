#pragma once
#include <iostream>

#define SQUARE_PIECE "00000001100011"
#define I_PIECE "000000000001111"
#define L_PIECE "0000000100001000011"
#define LM_PIECE "000000010000100011"
#define T_PIECE "000000010000110001"
#define N_PIECE "000000001000110001"
#define NM_PIECE "000000100001100001"

class Piece {
    int** matrix;
    int mapDim, colorHex;
public:
    int x, y;

    Piece(const char*);
    Piece(const Piece&);
    ~Piece();
    inline int GetDim() { return this->mapDim; }
    inline bool GetBlock(int x, int y) { return this->matrix[x][y]; }
    void Rotate(bool toLeft = false);
    friend std::ostream& operator<<(std::ostream&, const Piece&);
};


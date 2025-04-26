#include "board.h"

Board::Board() {
    this->pieces = new List<Piece*>();
    InitBoard();
}

Board::~Board() {
    if (pieces != nullptr)
        delete pieces;
    if (lastPiece != nullptr)
        delete lastPiece;
}

void Board::InitBoard() {
    for (int i = 0; i < BOARD_W; i++)
        for (int j = 0; j < BOARD_H; j++)
            this->field[i][j] = POS_FREE;
}

void Board::StorePiece(int x, int y, Piece& piece) {
    for (int i = x, i2 = 0; i < x + piece.GetDim(); i++, i2++)
        for (int j = y, j2 = 0; j < y + piece.GetDim(); j++, j2++)
            if (piece.GetBlock(i2, j2))
                this->field[x][y] = POS_FULL;
}

void Board::Append(Piece* piece) {
    pieces->Add(piece);
}

void Board::DeleteLine(int y) {
    for (int i = y; i > 0; i--)
        for (int j = 0; j < BOARD_W; j++)
            this->field[j][i] = this->field[j][i-1];
}

void Board::DeletePossibleLines() {
    for (int i = 0; i < BOARD_W; i++)
        for (int j = 0; j < BOARD_H; j++) {
            if (this->field[i][j]) break;
            if (i == BOARD_W-1) DeleteLine(j);
        }
}

bool Board::IsPossibleMovement(int px, int py, Piece& piece) {
    // TODO: Add a functionality
    return true;
}

bool Board::IsGameOver() {
    for (int i = 0; i < BOARD_W; i++)
        if (this->field[i][0]) return true;
    return false;
}


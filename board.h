#pragma once
#include "list.h"
#include "piece.h"

#define BOARD_W 10
#define BOARD_H 20

#define POS_FREE 0
#define POS_FULL 1

class Board {
    bool field[BOARD_W][BOARD_H];
    List<Piece*>* pieces;
    Piece* lastPiece;

    void DeleteLine(int y);
    void InitBoard();
public:
    Board();
    ~Board();
    void Append(Piece*);
    void StorePiece(int, int, Piece&);
    inline bool IsFreeBlock(int x, int y) { return !field[x][y]; }
    bool IsPossibleMovement(int, int, Piece&);
    bool IsPossibleRotation(Piece&, bool);
    void UpdatePiece(Piece*);
    void UpdateResult();
    void DeletePossibleLines();
    bool IsGameOver();
};


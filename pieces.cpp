#include "piece.h"

Piece** pieces = new Piece*[7];

void initPieces() {
	pieces[0] = new Piece(SQUARE_PIECE);
	pieces[1] = new Piece(I_PIECE);
	pieces[2] = new Piece(L_PIECE);
	pieces[3] = new Piece(LM_PIECE);
	pieces[4] = new Piece(T_PIECE);
	pieces[5] = new Piece(N_PIECE);
	pieces[6] = new Piece(NM_PIECE);
}

void deinitPieces() {
	for (int i = 0; i < 7; i++)
		delete pieces[i];
	delete[] pieces;
}

int main() {
	initPieces();
	pieces[0]->rotate(true);
	for (int i = 0; i < 7; i++) {
		std::cout << *(pieces[i]) << '\n';
	}
	deinitPieces();
    return 0;
}


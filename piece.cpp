#include "piece.h"
#include "basic.h"
#include <cmath>
#include <ctime>
#include <cstring>

Piece::Piece(const char* map) {
    this->mapDim = 5;
    srand(time(NULL));
    this->colorHex = ((rand()%256)*256+(rand()%256))*256 + rand()%256;
    int mapSize = strlen(map);
    int i;
    this->matrix = new int*[this->mapDim]();
    for (i = 0; i < this->mapDim; i++) this->matrix[i] = new int[this->mapDim]();
    i = 0;
    while (i < mapDim * mapDim) {
        this->matrix[i/5][i%5] = (i < mapSize ? (int) (map[i] - '0') : 0);
        i++;
    }
}

Piece::Piece(const Piece& piece) {
    this->mapDim = 5;
    this->colorHex = piece.colorHex;
    this->matrix = new int*[this->mapDim]();
    for (int i = 0; i < this->mapDim; i++) { this->matrix[i] = new int[this->mapDim](); }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            this->matrix[i][j] = piece.matrix[i][j];
}

Piece::~Piece() {
    for (int i = 0; i < this->mapDim; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void Piece::Rotate(bool toLeft) {
    for (int i = 0; i < (int) floor((double)mapDim/2); i++)
        for (int j = 0; j < mapDim; j++) if (!toLeft)
            ZameniElemente(matrix[i][j], matrix[mapDim-1-i][j]);
	    else
	        ZameniElemente(matrix[j][i], matrix[j][mapDim-1-i]);

    for (int i = 0; i < mapDim; i++)
        for (int j = i + 1; j < mapDim; j++)
            if (i != j)
                ZameniElemente(matrix[i][j], matrix[j][i]);
}

std::ostream& operator<<(std::ostream& izlaz, const Piece& deo) {
	for (int i = 0; i < deo.mapDim; i++) {
		for (int j = 0; j < deo.mapDim; j++)
			izlaz << (deo.matrix[i][j]==1 ? '@' : ' ') << ' ';
		izlaz << '\n';
	}
	return izlaz;
}


#pragma once

void ZameniElemente(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int MultiplyColors(int& color1, int& color2) {
    return (int) (((((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF)) >> 1) | ((((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF)) >> 1) | ((((color1) & 0xFF) + ((color2) & 0xFF)) >> 1));
}


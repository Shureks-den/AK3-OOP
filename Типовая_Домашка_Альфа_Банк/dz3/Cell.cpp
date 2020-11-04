//
// Created by Alexander on 12.10.2020.
//
#include "Cell.h"

Cell:: Cell(int rows, int cols) {
    height = rows;
    width = cols;
    field = new int* [height+2];
    for (int i = 0; i < height+2; i++) {
        field[i] = new int [width+2];
    }
}
Cell::~Cell() {
    for (size_t i = 0; i < height+2; i++) {
        delete[] old_field[i];
        delete[] field[i];
    }
    delete[] old_field;
    delete[] field;
    std::cout<<"Cell has been deleted"<<std::endl;
} // деструктор
void Cell :: transform (int k) {
    for (int x = 0; x < k; x++) {
        field_memorise();
        for (int i = 1; i < height + 1; i++) {
            for (int j = 1; j < width + 1; j++) {
                if (check(i,j) >= 2) {
                    this->field[i][j] = 2;
                } else if (check(i,j) == 1) {
                    this->field[i][j] = 1;
                } else {
                    this->field[i][j] = 0;
                }
            }
        }
        std::cout<< x+2 <<" iteration"<< std::endl;
        print_cell();
    }
}
void Cell :: print_cell() {
    for (int i = 1; i < height+1; i++) {
        for (int j = 1; j < width+1; j++) {
            std::cout << field[i][j] << "   ";
        }
        std::cout<<std::endl;
    }
    _sleep(1000);
    for (int i = 0; i < 3; i++) {
        std::cout<<std::endl;
    }
}
void Cell :: gen_rand_cell() {
    srand(time(nullptr));
    for (int i = 0; i < height+2; i++) {
        for (int j = 0; j < width+2; j++) {
            if (i==0 || j == 0 || i == height+1 || j ==width+1) {
                field[i][j]=0;
            }
            else {
                field[i][j] = rand() % 3;
            }
        }
    }
}
int Cell :: check (int i, int j) {
    int transform =0;
    if ((this->old_field[i - 1][j] == 1 || this->old_field[i - 1][j] == 1) ||
        (this->old_field[i - 1][j] == 2 || this->old_field[i - 1][j] == 2)) {
        transform++;
    }
    if ((this->old_field[i + 1][j] == 1 || this->old_field[i + 1][j] == 1) ||
        (this->old_field[i + 1][j] == 2 || this->old_field[i + 1][j] == 2)) {
        transform++;
    }
    if ((this->old_field[i][j - 1] == 1 || this->old_field[i][j - 1] == 1) ||
        (this->old_field[i][j - 1] == 2 || this->old_field[i][j - 1] == 2)) {
        transform++;
    }
    if ((this->old_field[i][j + 1] == 1 || this->old_field[i][j + 1] == 1) ||
        (this->old_field[i][j + 1] == 2 || this->old_field[i][j + 1] == 2)) {
        transform++;
    }
    return transform;
}
void Cell::field_memorise() {
    old_field = new int* [height+2];
    for (int i = 0; i < height+2; i++) {
        old_field[i] = new int [width+2];
    }
    for (int i = 0; i < height + 2; i++) {
        for (int j = 0; j < width + 2; j++) {
            old_field[i][j] = field[i][j];
        }
    }
}

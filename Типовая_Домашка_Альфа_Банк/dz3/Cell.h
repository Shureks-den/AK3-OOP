//
// Created by Alexander on 12.10.2020.
//

#ifndef UNTITLED3_CELL_H
#define UNTITLED3_CELL_H

#include <iostream>
#include <ctime>
#include <unistd.h>
#define msleep(x) usleep(x * 1000)

class Cell {
public:
    Cell (int rows, int cols);
    ~Cell (); // деструктор
    void transform (int k);
    void print_cell() ;
    void gen_rand_cell();
private:
    int check (int i, int j);
    void field_memorise();
    int ** field;
    int height; // число строк
    int width;// число столбцов
    int ** old_field;
};


#endif //UNTITLED3_CELL_H

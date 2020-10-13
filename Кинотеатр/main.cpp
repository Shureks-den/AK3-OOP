#include <iostream>
#include <ctime>
#include <cstdlib>


class Cinema{
public:
    Cinema(int row, int col){
        rows = row;
        cols = col;
        cinema = new int * [rows];
        for (int i; i<rows; i++ )
            cinema[i] = new int[cols];
        for (int i = 0; i<rows; i++)
            for (int j = 0; j<cols; j++)
                cinema[i][j]=rand()%2;
    }
    ~Cinema(){};
    void free_sits(int needed){
        int free_sits_in_a_row_in_the_cinema=0;
        int variants=0;
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++)
                if (cinema[i][j] == 1) {
                    free_sits_in_a_row_in_the_cinema++;
                    if (free_sits_in_a_row_in_the_cinema >= needed)
                        variants++;
                } else free_sits_in_a_row_in_the_cinema = 0;
            std::cout<<"There are "<< variants << " sits positions by " << needed << " in row " << i+1
            <<std::endl;
            variants=0;
        }

    }
   void print_cin(){
       for (int i = 0; i<rows; i++) {
           for (int j = 0; j < cols; j++)
               std::cout << cinema[i][j]<<"  ";
           std::cout<<std::endl;
       }
   }
private:
    int rows;
    int cols;
    int** cinema;

};
int main() {
    srand(time(NULL));
    int rows;
    int need;
    int cols;
    std:: cin >> rows;
    std::cin >> cols;
    Cinema *kinozal1 = new Cinema(rows, cols);
    kinozal1->print_cin();
    std::cout<<"Input desire sits positions";
    std::cin>> need;
    kinozal1->free_sits(need);
    delete kinozal1;
    return 0;
}

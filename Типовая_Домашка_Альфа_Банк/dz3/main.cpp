#include "Cell.h"
/*
 * 0 - неактивна
 * 1 - нестабильна
 * 2 - стабильна
 */

int main() {
    int k;
    std::cin>>k;
    int n;
    int m;
    std::cin>>n >> m;
    Cell a(n,m);
    a.gen_rand_cell();
    std::cout<<"First iteration"<< std::endl;
    a.print_cell();
    a.transform(k-1);
}

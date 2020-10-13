#include <iostream>
using std::string;

class The_doors{
public:
    The_doors(){};
    
    void set_info(int l, int h, int w, int pr, string name_in, string brand_in){
        length = l;
        height = h;
        width = w;
        price = pr;
        name = name_in;
        brand = brand_in;
    }
    ~The_doors(){};
    void print_info(){
        std::cout<<"Door name: "<< name << ", made by: " << brand <<", length is "<< length
        <<"cm, height is " << height << "cm, width is " << width<< "cm" << " price is "
        <<price<<std::endl;
    }
private:
    float length;
    float height;
    float width;
    string name;
    string brand;
    int price;
};

int main() {
    The_doors* all_doors = new The_doors[3];
    /*The_doors* first_door = new The_doors(50, 240, 10,1000,"Guardian", "A");
    The_doors* second_door = new The_doors(45, 250, 8,8000, "NPO_Dver'", "B");
    The_doors* third_door = new The_doors (6,6,6, 666, "TU ne Proidesh", "A");
    first_door->print_info();
    second_door->print_info();
    third_door->print_info();
     */

    all_doors[0].set_info(50, 240, 10,1000,"Guardian", "A");
    all_doors[1].set_info(45, 250, 8,8000, "NPO_Dver'", "B");
    all_doors[2].set_info(6,6,6, 666, "TU ne Proidesh", "A");
    for(int i = 0; i<3; i++)
        all_doors[i].print_info();
    return 0;
}

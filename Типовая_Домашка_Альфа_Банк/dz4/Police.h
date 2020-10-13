//
// Created by Alexander on 12.10.2020.
//

#ifndef DZ1_4_POLICE_H
#define DZ1_4_POLICE_H

#include <iostream>
#include <unistd.h>
#define msleep(x) usleep(x * 1000)
#define World_Size  9
#define center 4
using std::cout;
using std::endl;

class Police {
public:
    Police();
    ~Police();
    void print_world ();
    void full_route();
private:
    char city[World_Size][World_Size];
    int steps_x_left(int now_x, int now_y, int edge, char ride_num);
    int steps_y_up(int now_x, int now_y, int edge, char ride_num);
    int steps_x_right(int now_x, int now_y, int edge, char ride_num);
    int steps_y_down(int now_x, int now_y, int edge, char ride_num);
    void first_ride();
    void second_ride();
    void third_ride();
    void fourth_ride();
    void fifth_ride();
};


#endif //DZ1_4_POLICE_H

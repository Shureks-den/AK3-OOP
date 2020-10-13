//
// Created by Alexander on 12.10.2020.
//
#include "Police.h"

Police::Police() {
    for (int i = 0; i < World_Size; i++) {
        for (int j = 0; j < World_Size; j++) {
            city[i][j]='-';
        }
    }
    city[center][center] = '^';
    print_world();
}
Police::~Police(){}
void Police::print_world()  {
    for (int i = 0; i < World_Size; i++) {
        for (int j = 0; j < World_Size; j++) {
            cout<<city[i][j]<<"   ";
        }
        cout<<endl;
    }
    for (int i =0; i<9; i++) {
        cout<<endl;
    }
    msleep(1000);
}
void Police:: full_route() {
    first_ride();
    second_ride();
    third_ride();
    fourth_ride();
    fifth_ride();
}
int Police:: steps_x_left(int now_x, int now_y, int edge, char ride_num) {
    while(now_x-->edge) {
        city[now_y][now_x]=ride_num;
        print_world();
    }
    return edge;
}
int Police::steps_y_up(int now_x, int now_y, int edge, char ride_num) {
    while(now_y-->edge) {
        city[now_y][now_x]=ride_num;
        print_world();
    }
    return edge;
}
int Police::steps_x_right(int now_x, int now_y, int edge, char ride_num) {
    while(now_x++<edge) {
        city[now_y][now_x]=ride_num;
        print_world();
    }
    return edge;
}
int Police::steps_y_down(int now_x, int now_y, int edge, char ride_num) {
    while(now_y++<edge) {
        city[now_y][now_x]=ride_num;
        print_world();
    }
    return edge;
}
void Police::first_ride() {
    int nowX=center+1;
    int nowY=center+1;
    nowX= steps_x_left(nowX, nowY, 0, '1');
    nowY= steps_y_up(nowX, nowY, 0, '1');
    nowX= steps_x_right(nowX, nowY, 5, '1');
    nowY= steps_y_down(nowX, nowY, 2, '1');
    nowX= steps_x_left(nowX, nowY, center, '1');
    nowY= steps_y_down(nowX, nowY, 3, '1');
    nowY= steps_y_up(nowX, nowY, center, '1');
}
void Police::second_ride() {
    int nowX=center;
    int nowY=center;
    nowX= steps_x_left(nowX, nowY, 1, '2');;
    nowY= steps_y_up(nowX, nowY, 1, '2');
    nowX= steps_x_right(nowX, nowY, 2, '2');
    nowY= steps_y_down(nowX, nowY, 3, '2');
    nowX= steps_x_right(nowX, nowY, 3, '2');
    nowY= steps_y_up(nowX, nowY, 1, '2');
    nowX= steps_x_right(nowX, nowY, 6, '2');
    nowY= steps_y_down(nowX, nowY, 3, '2');
    nowX= steps_x_left(nowX, nowY, 5, '2');
    nowY= steps_y_down(nowX, nowY, center, '2');

}
void Police::third_ride() {
    int nowX=center;
    int nowY=center;
    nowX= steps_x_right(nowX, nowY, 7, '3');
    nowY= steps_y_up(nowX, nowY, 0, '3');
    nowX= steps_x_left(nowX, nowY, 6, '3');
    nowX= steps_x_right(nowX, nowY, 8, '3');
    nowY= steps_y_down(nowX, nowY, 5, '3');
    nowX= steps_x_left(nowX, nowY, center, '3');
    nowY= steps_y_down(nowX, nowY, center, '3');

}
void Police::fourth_ride() {
    int nowX=center;
    int nowY=center;
    nowY= steps_y_down(nowX, nowY, 6, '4');
    nowX= steps_x_left(nowX, nowY, 0, '4');
    nowY= steps_y_down(nowX, nowY, 8, '4');
    nowX= steps_x_right(nowX, nowY, 1, '4');
    nowY= steps_y_up(nowX, nowY, 7, '4');
    nowX= steps_x_right(nowX, nowY, 2, '4');
    nowY= steps_y_down(nowX, nowY, 8, '4');
    nowX= steps_x_right(nowX, nowY, 3, '4');
    nowY= steps_y_up(nowX, nowY, 7, '4');
    nowX= steps_x_right(nowX, nowY, center, '4');
    nowY= steps_y_down(nowX, nowY, 8, '4');
}
void Police::fifth_ride() {
    int nowX=center;
    int nowY=center;
    nowY= steps_y_down(nowX, nowY, 6, '5');
    nowX= steps_x_right(nowX, nowY, 8, '5');
    nowY= steps_y_down(nowX, nowY, 8, '5');
    nowX= steps_x_left(nowX, nowY, 7, '5');
    nowY= steps_y_up(nowX, nowY, 7, '5');
    nowX= steps_x_left(nowX, nowY, 6, '5');
    nowY= steps_y_down(nowX, nowY, 8, '5');
    nowX= steps_x_left(nowX, nowY, 5, '5');
    nowY= steps_y_down(nowX, nowY, 8, '5');
    nowY= steps_y_up(nowX, nowY, 6, '5');
    nowX= steps_x_left(nowX, nowY, center, '5');
}


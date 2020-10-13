//
// Created by zennoma on 08.10.2020.
//
#include "lucky_day.h"

// 366 - дней
// начинаем с четверга, нужны вторники, последняя цифра недели и дня
int year_days = 366;
int * lucky () {
    int j=0;
    int * lucky_days = new int [50];
    int week_counter = 1;
    for (int i = 0; i < year_days; i++) {
        if ( (i+3) % 7 == 0) {
            week_counter++;
        }
       if ( ((i+1) % 10) == ( week_counter % 10) && (i+2) % 7 ==0) {
           lucky_days[j++]=i+1;
            std::cout<< i+1 << " ";
        }
    }
    std::cout<<std::endl;
    return lucky_days;
}

void which_month(int* lucky_days) {
    int days_in_months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int j = 0;
    for (int i = 0; i < 11; i++) {
        while (lucky_days[i] > days_in_months[j]) {
            lucky_days[i] -= days_in_months[j];
            j++;
        }
        std::cout << j+1 << "  ";
        j=0;
    }
}
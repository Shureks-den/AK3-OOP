#ifndef UNTITLED3_TEXT_H
#define UNTITLED3_TEXT_H
#include <iostream>
#include <fstream>
using std::string;
using std::cin;
using std::cout;
class Text{
public:
    Text();
    ~Text();
    int search_dist();
    int get_dist();
    void close_file();
    void set_word1();
    void set_word2();
    void set_filename(string filename);

private:
    int pos1;
    int pos2;
    int dist;
    FILE* fin;
    string word1;
    string word2;
    string filename_;
};
#endif //UNTITLED3_TEXT_H

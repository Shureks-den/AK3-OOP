#include <string>
#include "text.h"
using std::string;
using std::cin;
using std::cout;
int main() {
    string filename = "sample.txt";
    Text* sample=new Text;
    sample->set_filename(filename);
    sample->set_word1();
    sample->set_word2();
    sample->search_dist();
    sample->get_dist();
    sample->close_file();
    delete sample;
}

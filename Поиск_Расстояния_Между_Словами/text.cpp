#include "text.h"
    Text::Text(){
        pos1=0;
        pos2=0;
        dist=-1;
        fin = NULL;
    };
    Text::~Text(){
        cout<<"class has been deleted"<<std::endl;
    }
    int Text::search_dist(){
        string buff;
        int pos=1;
        std::ifstream fin (filename_);
        while(true) {
            fin>>buff;
            if (!fin) break;
            if (buff == word1){
                pos1=pos;
                dist = -1;
            }
            if(buff == word2 ){
                pos2=pos;
                if(dist<pos2-pos1 && dist!=-1) break;
                dist = pos2-pos1-1;
            }
            pos++;
        }
    }
    int Text:: get_dist(){
        cout<<"distance between "<<word1<<" and "<<word2<<" is "<<dist<<std::endl;
    }
    void Text::close_file(){
        std::fclose(fin);
        cout<<"file connection was closed"<<std::endl;
    }
    void Text::set_word1(){
        cout<<"Input first word"<<std::endl;
        cin>>word1;
    }
    void Text::set_word2(){
        cout<<"Input second word"<<std::endl;
        cin>>word2;
    }
    void Text::set_filename(string filename){
        filename_=filename;
    }




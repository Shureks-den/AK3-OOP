#include <iostream>
#include <fstream>
using  std::string;

class Student{
public:

    Student()= default;  //
    void set_info(string info){
        int i = 0;
        int k=0;
        while(info[i] != ' '){
            surname[k++]=info[i++];
        }
        i++;
        k=0;
        while(info[i]!=' '){
            name[k++]=info[i++];
        }
        i++;
        k=0;
        while(info[i]!=' '){
            group[k++]=info[i++];
        }
        k=0;
        i++;
        for(k;k<5;k++)
        {
            marks[k]=info[i]-'0';
            i+=2;
        }
    }

    void get_surname() {
        std::cout <<surname << " " << name << " "<< group<<" ";
        for (int j=0; j<5; j++)
            std::cout<<marks[j];
        std::cout<<std::endl;
    }

    void get_avrg(){
        float sum = 0;
        for (int i = 0; i<5; i++)
            sum+=marks[i];
        average = sum/5;
        std::cout<<"Average is "<< average<<std::endl;
    }
    ~Student()= default;
private:

    char name[10];
    char surname[20];
    char group[20];
    int marks[5];
    float average;
};

int main() {
    int sCount = 0;
    auto* bomonka = new Student[20];
    string info;
    std::ifstream F ("studentsList.txt");
    if(F){
        while(std::getline(F, info)){
            bomonka[sCount].set_info(info);
            sCount++;
        }
        F.close();
        std::cout<<std::endl<<"Number of students is " <<  sCount<< std::endl;
        for(int i = 0; i<sCount; i++)
        {
            bomonka[i].get_surname();
            bomonka[i].get_avrg();
        }
    }
    else std::cout<<"File is not found";
    return 0;
}
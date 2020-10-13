#include <iostream>
#include <vector>
#include <fstream>
using std::vector;
using std::string;
using std::cout;

class Complex{
public:
    Complex(){
        real_ = 0;
        imaginary_ = 0;
    };

    Complex(int real, int imaginary) {
        real_=real;
        imaginary_=imaginary;
    }
    void set_real(int real){
        real_ =real ;
    }
    void set_img(int imaginary){
        imaginary_ =imaginary;
    }
    ~Complex(){};
    void print(){
        cout<<real_<<" + "<<imaginary_<<"i"<<std::endl;
    }
    Complex operator + (Complex &other) {
      return  Complex(this->real_+other.real_,
                      this->imaginary_ + other.imaginary_);
    }
    Complex operator * (Complex &other) {
        return Complex(this->real_ * other.real_ - this->imaginary_ * other.imaginary_,
                       this->imaginary_ * other.real_ + this->real_*other.imaginary_);
    }
private:
    int real_;
    int imaginary_;

};
int main() {
    Complex c1;
    c1.set_real(5);
    c1.set_img(2);
    Complex c2;
    c2.set_real(3);
    c2.set_img(2);
    Complex c3;
    c3=c1+c2;
    c1.print();
    c2.print();
    c3.print();
    c3=c1*c2;
    c3.print();
    return 0;
}

#include <iostream>
using namespace std;
class Fruit{
public:
    Fruit(){
        cout<<"FRUIT HAS BEEN CREATED"<<endl;
    }
    ~Fruit(){
        cout<<"FRUIT HAS BEEN DESTROYED"<<endl;
    }
private:
    string name;
    int price[5];
};
class Apple:public Fruit{
public:
    Apple(){
        cout<<"APPLE HAS BEEN CREATED"<<endl;
    }
    string name;
    ~Apple(){
        cout<<"APPLE HAS BEEN DESTROYED"<<endl;
    }
};
int main() {
  cout << "Hello, World!" << std::endl;
  Apple * A = new Apple;
  delete A;
    return 0;
}

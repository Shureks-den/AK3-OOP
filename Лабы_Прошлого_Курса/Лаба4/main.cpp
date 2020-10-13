#include <iostream>
class C{
public:
    C(int first, int second){
        N=first;
        K=second;
    }
    ~C(){
        std::cout<<"Deleted C"<<std::endl;
    }
protected:
    int N;
    int K;
};
class E: public C{
public:
    E(int first, int second): C(int(first) , int (second)){};
    void get_info(){
        std::cout<<"N="<<N<<" K="<<K<<std::endl;
    }
    ~E(){std::cout<<"deleted E";}
};
class D: public C{
public:
    D(int first, int second): C(int(first) , int (second)){};
    virtual void foo(){
        for (int i =0; i<K;i++ )
            std::cout<<N;
    }
};
class F: public D{
public:
    F(int first, int second): D(int(first) , int (second)){};
     void foo() override {
        for (int i =0; i<N;i++ )
            std::cout<<K<<std::endl;
    }
};
void test(){
    E first(2,5);
    first.get_info();
    D second(5,6);
    second.foo();
    F third(67,82);
    third.foo();
}
int main() {
    test();
    return 0;
}

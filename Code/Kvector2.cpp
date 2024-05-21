#include<iostream>

using namespace std;

class Kvector{

    int *m;

    int len;

public:

    static int total_len;

    Kvector(int sz = 0, int value = 0);

    Kvector(const Kvector& v);

    ~Kvector(){
        
        total_len -= len;

        delete[] m;


    }

    void print()const{

        for (int j=0; j<len; j++) cout << m[j] << " " ;
        cout << endl;
        }


    void clear(){

        delete[] m;

        m = nullptr;

        total_len -= len;

        len = 0;

    }

    int size(){ return len;}

};

int Kvector::total_len = 0;

Kvector::Kvector(int sz, int value){

    len = sz;

    total_len += len;

    if (sz == 0) {

        m = nullptr;

        return;

    }

    m = new int[sz];

    for(int j=0; j<sz; j++){

        m[j] = value;

    }

}

Kvector::Kvector(const Kvector& v){


    len = v.len;

    total_len += len;

    m = new int[len];

    for(int j=0; j<len; j++){

    m[j] = v.m[j];

    }

}

int main(){

    Kvector v1(3); v1.print();

    const Kvector v2(2, 9); v2.print();

    Kvector v3(v2); v3.print();

    Kvector *p = new Kvector(3,10); p->print();

    cout << "total length :" << Kvector::total_len << endl;

    delete p;

    cout << "total length after deletion : " << Kvector::total_len << endl;

    return 0;

}
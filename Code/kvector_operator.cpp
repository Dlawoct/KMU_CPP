#include <iostream>

using namespace std;

class Kvector {
    int *m;
    int len;
public:
    Kvector(int sz=0, int value = 0): len(sz) {
        m = new int[sz];
        if(!sz) m = NULL;
        for (int i = 0; i < sz; i++) {
            m[i] = value;
        }
        len = sz;
    }
    Kvector(const Kvector& v) {
        m = new int[v.len];
        for (int i = 0; i < v.len; i++) {
            m[i] = v.m[i];  
        }
        len = v.len;
    }
    ~Kvector() {
        delete[] m;
    }
    void print() const {
        for (int i = 0; i < len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear() {
        delete[] m;
        m = NULL;
        len = 0;
    }
    int size() const {return len;}

    Kvector& operator=(const Kvector& c);
    friend bool operator==(const Kvector& c, const Kvector& d);
    friend bool operator!=(const Kvector& c, const Kvector& d);
    int& operator[](int idx);
    friend ostream& operator<<(ostream& os, const Kvector& c);
};

Kvector& Kvector::operator=(const Kvector& c) {
    m = new int[c.len];
    for (int i = 0; i < c.len; i++) {
        m[i] = c.m[i];  
    }
    len = c.len;
    return *this;
}
bool operator==(const Kvector& c, const Kvector& d) {
    return ((c.len == d.len) && (*c.m == *d.m));
}
bool operator!=(const Kvector& c, const Kvector& d) {
    return !(c==d);
}
int& Kvector::operator[](int idx) {
    return m[idx];
}
ostream& operator<<(ostream& os, const Kvector& c) {
    for (int i = 0; i < c.len; i++) os << c.m[i] << " ";
    return os;
}

int main() {
    Kvector v1(3);  v1.print();
    Kvector v2(2,9);  v2.print();
    Kvector v3(v2);  v3.print();
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    cout << "v1 : " << v1 << "v2 : " << v2 << "v3 : " << v3 << endl;
    return 0;
}
#ifndef __KVECTOR__
#define __KVECTOR__
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Kvector {
protected:
    T *m;
    int len;
public:
    Kvector(int sz = 0, T value = T()): len(sz) {
        if (!sz) { 
            m = nullptr; 
            return; 
        }
        m = new T[sz];
        for (int i = 0; i < sz; i++) m[i] = value;
    }
    
    Kvector(const Kvector& v): len(v.len) {
        if (!len) { 
            m = nullptr; 
            return; 
        }
        m = new T[len];
        for (int i = 0; i < len; i++) m[i] = v.m[i];
    }
    
    virtual ~Kvector() {
        delete[] m;
    }
    
    virtual void print() const { 
        cout << "Kvector<T>\n"; 
    }
    
    void clear() { 
        delete[] m; 
        m = nullptr; 
        len = 0;
    }
    
    int size() const { 
        return len; 
    }
    
    Kvector<T>& operator=(const Kvector& v) {
        if (this == &v) return *this;  
        delete[] m;
        len = v.len;
        if (len) {
            m = new T[len];
            for (int i = 0; i < len; i++) m[i] = v.m[i];
        } else {
            m = nullptr;
        }
        return *this;
    }
    
    T& operator[](int idx) { 
        return m[idx]; 
    }
    
    const T& operator[](int idx) const { 
        return m[idx]; 
    }
    
    T sum() const {
        if (len == 0) return T();
        T s = m[0];
        for (int i = 1; i < len; i++) s += m[i];
        return s;
    }
    
    friend bool operator==(const Kvector<T>& v, const Kvector<T>& w) {
        if (v.len != w.len) return false;
        for (int i = 0; i < v.len; i++) {
            if (v.m[i] != w.m[i]) return false;
        }
        return true;
    }
    
    friend bool operator!=(const Kvector<T>& v, const Kvector<T>& w) {
        return !(v == w);
    }
    
    friend ostream& operator<<(ostream& os, const Kvector<T>& v) {
        for (int i = 0; i < v.len; i++) os << v.m[i] << " ";
        return os;
    }
};

#endif

#ifndef TEAM_H
#define TEAM_H

class Team {
    string name;
    int wins;
public:
    Team(const string& n = "teamX", int w = 0): name(n), wins(w) {}
    
    Team& operator+=(const Team& rhs) {
        wins += rhs.wins;
        return *this;
    }
    
    friend Team operator+(Team a, const Team& b) {
        a += b;
        return a;
    }
    
    friend bool operator==(const Team& a, const Team& b) {
        return (a.name == b.name);
    }
    
    friend bool operator!=(const Team& a, const Team& b) {
        return !(a == b);
    }
    
    friend ostream& operator<<(ostream& os, const Team& a) {
        os << a.name << "(" << a.wins << ")";
        return os;
    }
};

#endif

int main() {
    Kvector<int> v1(3, 0);
    cout << "v1 : " << v1 << endl;
    cout << "v1.sum() = " << v1.sum() << endl;

    Kvector<int*> v2(5, nullptr);
    int a[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++) v2[i] = &a[i];
    for (int i = 0; i < 5; i++) cout << *(v2[i]) << " ";
    cout << endl;

    Kvector<Team> league1(2, Team()), league2(2, Team());
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    league1[0] = Team("Twins", 10);
    league1[1] = Team("Bears", 5);
    league2[0] = Team("Twins", 80);
    league2[1] = Team("Bears", 81);
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    cout << "league1 == league2 : " << (league1 == league2) << endl;
    league2[0] = Team("Bulls", 80);
    league2[1] = Team("Warriors", 81);
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    cout << "league1.sum() = " << league1.sum() << endl;
    cout << "league2.sum() = " << league2.sum() << endl;

    return 0;
}

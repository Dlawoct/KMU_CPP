#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "[" << p.first << "]" << p.second;
    return os;
}

template <class T>
void print_container(const T& container, string s = "") {
    cout << s << "(" << container.size() << ") ";
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    char a[10] = {'c', 'a', 'x', 'a', 'c', 'b', 'x', 'c', 'b', 'y'};

    // 컨테이너 생성 및 데이터 삽입
    vector<char> v(a, a + 10);
    deque<char> dq(a, a + 10);
    list<char> li(a, a + 10);
    set<char> s(a, a + 10);
    multiset<char> ss(a, a + 10);

    map<int, char> m;
    multimap<int, char> mm;
    for (int i = 0; i < 10; ++i) {
        m[i] = a[i];
        mm.insert(make_pair(i, a[i]));
    }

    // 출력
    print_container(v, "v= ");
    print_container(dq, "dq= ");
    print_container(li, "li= ");
    print_container(s, "s= ");
    print_container(ss, "ss= ");
    print_container(m, "m= ");
    print_container(mm, "mm= ");

    return 0;
}

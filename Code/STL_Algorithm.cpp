#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

// Team 클래스 정의
class Team {
public:
    string name;
    int wins;

    Team(string n, int w) : name(n), wins(w) {}

    friend ostream& operator<<(ostream& os, const Team& team) {
        os << team.name << "(" << team.wins << ")";
        return os;
    }
};

// 컨테이너 출력 함수
template <class T>
void print_container(const T& container, string s="") {
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for (; it != container.end(); it++) cout << *it << " ";
    cout << endl;
}

// 이름 순으로 정렬하는 함수
bool teamCmp_byName (const Team& a, const Team& b) {
    return a.name < b.name;
}

// 승수 순으로 정렬하는 함수 객체
struct TeamCmp_byVictory {
    bool operator() (const Team& a, const Team& b) const {
        return a.wins < b.wins;
    }
};

int main() {
    Team t[] = {Team("Bulls", 7), Team("Warriors", 5), Team("Spurs", 2)};
    
    // 1-1: Team 배열을 내용으로 하는 vector<Team> v을 만들고 출력
    vector<Team> v(t, t + 3);
    print_container(v, "1.v=");
    
    // 1-2: v을 이름 순으로 정렬하고 다시 출력
    sort(v.begin(), v.end(), teamCmp_byName);
    print_container(v, "2.v=");
    
    // 1-3: v을 승수 오름차순으로 정렬하고 출력
    sort(v.begin(), v.end(), TeamCmp_byVictory());
    print_container(v, "3.v=");
    
    // 1-4: v에 새로운 팀("Lakers", 3)을 맨 앞에 삽입하고 다시 출력
    v.insert(v.begin(), Team("Lakers", 3));
    print_container(v, "4.v=");
    
    // 2-1: Team 배열을 내용으로 하는 set<Team> s을 만들고 출력 (승수 순서로 정렬)
    set<Team, TeamCmp_byVictory> s(t, t + 3);
    print_container(s, "1.s=");
    
    // 2-2: s에 새로운 팀("Lakers", 3)을 삽입하고 다시 출력
    s.insert(Team("Lakers", 3));
    print_container(s, "2.s=");
    
    // 3-1: Team 배열을 내용으로 하는 priority_queue<Team> p를 만듦 (승수가 클수록 우선 순위가 높게)
    priority_queue<Team, vector<Team>, TeamCmp_byVictory> p(t, t + 3);
    
    // 3-2: p에 새로운 팀("Lakers", 3)을 push
    p.push(Team("Lakers", 3));
    
    // 3-3: top(), pop() 함수를 사용하여 모든 원소를 출력
    cout << "priority queue: ";
    while (!p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        set<long long> s;
        s.insert(1);
        long long x;
        for (int i = 0; i < k; ++i) {
            x = *s.begin();
            s.erase(s.begin());
            s.insert(x * 2);
            s.insert(x * 3);
            s.insert(x * 5);
        }
        cout << x << endl;
    }

    return 0;
}

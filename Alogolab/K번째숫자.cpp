#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    int t, tmp;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        num = "1";
        tmp = 1;

        while(num.length() < n){ //길이 전 까지 돌지만, 한 번 더 실행하게 되어있음
            tmp++; //1부터 1씩 더하기
            num += to_string(tmp); //"1"부터 1씩 문자열 추가 123456789 + 10
            }

    cout << num[n - 1] << endl;
    
    }
}
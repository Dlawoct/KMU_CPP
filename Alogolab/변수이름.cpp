#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        int ans = 1, num;
        cin >> s;
        num = s.length();

        for (int i =0;i<num;i++){
            if ('0'<= s[0] && s[0]<='9'){ //맨 앞자리가 숫자인 경우
                ans = 0;
                break;
            }

            else if(!( (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z')) || s[i] == '_' || ('0' <= s[i] && s[i] <= '9'))){ //영어 or _ or 숫자 인지
                ans = 0;
                break;
            }
        }
    cout << ans << endl;
    }
}
//숫자로 시작 x, _ 제외한 문자 입력 x

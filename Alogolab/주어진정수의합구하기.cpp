#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i =0; i<t; i++){
        int count, sum=0;
        cin >> count;
        for(int j=0; j<count; j++){
            int num;
            cin >> num; //cin은 공백을 기준으로 입력을 받음.
            sum += num;
        }
    cout << sum << endl;
    }
}
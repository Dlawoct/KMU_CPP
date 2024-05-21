#include <iostream>
using namespace std;

int main(){
    int t, n;
    cin >> t;

    for(int i=0; i<t; i++){
       cin >> n;
       int sum = 1;
       
       for(int j=0; j<n; j++){
        int a;
        cin >> a;
        a %= 10; //각 숫자의 1의 자리 , overflow 발생할 수 있어 숫자의 1의 자리만 따로 구함
        sum *= a; // sum에 각 숫자의 1의 자리 곱함
        sum %= 10; // 다 곱한 sum의 1의 자리 
       }
    cout << sum << endl;
    }
}
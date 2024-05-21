#include <iostream> 
using namespace std;

int main(){
    int t;
    unsigned int n, c;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        
        while(n >= 10){ //n의 값이 한자리 숫자가 되면 종료
            int sum = 1;
            while(n>0){ //n을 10으로 나누고 마지막까지 나누게 되면 0이 나옴 -> 종료
                c = n % 10; //나머지 값

                if (c != 0) //나머지 값이 0이 아니면 sum에 곱해줌
                    sum *= c;

                n /= 10; //n을 10으로 나누어 줌
            }
            n = sum; // n을 한 번 다 나누게 되면, sum을 넣어 다시 한자리가 될 때까지 반복
        }
    cout << n << endl;
    }
}
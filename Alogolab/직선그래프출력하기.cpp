#include <iostream> //원점: O, x축: +, y축: I, 직선: *, 공백: .
using namespace std;

int main(){
    int t, n;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        
        for(int j=0; j<n; j++){
            for(int a=0; a<n; a++){

                if (a == (n/2) and j == (n/2)) // n을 2로 나누어 중앙에 출력
                    cout << "O";
                
                else if (a == (n-1) - j) //행의 순서에 따라 (n-1)값에 빼주고 출력
                    cout << "*";
            
                else if (a == (n/2)) //중간 열에 출력
                    cout << "I";
                
                else if (j == (n/2)) //중간 행에 출력
                    cout << "+";

                else
                    cout << "." ;
            }
            cout << endl;
        }
        
    }
}
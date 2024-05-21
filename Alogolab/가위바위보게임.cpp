#include <iostream> //가위=1, 바위=2, 보=3  
using namespace std;

int main(){
    int t, n;
    cin >> t;

    for(int i=0; i<t; i++){
       cin >> n;
       int rock=0, sissors=0, paper=0;
       for(int j=0; j<n; j++){
        int a;
        cin >> a;
        if (a == 1) // a의 값에 따라 가위,바위,보 카운트
            sissors += 1;
        else if (a == 2)
            rock += 1;
        else
            paper += 1;
        
       }
       
    if (sissors > 0 && rock > 0 && paper >0) // 3개 다 나왔을 때: 무승부 
        cout << 0 << endl;
    else if(sissors > 0 && rock > 0 && paper == 0) // 가위와 바위 : 바위 출력
        cout << rock << endl;
    else if(sissors > 0 && paper > 0 && rock == 0) // 가위와 보 : 가위 출력
        cout << sissors << endl;
    else if(paper > 0 && rock > 0 && sissors == 0) // 보와 바위 : 보 출력
        cout << paper << endl;
    else if(sissors > 0 && rock == 0 && paper == 0) // 가위만 : 무승부
        cout << 0 << endl;
    else if(sissors == 0 && rock > 0 && paper == 0) // 바위만 : 무승부
        cout << 0 << endl;
    else if(sissors == 0 && rock == 0 && paper >0) // 보만 : 무승부
        cout << 0 << endl;
    }
}
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, a, price=0, closing=0, cnt = 0;
        cin >> n;

        for(int j=0; j<n; j++){ //어제의 가격보다 높고 && 내일 가격보다 높을 때
            cin >> a;

            if (j==0){ //처음 시작일 때
                price = a;
                closing = 0;
            }

            if (price < a){ //오늘 가격이 어제 가격보다 높을 때
                closing = 1; //어제 가격보다 높다는 뜻
            }

            if (price == a){ //어제와 오늘의 가격이 같을 때
                continue;
            }
            
            if (closing == 1 && price > a){ //어제의 가격보다 높고 && 내일 가격(오늘)보다 높을 때
                cnt += 1;
                closing = 0; 
                

            }
            price = a;
        }
        cout << cnt << endl;
    }
}
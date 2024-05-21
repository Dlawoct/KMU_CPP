#include <iostream>
using namespace std;

int main() {
    int t;
    int Y[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int YY[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    cin >> t;

    for (int i = 0; i < t; i++) {
        int y,m,d;
        int all = 0, day = 0, sum = 0;
        
        cin >> y >> m >> d;

        for (int i = 1582; i<y; i++){ //년에 대해 전체 날짜 구하기
            if ((i % 4 ==0 && i % 100 != 0) || i % 400 == 0){
                all += 366;
            }
            else{
                all += 365;
            }
        }

        for(int i = 0; i<m-1; i++){ //남은 년에 대해 월 구하기
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
                all += YY[i];
            }
            else{
                all += Y[i];    
            }
        }
        
        all += d; //남은 달에 대해 날짜 더하기

        sum += all % 7;
        day += (sum + 4) % 7;

        cout << day << endl;
    }
}
//1월 2월 3월 4월 5월 6월 7월 8월 9월 10월 11월 12월
//31  28  31 30 31 30  31 31 30  31   30  31
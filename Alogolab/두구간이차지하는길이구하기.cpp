#include <iostream>
using namespace std;
            //[a,b] [c,d]

            //[a,b]와 [c,d] 둘 중에 누가 크냐? - a < c? a > c?

            // a <= c
            //일부가 겹칠 때 - 겹치는 구간: b-c, 전체 구간: d-a
            //한 구간에 속해 있을 때 - 겹치는 구간: d-c, 전체 구간: b-a
            //겹치지 않을 때 - 겹치는 구간: 0, 전체 구간 (b-a) + (d-c)
            

int main() {
    int t,n;
    cin >> t;

    for (int i = 0; i < t; i++) {
            int a, b, c, d;
            int part = 0, all =0;
            cin >> a >> b >> c >> d;

            if (a < c){
                if (a < c && c < b && b < d){ //일부가 겹칠 때
                    part = b - c;
                    all = d - a;
                }
                
                if (a < b && b < c && c < d){ //겹치지 않을 때
                    part = 0;
                    all = (b - a) + (d - c);
                }

                if (a < c && c < d && d < b){ //한 구간에 속해 있을 때
                    part = d - c;
                    all = b - a; 
                }
            }

            else if (a > c){
                if (c < a && a < d && d < b){ //일부가 겹칠 때
                    part = d - a;
                    all = b - c;
                }
                
                if (c < d && d < a && a < b){ //겹치지 않을 때
                    part = 0;
                    all = (b - a) + (d - c);
                }

                if (c < a && a < b && b < d){ //한 구간에 속해 있을 때
                    part = b - a;
                    all = d - c;
                }
            }
            
            else if (a == c || b == d){
                if(b == d || a == c){ //같은 구간 일 때
                    part = a - b;
                    all = a - b;
                }

                else if(b < d || a < c){ //d가 구간이 더 클 때
                    part = b - a;
                    all = d - c;
                }

                else if(b > d || a > c){ //b가 구간이 더 클 때
                    part = d - c;
                    all = b - a;
                }
            }
            cout << part << " " << all << endl;
    }
}
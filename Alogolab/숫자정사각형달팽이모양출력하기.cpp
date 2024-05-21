#include <iostream>
using namespace std;

int main(){
    int t,n,a,b,tmp,cnt,cntup,row,column;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n >> a >> b;
        tmp = 0; cnt = 0;
        row = n; column = 1; cntup = 1;
        for(int j=0; j<n; j++) {
            tmp++;
            cnt++;
            if(a <= cnt && cnt <= b) cout << tmp << " ";

        for(int j=0; j < 2*(n-1); j++) {
            if(j%2 == 0 && j>0) cntup++;
            for(int k=0; k < n-cntup; k++) {
                if(j % 4 == 0)  tmp += n;
                else if(j % 4 == 1) tmp -= 1;
                else if(j % 4 == 2) tmp -= n;
                else tmp += 1;
                cnt++;
                if(a <= cnt && cnt <= b) cout << tmp << " ";
            }
        }
        cout << "\n";
        }
    }
}
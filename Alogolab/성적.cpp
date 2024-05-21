#include <iostream> 
using namespace std;

int main(){
    int t, k, n;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> k;
        int a=0, b=0, c=0, d=0, f=0;

        for(int j=0; j<k; j++){
            cin >> n;

            if (n >= 90)
                a += 1;
            else if (89 >= n && n >= 80)
                b += 1;
            else if (79 >= n && n >= 70)
                c += 1;
            else if (69 >= n && n >= 60)
                d += 1;
            else
                f += 1;
        }
    cout << a << " " << b << " " << c << " " << d << " " << f << endl;
    }
}
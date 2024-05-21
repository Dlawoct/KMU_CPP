#include<iostream>
using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    int ax, ay, bx, by;
    int cx, cy, dx, dy;
    
    for(int i=0; i<testcase; i++){
        int x, y;
        cin >> ax >> ay >> bx >> by; 
        cin >> cx >> cy >> dx >> dy; 
        if( bx < cx || dx < ax || dy < ay || by < cy){
            cout << ((bx - ax) * (by - ay))+((dx - cx) * (dy  - cy));
            cout << " " ;
            cout << ((bx - ax)*2 + (by - ay)*2 )+((dx - cx)*2 + (dy  - cy)*2) << endl;
        }

        else{
            x = min(bx, dx) - max(ax, cx);
            y = min(dy, by) - max(ay, cy);
            cout << (((bx - ax) * (by - ay))+((dx - cx) * (dy  - cy))) - x*y;
            cout << " " ;
            cout << (((bx - ax)*2 + (by - ay)*2 )+((dx - cx)*2 + (dy  - cy)*2)) - (2*x + 2*y) << endl;          
        }
    }
    return 0;
}
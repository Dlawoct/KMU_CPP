#include <iostream>
using namespace std;

int main(){
    int t, width=0, round=0;
    int ax, ay, bx, by;
    int cx, cy, dx, dy;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> ax >> ay >> bx >> by;
        cin >> cx >> cy >> dx >> dy;


        if(((ax<cx && cx<dx && dx<bx) && (ay<cy && cy<dy && dy<by)) || ((cx<ax && ax<bx && bx<dx) && (cy<ay && ay<by && by<dy))){ //내부에 있을 때
            if(ax<cx){
                width = (bx-ax) * (by-ay);
                round = (bx-ax + by-ay)*2;
            }
            else{
                width = (dx-cx) * (dy-cy);
                round = (dx-cx + dy-cy)*2;
            }
            
        }

        else if(((ax<cx && cx<bx && bx<dx) && (ay<cy && cy<by && by<dy)) || ((cx<ax && ax<dx && dx<bx) && (cy<ay && ay<dy && dy<by))){ //일부 겹칠 때
            if (ax<cx){
                width = abs(((bx-ax) * (by-ay)) + ((dx-cx) * (dy-dx)) - ((bx-cx) * (by-cy)));
                round = ((bx-ax + by-ay) * 2) + ((dx-cx + dy-cy) * 2) - ((bx-cx + by-cy) * 2);
            }
            else{
                width = abs(((bx-ax) * (by-ay)) + ((dx-cx) * (dy-dx)) - ((dx-ax) * (dy-ay)));
                round = ((bx-ax + by-ay) * 2) + ((dx-cx + dy-cy) * 2) - ((dx-ax + dy-ay) * 2);
            }
        }

        else{ // 안겹칠때
            width = ((bx - ax) * (by - ay)) + ((dx - cx) * (dy - cy));
            round = ((bx - ax + by - ay) * 2) + ((dx - cx + dy - cy) * 2);
        }

        
        cout << width << " " << round << endl;
        //겹치지 않을때 bx<cx, by<cy
        //일부 겹칠때 ax<cx<bx<dx, ay<cy<by<dy
        //내부에 있을때 ax<cx<dx<bx, ay<cy<dy<by

        // 사각형이 겹치지 않을 때 - 면적: (bx-ax)(by-ay) + (dx-cx)(dy-dx) 둘레: (bx-ax + by-ay)*2 + (dx-cx + dy-cy)*2 
        // 사각형이 일부 겹칠 때 - 면적: (bx-ax)(by-ay) + (dx-cx)(dy-dx) - (bx-cx)(by-cy) 둘레: (bx-ax + by-ay)*2 + (dx-cx + dy-cy)*2 - (bx-cx + by-cy)*4
        // 사각형이 내부에 있을 때(큰 사각형)- 면적: (bx-ax)(by-ay) 둘레: (bx-ax + by-ay)*2

    }
}
////
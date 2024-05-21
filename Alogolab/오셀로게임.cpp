#include <iostream>
using namespace std;
int main(){
    int testcase, num;
    char othello[9][9];
    char black = 'X', white = 'O';
    int move[8][2] = {
        {-1, -1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
    };

    cin >> testcase;
    
    while(testcase--){
        for(int i=1; i<=8; i++){
            for(int j=1; j<=8; j++){
                othello[i][j] = '+';
            }
        }
        othello[4][4] = white;
        othello[5][5] = white;
        othello[4][5] = black;
        othello[5][4] = black;
    

    cin >> num;
    int white_num = 0;
    int black_num = 0;
    
    char color = black;
    while(num --){
        int x,y;
        cin >> x >> y;
        othello[x][y] = color;

        for(int q=0; q<8; q++){
            int mx = x;
            int my = y;
            int change = 0;
            while(1){
                mx += move[q][0];
                my += move[q][1];

                if(mx >= 9 || my >= 9 || mx <= 0 || my <= 0) {
                        change = 0;
                        break;   
                    }
                    else if(othello[mx][my] == '+'){
                        change = 0;
                        break;
                    }

                    else if(othello[mx][my] == color){
                        break;
                    } 

                    else{
                        change++;
                    }
                }
                for(int i=1; i<=change; i++){
                    int update_x = x + move[q][0] * i;
                    int update_y = y + move[q][1] * i;

                    if(update_x >= 9 || update_y >= 9 || update_x <= 0 || update_y <= 0) {
                            change = 0;
                            break;
                        }
                    othello[update_x][update_y] = color;
                }
            }
            if(color == black){
                color = white;
            }   
            else if(color == white){
                color = black;
            }
        }
        for(int x = 1; x <= 8; x++){
                for(int y = 1; y <= 8; y++){
                    if(othello[x][y] == black) black_num++;
                    if(othello[x][y] == white) white_num++;       
                }
        }
        cout << black_num << " " << white_num << endl;
        for(int x = 1; x <= 8; x++){
            for(int y = 1; y <= 8; y++){
                cout << othello[x][y];
            }
            cout << endl;
        }
    }
}
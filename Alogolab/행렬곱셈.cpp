#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        int r,s,t;
        cin >> r >> s >> t;

        int A[r][s];
        for(int i=0; i<r; i++){
            for(int j=0; j<s; j++){
                int num;
                cin >> num;
                A[i][j] = num;
            }
        }

        int B[s][t];
        for(int i=0; i<s; i++){
            for(int j=0; j<t; j++){
                int num;
                cin >> num;
                B[i][j] = num;
            }
        }
        
        int C[r][t];
        for(int i=0; i<r; i++){
            for(int j=0; j<t; j++){
                C[i][j] = 0;  
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<t; j++){
                for(int k=0; k<s; k++){
                    C[i][j] += A[i][k] * B[k][j];
                }   
            }
        }


        for(int i=0; i<r; i++){
            for(int j=0; j<t; j++){
               cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
}
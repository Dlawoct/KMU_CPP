#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m,n;
        cin >> m >> n;
        
        int A[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int num;
                cin >> num;
                A[i][j] = num;
            }
        }

        int B[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int num;
                cin >> num;
                B[i][j] = num;
            }
        }

        int C[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               C[i][j] = A[i][j] + B[i][j];
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
}
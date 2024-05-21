#include <iostream>
#include <fstream> 
using namespace std;

int main() {
    ifstream inputFile("input.txt"); 
    int t, n;
    inputFile >> t;

    for (int i = 0; i < t; ++i) {
        int num0 = 0, num1=0;
        inputFile >> n; 

        while (n>0){ //n을 2로 나누어 마지막까지 나누게 되면 0이 됨

            if (n % 2 == 0){
                num0++;
            }
            else{
                num1++;
            }   
            n /= 2;
        }
        cout << num0 << " " << num1 << endl;
    }
    inputFile.close(); 
}
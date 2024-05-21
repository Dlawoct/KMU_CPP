#include <iostream> 
#include<cstdlib>
using namespace std;

int main(){
    int seed; //seed 정수 선언
    cout << "랜덤 시드를 입력하시오." << endl; 
    cin >> seed; //seed에 입력받고
    
    srand(seed); //srand()함수를 seed를 인자로 작동
    for (int i=1; i<10; i++){ //10개만 출력
        int number = rand()%5 +1; //1~5까지 난수생성, 랜드로 4까지 만들고 +1를 이용해 1~5까지 저장
        cout << number << endl; //number 출력
    }
    return 0;
}

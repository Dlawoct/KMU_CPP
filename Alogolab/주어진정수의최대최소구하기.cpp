#include <iostream>
#include <algorithm> //sort가 algorithm에 포함된 함수.
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
       int n;
       cin >> n;
       int arr[n]; //n칸의 int arr배열 생성
       for(int j = 0; j<n; j++){
            cin >> arr[j]; //순차대로 arr배열에 입력
       }
        sort(arr, arr+n); //sort는 오름차순으로 정렬, sort(begin,end)지만 <end라 배열의 크기 입력
        cout << arr[n-1] << " " << arr[0] << endl;
    }
}
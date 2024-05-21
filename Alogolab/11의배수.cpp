#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;
int main(){
    int testcase;
    string num;
    cin >> testcase;
    for(int i=0; i<testcase; i++){
        string a="";
        int rem, rem2, b, size;
        cin >> num;

        if(num.size()<2){
            cout << 0 << endl;
            continue;
        }
        else{
            while(num.size() > 1){
                rem = (int)num[num.size()-1] - 48;
                a = to_string(rem) + a;
                num.pop_back();

                rem2 = (int)num[num.size()-1] - 48;     
                b = rem2 - rem;
                num.pop_back();

                if(b<0){
                    size = num.size()-1;
                    while(size >= 0){
                        if(num[size] == '0'){
                            num[size] = '9';
                            size --;
                        }
                        else{
                            num[size] = (char)((int)num[size] -1);
                            break;
                        }
                    }
                    num = num + to_string(10+b);
                }
                else{
                    num += to_string(b);
                }
            }
        }
        if (num == "0"){
            if(a[0] == '0')
        cout << a.substr(1)<< endl;
            else
        cout << a << endl;
    }
        else
        cout << 0 << endl;
        
    }
}
#include <iostream>
using namespace std;

int my_atoi(char *s){
    int v = 0;
    for(;*s != '\0'; s++){
        v = v * 10 + (*s - '0');
    }
    return v;
}    
int main(){
    int v, i;
    char s[100];

    cin >> s;
    v = my_atoi(s);
    cout << hex << v << endl;
}
#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

bool not_self_num[10100];

int d(int a){
    int ret = 0;

    while(a){
        ret += a%10;
        a /= 10;        
    }
    ret += a;
    
    return ret;
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    for(int i = 1 ; i < 10001 ; i++){
        not_self_num[d(i)] = true;
    }
    
    for(int i = 1 ; i < 10001 ; i++){
        if(!not_self_num[i])    cout << i << '\n';
    }

    return 0;
}


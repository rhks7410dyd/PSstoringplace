#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

int n,m;
long long subtotal[(10e6)+1];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        long long t;
        cin >> t;
        subtotal[i] += subtotal[i-1];
        subtotal[i] %= m;
    }

    return 0;
}
/*
누적합에서 나머지를 구해도 나머지 값이 유지가 됨.
*/
//왜 dp를 섞었더니 모든 값이 1이 되는지 이해가 안됨
#include <iostream>
#include <cstring>
#define mod 1000000007

using namespace std;

long long dp[5002][2502];
long long rec(int n,int c);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;

    for(int i = 0 ; i < 5002 ; i++){
        for(int j = 0 ; j < 2502 ; j++){
            dp[i][j] = -1;
        }
    }

    while(C--){
        //continue code. . .
        int N;
        cin >> N;
        if(N%2){
            cout << 0 << '\n';
            continue;
        }

        long long ans = rec(N,0);

        cout << ans << '\n';
    }
    return 0;
}

long long rec(int n,int c){
    long long ret = dp[n][c];
    if(ret != -1)   return dp[n][c];

    if(n == 0 || n == c){
        return dp[n][c] = 1;
    }

    if(c == 0){
        return dp[n][c] = rec(n-1,1);
    }

    ret += rec(n-1,c+1);
    ret %= mod;
    ret += rec(n-1,c-1);
    ret %= mod;

    return dp[n][c] = ret;
}
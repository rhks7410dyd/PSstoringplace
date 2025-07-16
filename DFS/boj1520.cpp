#include <iostream>
#include <algorithm>
#define endl '\n'
#define SIZE 501
using namespace std;

int map[SIZE][SIZE];
int dp[SIZE][SIZE];

int n,m;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

int dfs(int c,int r);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    dfs(0,0);

    cout << dp[0][0] << endl;

    return 0;
}

int dfs(int c, int r) {
    if(c == m-1 && r == n-1) return 1;
    
    if(dp[c][r] != -1) return dp[c][r];
    
    dp[c][r] = 0;  // 초기화
    
    for(int i = 0; i < 4; i++) {
        int nc = c + dy[i];
        int nr = r + dx[i];
        
        if(nc < 0 || nc >= m || nr < 0 || nr >= n || map[c][r] <= map[nc][nr]) continue;
        
        dp[c][r] += dfs(nc, nr);
    }
    
    return dp[c][r];
}
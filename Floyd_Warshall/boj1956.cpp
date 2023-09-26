#include <iostream>
#include <algorithm>
#define endl '\n'
#define SIZE 401
#define INF 987654321

using namespace std;

int n,v;
int map[SIZE][SIZE];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> n >> v;

    fill(&map[0][0],&map[SIZE-1][SIZE],INF);

    int a,b,c;
    for(int i = 0 ; i < v ; i++){
        cin >> a >> b >> c;
        map[a][b] = c;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= n ; k++){
                map[j][k] = min(map[j][k],map[j][i]+map[i][k]);
            }
        }
    }

    int ans = INF;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            ans = min(ans,map[i][j]+map[j][i]);
        }
    }

    if(ans == INF)  cout << -1 << endl;
    else    cout << ans << endl;
    
    return 0;
}
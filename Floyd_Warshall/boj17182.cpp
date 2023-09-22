//비트마스킹에 너무 안익숙함
#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define INF 987654321

using namespace std;

int N,K,ans = INF;
int dis[10][10];
int adj[10][10];
int best[1<<10];

void floyd_warshall();
int backtracking(int set,int now);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> adj[i][j];
        }
    }

    floyd_warshall();

    fill(&best[0],&best[1<<10],INF);
    backtracking(1<<K,K);

    cout << best[1<<K] << endl;

    return 0;
}

int backtracking(int set,int now){
    if(set == (1<<10)-1)    return 0;

    int ret = INF;
    for(int i = 0 ; i < N ; i++){
        if(set & (1<<i))  continue;
        int next_set = set | (1<<i);
        ret = min(ret,backtracking(next_set,i)+dis[now][i]);
    }

    if(ret > best[set]) return INF;
    return best[set] = ret;
}

void floyd_warshall(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            dis[i][j] = adj[i][j];
        }
    }

    for(int k = 0 ; k < N ; k++){
        for(int j = 0 ; j < N ; j++){
            for(int i = 0 ; i < N ; i++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
}
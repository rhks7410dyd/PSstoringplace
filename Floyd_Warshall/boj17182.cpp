#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define INF 987654321

using namespace std;

int N,K,ans = INF;
int dis[10][10];
int adj[10][10];
bool visit[10];

void floyd_warshall();
int huristic(int now);
int backtracking(int now);

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

    visit[K] = true;
    ans = huristic(K);
    visit[K] = false;

    ans = min(ans,backtracking(K));

    cout << ans << endl;

    return 0;
}

int backtracking(int now){
    -
}

int huristic(int now){
    int ret = 0,best_path=INF,next_node;

    for(int i = 0 ; i < N ; i++){
        if(best_path > dis[now][i] && now != i && !visit[i]){
            best_path = dis[now][i];
            next_node = i;
        }
    }

    if(best_path == INF)    return 0;

    visit[next_node] = true;
    ret = dis[now][next_node] + huristic(next_node);
    visit[next_node] = false;

    return ret;
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
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321

using namespace std;

int sx,sy,sd,ex,ey,ed;
bool path[100][100];
int map[100][100];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,1,-1};

void Solve();
void Input();
void BFS();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();
    fill(&map[0][0],&map[99][100],-1);
    BFS();
}

void Input(){
    cin >> n >> m;

    int t;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> t;
            if(t)   path[i][j] = true;
            else    path[i][j] = false;
        }
    }
    cin >> sy >> sx >> sd;
    cin >> ey >> ex >> ed;
}

void BFS(){
    queue<pair<pair<int,int>,int>> q;

    q.push({{sy,sx},sd});
    map[sy][sx] = 0;
    while(!q.empty()){
        auto now = q.front();
        q.pop();

        /*
        여기서 반복문으로 돌려야됨.
        */
        int next_y = now.front.front + dy[now.second];
        int next_x = now.front.second + dx[now.second];

        if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || map[next_y][next_x] != -1)  continue;

        //
    }
}
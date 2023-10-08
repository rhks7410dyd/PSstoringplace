//약간 뇌정지 쎄게 와서 메모 하면서 제대로 진행되는 구조인지 확인해봐야됨
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

pair<int,int> map[4][4];
pair<int,int> pos[17];
void Solve();
void Input();
void Swap(int x1,int y1,int x2,int y2);
int rec(int x,int y);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    Solve();

    return 0;
}

void Solve(){
    Input();

    int ans = rec(0,0);

    cout << ans << endl;
}

void Input(){
    int a,b;
    int n = 4;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a >> b;
            map[i][j].first = a;
            map[i][j].second = b;
            pos[a].first = i;
            pos[a].second = j;
        }
    }
}

int rec(int x,int y){
    /*
    1. 이번 칸의 물고기를 먹는다
    2. 물고기가 이동한다
    3. 먹을 수 있는 물고기들 모두로 간 경우를 재귀로 탐색한다.
    4. 최댓값을 구한다.
    백트래킹은 현재 상어의 위치에서 상어의 방향이 벽에 붙어서 벽을 향하는지를 확인하면된다.
    */
    //Backtracking
    int now_d = map[x][y].second;
    int tx = x + dx[now_d];
    int ty = y + dy[now_d];
    
    if(tx < 0 || tx >= 4 || ty < 0 || ty >= 4)  return map[x][y].first;

    int ret = 0;
    pos[map[x][y].first].first = -1;    //행 값이 -1인 경우는 먹힌 경우로 판단
    map[x][y].first = 0;    //0은 상어를 의미,-1은 빈칸

    for(int i = 1 ; i <= 16 ; i++){
        auto now = pos[i];
        if(now.first == -1) continue;

        now_d = map[now.first][now.second].second;
        int next_x = now.first + dx[now_d], next_y = now.second + dy[now_d];
        if(next_x < 0 || next_x >= 4 || next_y < 0 || next_y >= 4)    continue;

        if(map[next_x][next_y].first == 0){
            //이 경우에는 8 방향 다 돌려보기
        }

        Swap(now.first,now.second,next_x,next_y);
    }
    
    //빈칸빈칸빈칸...
    while(tx < 0 || tx >= 4 || ty < 0 || ty >= 4 || map[tx][ty].first != -1){
        ret = max(ret,rec(tx,ty));
        tx += dx[now_d];    ty += dy[now_d];
    }
    ret += map[x][y].first;

    return ret;
}

void Swap(int x1,int y1,int x2,int y2){    
    int& tf = map[x1][y1].first;
    int& ts = map[x1][y1].second;

    if(tf != -1)    pos[tf].first = x2;     pos[tf].second=y2;

    map[x1][y1].first = map[x2][y2].first;
    map[x1][y1].second = map[x2][y2].second;

    map[x2][y2].first = tf;
    map[x2][y2].second = ts;

    if(tf != -1)    pos[tf].first = x1;     pos[tf].second=y1;
}
//
/*]
지금 방향을 따로 저장하지 않고, 상하좌우의 맵에 저장된 최단수행 횟수 값을 역추적해서 지금의 방향을 알아차리는 식으로 구현을 해놨지만,
상하좌우 한 칸씩만 고려하게 된다면 아래와 같은 경우에 오류가 발생한다.

? ? ? 4 ? ? ?
0 0 0 6 0 0 0
5 5 6 6 6 7 7

0이 이동할 수 없는 칸이라 하고, 마지막에 (3,4)에 위치해야된다고 가정하자.
그러면 1,4 와 3,2 에서 출발하는 두 값은 3,4에 위치하는데는 동일한 시간이 걸리지만, 만약 마지막 방향이 1이어야한다면
전자의 경우에는 7번의 시행을 거쳐야하지만, 후자의 경우에는 6번에 걸쳐 끝난다.
즉, 방향에 대한 고려를 하지 않은 최단거리 계산에서 오류가 났다고 볼 수 있다.
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321

using namespace std;

int sx,sy,sd,ex,ey,ed,n,m;
bool wall[100][100];
int map[100][100];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,1,-1};

void Solve();
void Input();
void BFS();
void print2Darray(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] != INF)    cout << map[i][j] << ' ';
            else    cout << -1 << ' ';
        }
        cout << endl;
    }
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();

    if(sx == ex && sy == ey){
        if(sd == ed)    cout << 0 << endl;
        else if(sd/3 == ed/3)   cout << 2 << endl;
        else    cout << 1 << endl;
        return;
    }    

    fill(&map[0][0],&map[99][100],INF);
    BFS();

    int min_d,min_val=INF;
    for(int i = 1 ; i <= 4 ; i++){
        int ty = ey + dy[i];
        int tx = ex + dx[i];
        
        if(ty < 0 || ty >= n || tx < 0 || tx >= m) continue;

        if(map[ty][tx] > map[ey][ex])  continue;

        bool out_range = false;
        if(map[ey][ex] == map[ty][tx]){
            for(int j = 0 ; j < 2 ; j++){
                ty += dy[i];    tx += dx[i];
                if(ty < 0 || ty >= n || tx < 0 || tx >= m){
                    out_range = true;
                    break;
                }
                
                if(map[ty][tx] < map[ey][ex])   break;
            }
        }
        
        if(out_range)   continue;

        if(i == ed) min_val = min(min_val,map[ey][ex] + 2);
        else if(i/3 == ed/3)    min_val = min(min_val,map[ey][ex]);
        else    min_val = min(min_val,map[ey][ex]+1);
    }
    
    cout << min_val << endl;
    //print2Darray();
}

void Input(){
    cin >> n >> m;

    int t;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> t;
            if(t)   wall[i][j] = true;
            else    wall[i][j] = false;
        }
    }
    cin >> sy >> sx >> sd;
    cin >> ey >> ex >> ed;
    sy--;   sx--;
    ey--;   ex--;
}

void BFS(){
    queue<pair<pair<int,int>,int>> q;

    q.push({{sy,sx},sd});
    map[sy][sx] = 0;
    while(!q.empty()){
        auto now = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            for(int k = 1 ; k < 4 ; k++){
                int next_d = (now.second+i)%4+1;
                int next_y = now.first.first + dy[next_d]*k;
                int next_x = now.first.second + dx[next_d]*k;

                if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || wall[next_y][next_x])  break;

                int next_val;
                if(now.second == next_d){
                    next_val = map[now.first.first][now.first.second] + 1;
                }
                else if(now.second/3 == next_d/3){
                    next_val = map[now.first.first][now.first.second] + 3;
                }
                else{
                    next_val = map[now.first.first][now.first.second] + 2;
                }

                if(map[next_y][next_x] > next_val){
                    map[next_y][next_x] = next_val;
                    q.push({{next_y,next_x},next_d});
                }
            }
        }
    }
}

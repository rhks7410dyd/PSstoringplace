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
        if(ty < 0 || ty >= n || tx < 0 || tx >= m || min_val < map[ty][tx]) continue;
        min_val = map[ty][tx];
        min_d = i;
    }
    int last_dir;
    if(min_d%2) last_dir = min_d+1;
    else    last_dir = min_d-1; 

    if(last_dir == ed){
        cout << map[ey][ex] << endl;
    }
    else if(last_dir/3 == ed/3){
        cout << map[ey][ex] + 2;
    }
    else{
        cout << map[ey][ex] + 1;
    }
    cout << endl;

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

/*
1.문제에서의 동서남북과 본인의 코드 동서남북 왼쪽 오른쪽 회전이 논리적으로 일치하는가?

2. 현재 방향으로1,2,3칸을 갈 수있는데 만약 첫 번째칸은 0,두 번째 칸은 1, 세 번째 칸은 0 이라고 하면 첫 번째 칸 까지밖에 가지 못합니다.

3.180회전할 때 명령어 2번이 잘 카운팅이 되는가?

4.저는 목표점에 도착하고 return하는 방식으로 하지않고 목표방향과 일치하는지 검증 후 값을 갱신해주고 continue하는 식으로 했습니다.간간히 return 방식으로 하시는 분들이 계신데 (저도 코린이라 잘 모릅니다만)본인의 논리대로 도착시 바로 return한 값이 최소값이라는 보장이 있는지 다시 생각해 보세요.

5.입력 행,열 은 1<=i,j<=row,col입니다.런타임에러 뜨시는 분들은 index 범위를 고려하였는지 확인해 보세요.

6.저는 이 부분을 간과했었는데 현재 방향에서 시계방향으로 회전하도록 구현했었는데 이렇게 하면 문제가 있습니다

예시로 남쪽을 바라보고 있는 상태에서 동쪽방향으로 회전하려면 회전1번이면 충분하지만 시계방향으로 회전시 3번 회전하게 됩니다.
*/
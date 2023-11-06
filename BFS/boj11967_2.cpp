#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define endl '\n'
#define INF 987654321

using namespace std;

const int SIZE = 101;
int N,M;
struct Info{
    int y,x;
};
vector<Info> Switch[SIZE][SIZE];
queue<pair<int,int>> q;
bool light_on[SIZE][SIZE];
bool push_switch[SIZE][SIZE];
bool can_move[SIZE][SIZE];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void Solve();
void Input();
void BFS();
void pushing(int y,int x);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();

    BFS();

    int n = N,ans = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(light_on[i][j])  ans++;
        }
    }

    cout << ans << endl;
}

void Input(){
    cin >> N >> M;
    int x,y,a,b;
    for(int i = 0 ; i < M ; i++){
        cin >> x >> y >> a >> b;

        Switch[y][x].push_back({b,a});
    }
}

void BFS(){
    light_on[1][1] = true;
    can_move[1][1] = true;
    q.push({1,1});

    //매번 탐색을 해야되나 굳이??
    //불을 킬 때, 1,1과 이어진 친구와 근접해있으면 추가되는 형식으로 하면 될듯
    //while의 조건을 q.empty()로 설정하고, 각 반복의 마지막의 q.empty() == true인 경우 반복문을 사용해서 불이 켜진 방 중에서 인접한 방을 추가로 찾아내는 방식을 사용하면 우선적으로 한 번 거르고, 이후에 한 번에 최대한 여러개를 푸시할 수 있게 됨.
    while(!q.empty()){
        auto now = q.front();        q.pop();
        pushing(now.first,now.second);

        for(int i = 0 ; i < 4 ; i++){
            int ny = dy[i] + now.first;
            int nx = dx[i] + now.second;

            if(ny <= 0 || ny > N || nx <= 0 || nx > N || can_move[ny][nx])  continue;

            if(light_on[ny][nx] && !can_move[ny][nx] && !push_switch[ny][nx]){
                q.push({ny,nx});                
            }
            can_move[ny][nx] = true;
        }

        if(q.empty()){
            for(int i = 1 ; i <= N ; i++){
                for(int j = 1 ; j <= N ; j++){
                    if(light_on[i][j] && can_move[i][j] && !push_switch[i][j]){
                        q.push({i,j});
                        cout << i << ' ' << j << ' ' <<"push\n";
                    }
                }
            }
        }
    }
}

void pushing(int y,int x){
    for (int i=0; i< Switch[y][x].size(); i++)
    {
      auto now = Switch[y][x][i];
      if(!light_on[now.y][now.x]){
        light_on[now.y][now.x] = true;
        if(can_move[now.y][now.x]){
            q.push({now.y,now.x});
        }
      }
    }

    push_switch[y][x] = true;
}

/*
1. 1,1에 있는 모든 스위치를 킴
2. 상하좌우에 불이 켜졌고

추가 고려사항 -> 항상 1,1과 이어져있는지를 확인해야됨.
*/
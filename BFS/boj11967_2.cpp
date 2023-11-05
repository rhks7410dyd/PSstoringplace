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
    int x,y;
};
vector<Info> Switch[SIZE][SIZE];
bool light_on[SIZE][SIZE];
bool push_switch[SIZE][SIZE];
bool can_move[SIZE][SIZE];
void Solve();
void Input();
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

        Switch[y][x].push_back({a,b});
    }
}

void BFS(){
    light_on[1][1];
    pushing(1,1);

    queue<pair<int,int>> q;
    q.push({1,1});
}

void pushing(int y,int x){
    for (int i=0; i< Switch[y][x].size(); i++)
    {
      auto now = Switch[y][x][i];
      light_on[now.y][now.x] = true;
    }

    push_switch[y][x] = true;
}

/*
1. 1,1에 있는 모든 스위치를 킴
2. 상하좌우에 불이 켜졌고

추가 고려사항 -> 항상 1,1과 이어져있는지를 확인해야됨.
*/
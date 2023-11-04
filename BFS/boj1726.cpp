#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321

using namespace std;

struct info{
    int y,x,d,val;
};
typedef struct info info;

bool operator<(const info& a,const info& b){
    if(a.val != b.val)  return a.val > b.val;
    if(a.y != b.y)    return a.y < b.y;
    if(a.x != b.x)  return a.x < b.x;
    return a.d < b.d;
}


bool wall[100][100];
int sx,sy,sd,ex,ey,ed,n,m;
int map[100][100][4];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void Solve();
void Input();
void BFS();
void printarray(){
    cout <<"==============================================\n";
    for(int i = 0 ; i < 4; i++){
        cout << "dir : " << i << endl;
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < m ; k++){
                cout << map[j][k][i] << ' ';
            }
            cout << endl;
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

    //시작점 ==
    if(sx == ex && sy == ey){
        if(sd == ed)    cout << 0 << endl;
        else if(sd/2 == ed/2)   cout << 2 << endl;
        else    cout << 1 << endl;
        return;
    }    

    fill(&map[0][0][0],&map[99][99][4],INF);
    
    BFS();
    
    cout << map[ey][ex][ed] << endl;
    //printarray();
}

void Input(){// 0에 맞춰서 시작점과 도착점의 인덱스 조정
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
    sy--;   sx--;   sd--;
    ey--;   ex--;   ed--;
}

void BFS(){
    priority_queue<info> pq;
    pq.push({sy,sx,sd,0});
    map[sy][sx][sd] = 0;

    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();

        for(int i = 1 ; i <= 3 ; i++){
            int ny = now.y + dy[now.d]*i;
            int nx = now.x + dx[now.d]*i;
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)  continue;
            
            int& next_pos = map[ny][nx][now.d];
            if(next_pos != INF) continue;
            if(wall[ny][nx])    break;
            
            next_pos = now.val + 1;
            pq.push({ny,nx,now.d,now.val + 1});
        }


        for(int i = 0 ; i < 4 ; i++){
            int& next_pos = map[now.y][now.x][i];
            if(now.d != i && next_pos == INF){
                int next_val = now.val;
                if(now.d/2 == i/2)  next_val += 2;
                else    next_val += 1;

                next_pos = next_val;
                pq.push({now.y,now.x,i,next_val});
            }
        }
        
    }
}
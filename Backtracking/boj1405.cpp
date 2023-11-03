#include <iostream>
#define endl '\n'
#define INF 987654321

using namespace std;

bool visit[30][30];
int N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
double per[4];
double backtracking(int y,int x);
void Solve();
void Input();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(10);
    Solve();

    return 0;
}

void Solve(){
    Input();

    double ans = backtracking(15,15);

    cout << ans << endl;
}

void Input(){
    cin >> N;
    for(int i = 0 ; i < 4 ; i++){
        cin >> per[i];
        per[i] /= 100;
    }
}

double backtracking(int y,int x){
    if(visit[y][x]) return 0;
    
    if(!N){
        return 1;
    }

    visit[y][x] = true;

    double ret = 0;
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        N--;
        ret += backtracking(ny,nx)*per[i];
        N++;
    }

    visit[y][x] = false;

    return ret;
}
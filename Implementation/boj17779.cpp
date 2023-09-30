//그림으로 그리든 해서 좀 정리하고 구현하는게 좋아보임
#include <iostream>
#define endl '\n'
#define INF 987654321
#define SIZE 20;

using namespace std;

int n;
int map[SIZE][SIZE];
int section[SIZE][SIZE];

void Solve();
void Input();
int get_diff(int x,int y,int d1,int d2);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();

    for(int i = 1 ; i < n; i++){
        for(int j = 1 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                //continue code...
            }
        }
    }
}

void Input(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }
}

int get_diff(int x,int y,int d1,int d2){
    int ret;

    return ret;
}
#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int N,K;
int dis[10][10];
int adj[10][10];

void floyd_warshall();

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

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << dis[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}

void floyed_warshall(){
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
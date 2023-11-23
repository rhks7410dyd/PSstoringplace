#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 987654321

using namespace std;

const int SIZE = 50;

int N,M,start,end;
int city_val[SIZE];
int move_price[SIZE][SIZE];


void Solve();
void Input();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();
}

void Input(){
    memset(&move_price[0][0],-1,sizeof(move_price));
    int s,e,pri;
    for(int i = 0 ; i < M ; i++){
        //continue code...
        cin >> s >> e >> pri;
        if(move_price[s][e] == -1){
            move_price[s][e] = pri;
        }
        else    move_price[s][e] = move_price[s][e] < pri ? move_price[s][e] : pri;
    }
    for(int i = 0 ; i < N ; i++){
        cin >> city_val[i];
    }
}



/*
1. 마지막 도시까지 도착할 수 있는가?
2. 경로 상에 이윤이 남는 사이클이 존재하는가?
3. 사이클이 존재하지 않는 마지막 도시까지 도착하는 그래프의 경우에는 동적 계획법으로 풀기

https://great-park.tistory.com/134
벨만-포드 알고리즘에서 N-1개보다 더 많은 간선을 지날 때, 최종 수익이 최대화 됨을 알아낸다면 양의 사이클이 존재하므로 gee, 결과 값이 INF라면 gg, 아니라면 그 값을 출력하면 됨
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

int N;
long long M;
vector<pair<long long,long long>> route;
priority_queue<long long,int> temp;


int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    cin >> N >> M;

    long long a,b;
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b;
        route.push_back({a,b});
    }

    sort(route.begin(),route.end());

    int passenger_num = 0;
    long long now_pos = 0;
    long long ans_dis = 0;
    temp.push({route[0].first,0});

    /*
    가는 길에 픽업 되면 하기 + 내려주는 위치면 second를 -1로 푸쉬, 아니면 자기 인덱스 번호 저장
    그래서 세컨드가 음수가 아니면 그 인덱스 번호의 세컨드를 푸쉬, -1이면 푸쉬 X
    */
    while(!temp.empty()){
        auto nxt = temp.top().first;
        temp.pop();
        ans_dis += abs(now_pos - nxt.first);
        now_pos = nxt.first;
        if(nxt.second >= 0)  temp.push({});
        else    temp.push({});
    }

    return 0;
}
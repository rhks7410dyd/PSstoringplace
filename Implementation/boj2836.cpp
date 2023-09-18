//우선순위 큐에 넣을 comapare함수를 통해서 무조건적으로 가장 효율적인 애가 우선순위 큐의 탑에 오도록 구현할 수 있다면 편할 것
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

int N;
long long M,now_pos=0;
vector<pair<long long,long long>> route;
priority_queue<long long,int> temp;

bool compare(pair<long long,long long>& a,pair<long long,long long>& b);

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

    long long ans_dis = 0;
    temp.push({route[0].first,0});

    /*
    가는 길에 픽업 되면 하기 + 내려주는 위치면 second를 -1로 푸쉬, 아니면 자기 인덱스 번호 저장
    그래서 세컨드가 음수가 아니면 그 인덱스 번호의 세컨드를 푸쉬, -1이면 푸쉬 X
    */
   
    while(!temp.empty()){
        auto now = temp.top();
        temp.pop();
        

        if(now.second >= 0){
            temp.push({route[now.second].first,-1});
        }

        
    }

    return 0;
}

bool compare(pair<long long,long long>& a,pair<long long,long long>& b){
    return abs(a.first-now_pos) > abs(b.first-now_pos);
}
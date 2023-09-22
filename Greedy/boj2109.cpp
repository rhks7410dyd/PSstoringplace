#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define INF 987654321

using namespace std;

int n;
vector<pair<int,int>> v;
priority_queue <int> pq;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    int a,b;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end(),greater<>());

    int ans = 0,i = 0,max_d = v[0].first;
    //이미 사용한 애 중복 가능 += 모든 요일이 붙어서 나오는 것이 아님을 명심해야됨
    for(int i = max_d ; i > 0 ; i--){
        for(int j = 0 ; j < n ; j++){
            if(v[j].first != i) break;
            pq.push(v[j].second);
        }

        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}
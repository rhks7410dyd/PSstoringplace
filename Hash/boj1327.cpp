#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    map<vector<int>,int> Map;
    int k,n;
    cin >> n >> k;

    vector<int> input;
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        //continue code...
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
        ans.push_back(i+1);
    }

    
    Map[ans] = INF;
    if(Map[input] == INF){
        cout << 0 << endl;
        return 0;
    }
    Map[input] = 0;
    queue<pair<vector<int>,int>> q;
    q.push({input,0});

    int tmp;
    while(!q.empty()){
        auto now = q.front();
        q.pop();

        for(int i = 0 ; i <= n-k ; i++){
            auto temparr = now.first;
            for(int j = 0 ; j < k/2 ; j++){
                tmp = temparr[i+j];
                temparr[i+j] = temparr[i+k-j-1];
                temparr[i+k-j-1] = tmp;
            }
            if(Map.find(temparr) != Map.end()){
                if(Map[temparr] == INF){
                    cout << now.second+1 << endl;
                    return 0;
                }
            }
            else{
                Map[temparr] = now.second+1;
                q.push({temparr,now.second+1});
            }
        }

    }

    cout << -1 << endl;
    return 0;
}
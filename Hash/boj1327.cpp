#include <bits/stdc++.h>

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

    
    Map[input] = 0;
    queue<pair<vector<int>,int>> q;
    q.push({input,0});

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(Map.find(now.first) != Map.end()){
            break;
        }
        for(int i = 0 ; i <= n-k ; i++){
            //continue code...
        }
    }


}
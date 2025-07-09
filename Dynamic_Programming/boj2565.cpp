#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    int n;

    cin >> n;
    
    int a,b;
    vector<pair<int,int>> input;
    for(int i = 0 ; i < n ; i++){
        //continue code...
        cin >> a >> b;
        input.push_back({a,b});
    }

    sort(input.begin(),input.end());

    int dp[500][2];
    
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = 0; dp[i][1] = 0;
    }

    dp[0][0] = 1;
    dp[0][1] = input[0].second;

    for(int i = 1 ; i < n ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            //continue code...
            if(dp[j][1] < input[i].second && dp[j][0] + 1 > dp[i][0] ){
                if(dp[i][0] == dp[j][0] + 1){
                    dp[i][1] = min(input[i].second, dp[i][1]);
                }
                else{
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = input[i].second;
                }
            }
        }

        if(dp[i][0] == 0){
            dp[i][0] = 1;
            dp[i][1] = input[i].second;
        }
    }

    int max = -1;
    for(int i = 0 ; i < n ; i++){
        if(max < dp[i][0])  max = dp[i][0];
    }

    cout << n - max << endl;
    return 0;
}
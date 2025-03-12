#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    map<string,int> ans;

    int n;

    cin >> n;

    string temp;

    for(int i = 1 ; i <= n ; i++){
        //continue code...
        cin >> temp;
        ans[temp] = i;
    }

    vector<string> input;

    for(int i = 0 ; i < n ; i++){
        //continue code...
        cin >> temp;
        input.push_back(temp);
    }

    string earliar,later;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            //continue code...
            earliar = input[i];
            later = input[j];

            if(ans[earliar] < ans[later])   cnt++;
        }
    }

    cout << cnt <<'/' << n*(n-1)/2 << endl;

    return 0;
}
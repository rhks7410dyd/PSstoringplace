#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    int n;
    cin >> n;

    map<string,int> out;
    vector<string> in;

    string temp;
    for(int i = 0 ; i < n ; i++){
        //continue code...
        cin >> temp;
        in.push_back(temp);
    }
    for(int i = 0 ; i < n ; i++){
        //continue code...
        cin >> temp;
        out[temp]=i;
    }
    
    int cnt = 0;
    int max = out[in[0]];
    for(int i = 1 ; i < n ; i++){
        //continue code...
        string now = in[i];
        if(max > out[now]){
            cnt++;
        }
        else{
            max = out[now];
        }
    }

    cout << cnt << endl;

    return 0;
}
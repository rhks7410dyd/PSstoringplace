#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int n;
vector<int> input;

void Solve();
void Input();
bool is_good(int idx);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();

    sort(input.begin(),input.end());

    int cnt = 0;
    for(int i = n-1 ; i > 1 ; i--){
        //continue code...
        if(input[0] + input[1] > input[i]) break;

        if(is_good(i))   cnt++;
    }

    cout << cnt << endl;
}

void Input(){
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        //continue code...
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
}

bool is_good(int idx){
    int le = 0,ri = idx-1, temp;
    while(le < ri){
        temp = input[le] + input[ri];
        if(temp == input[idx]) return true;
        else if(temp > input[idx])  ri--;
        else    le++;
    }
    return false;
}
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
    for(int i = n-1 ; i >= 0 ; i--){
        //continue code...

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
    int le = 0,ri = n-1, temp;
    if(ri < 1)  ri = 1;
    while(le < ri){
        temp = input[le] + input[ri];
        if(temp == input[idx] && (idx != ri && idx != le) ){
            //cout << idx << ':' << le << '&' << ri << ' ' << input[le] << " + " << input[ri]  << " = " << input[idx] << endl;
            return true;
        }
        else if(temp >= input[idx] && idx != 0)  ri--;
        else    le++;
    }
    return false;
}
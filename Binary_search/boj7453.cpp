#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define endl '\n'

using namespace std;

int n;
vector<int> input[4];
vector<int> merging[2];

void Solve();
void Input();
void sort_and_merging();
void get_ans();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}
 
void Solve(){
    Input();

    sort_and_merging();

    cout << get_ans() << endl;
}

void sort_and_merging(){
    for (int i = 0; i < 4; ++i) {
        sort(input[i].begin(), input[i].end());
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            //continue code...
            merging[0].push_back(input[0][i] + input[1][j]);
            merging[1].push_back(input[2][i] + input[3][j]);
        }
    }
}

void Input(){
    cin >> n;
    int temp;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 4 ; j++){
            //continue code...
            cin >> temp;
            input[j].push_back(temp);
        }
    }
}


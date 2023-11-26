#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int w,b;
const int score[9] = {0,0,0,1,1,2,3,5,11};
char board[30][4][4];
vector<string> word;

void Solve();
void Input();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();
}

void Input(){
    cin >> w;
    string input;
    for(int i = 0 ; i < w ; i++){
        cin >> input;
        word.push_back(input);
    }

    sort(word.begin(),word.end());
    
    cin >> b;
    for(int i = 0 ; i < b ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cin >> input;
            for(int k = 0 ; k < 4 ; k++){
                board[i][j][k] = input[k];
            }
        }
    }
}

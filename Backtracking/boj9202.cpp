#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

/*
1. 최대 점수는 가능한 모든 조합을 해봐야됨.
2. 두 글자 이하의 단어는 패스
3. 어떤 단어를 만들 수 있을 때, 만들 수 있는 경로(정확히는 위치들의 집합)을 저장해야됨 <= 비트마스킹
4. 
*/

const int score[9] = {0,0,0,1,1,2,3,5,11};
const int dx[8] = {0,1,1,1,0,-1,-1,-1};
const int dy[8] = {-1,-1,0,1,1,1,0,-1};

char board[30][4][4];
vector<string> word;

void Solve();
void Input();
bool backtracking(int board_num,int word,int index,int y,int x);

int w,b,visit_set;
int longest_index;
int cnt;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();

    int n = 4;
    for(int b_num = 0 ; b_num < b , b_num++){
        for(int i = 0 ; i < w ; i++){
            for(int j = 0 ; j < 4 ; j++){
                for(int k = 0 ; k < 4 ; k++){
                    if(word[i][0] == board[b_num][j][k]){
                        visit_set = 0;
                        if(backtracking(b_num,w,0,j,k)){
                            cnt++;
                        }
                    }
                }
            }
        }
        cout << score[word[longest_index].size()] << ' ' << word[longest_index] << ' ' << cnt << endl;
    }
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
    cnt = 0;
    longest_index = -1;
}

bool backtracking(int board_num,int word,int index,int y,int x);

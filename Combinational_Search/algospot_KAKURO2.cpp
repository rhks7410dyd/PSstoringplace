#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define MAXSIZE 20

using namespace std;

struct hint_info{
    int r,c,sum;
    bool vert_dir;
};

int n,q,now_idx;
int gameboard[MAXSIZE+1][MAXSIZE+1];
int dp[10][46][1024];
vector<hint_info> info;
vector<int> v[46];



int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;

    while(C--){
        //continue code. . .
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cin >> gameboard[i][j];
                if(gameboard[i][j]) gameboard[i][j] = 0;
                else    gameboard[i][j] = 1;
            }
        }

        cin >> q;
        int x,y,s,d;
        bool dir;
        for(int i = 0 ; i < q ; i++){
            cin >> y >>x >> d >> s;
            if(d)   dir = true;
            else    dir = false;

            info.push_back({y,x,s,dir});
        }
    }
    return 0;
}


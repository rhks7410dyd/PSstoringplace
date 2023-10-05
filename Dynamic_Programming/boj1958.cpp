/*
좀 손으로 풀어보고 확인하기.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define SIZE 101

using namespace std;

string a,b,c;
int a_size,b_size,c_size;

int dp[SIZE][SIZE][SIZE];

void Solve();
int get_ans(int i,int j,int k);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    cin >> a >> b >> c;

    a_size = a.size();
    b_size = b.size();
    c_size = c.size();

    memset(dp,-1,sizeof(dp));

    int ans = get_ans(0,0,0);

    cout << ans << endl;
}

int get_ans(int i,int j,int k){
    int& ret = dp[i][j][k];
    if(ret != -1)   return ret;
    //
    if(i == a_size || j == b_size || k == c_size)   return 0;

    if(a[i] == b[j] && b[j] == c[k]){
        ret = max(ret,get_ans(i+1,j+1,k+1)+1);
    }

    ret = max(ret,get_ans(i+1,j,k));
    ret = max(ret,get_ans(i,j+1,k));
    ret = max(ret,get_ans(i,j,k+1));

    return ret;
}


/*
#include <iostream>
#include <string>

using namespace std;

string str1;
string str2;
int dp[1001][1001];

int main()
{
    cin >> str1;
    cin >> str2;
    for(int i = 1 ; i <= str1.size() ; i++){
        for(int j = 1 ; j <= str2.size() ; j++){
            if(str1[i-1] == str2[j-1]){
               dp[i][j] = dp[i-1][j-1] + 1; 
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]) dp[i][j] = dp[i-1][j];
                else    dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[str1.size()][str2.size()];
    return 0;
}
*/
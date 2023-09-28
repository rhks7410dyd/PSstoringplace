/*
좀 손으로 풀어보고 확인하기.
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define SIZE 101

using namespace std;

int dp[SIZE][SIZE][SIZE];

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    string a,b,c;

    cin >> a >> b >> c;

    int a_size = a.size();
    int b_size = b.size();
    int c_size = c.size();

    for(int i = 1 ; i <= a_size ; i++){
        for(int j = 1 ; j <= b_size ; j++){
            for(int k = 1 ; k <= c_size ; k++){
                if(a[i-1]==b[j-1]==c[k-1]){
                    dp[i][j][k] == dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k-1]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);   
                }
            }
        }
    }

    cout << dp[a_size][b_size][c_size] << endl;

    return 0;
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#define endl '\n'
#define INF 987654321
#define MOD 1000000007

using namespace std;

/*
스캐폴딩에 문제가 있ㅇ므;;
*/

int n;
vector<int> v;

long long DP[300000];
long long dp[1<<24];
void Solve();
void Input();
long long get_ans();

bool scapolding();
long long sca_rec(int set,int index);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0 ; i < 10 ; i++){
        fill(dp,&dp[(1<<24) + 1],-1);
        random_device rd1;
        mt19937 gen(rd1());
        uniform_int_distribution<int> dis(0, MOD-1);
        n = dis(gen) % 24 + 1;
        n = 4;
        for(int i = 0 ; i < n ; i++){
            v.push_back(dis(gen));
        }
        bool same = scapolding();
        v.clear();
        if(!same)   break;
    }

    return 0;
}

void Solve(){
    Input();
    sort(v.begin(),v.end());
    long long ans = get_ans();
    cout << ans << endl;
}

void Input(){
    cin >> n;

    int t;
    for(int i = 0 ; i < n ; i++){
        cin >> t;
        v.push_back(t%MOD);
    }
}

long long get_ans(){
    long long ret = 0;
    DP[0] = 1;
    for(int i = 1 ; i < n ; i++){
        DP[i] = (2*DP[i-1])%MOD;
    }

    /*
    0 1 2 3 4 5 6 7 8 9 10
    i번째
    최대의 경우 = 2^i - 1
    최소의 경우 = 2^(n-i-1) - 1
    */

    for(int i = n - 1 ; i >= 0 ; i--){
        long long temp = (DP[i] - DP[n-i-1])%MOD;
        ret += (v[i] * temp)%MOD; 
    }
    if(ret < 0) ret += MOD;
    return ret;
}

void printvector(){
    cout << v.size() << endl;
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << '\n';
    }
    cout << '\n';
}

bool scapolding(){
    /*
    모든 조합을 만들어보고, 그 조합에 따라서 결과 값을 다 계산해보는 브루트 포스로 구현하기
    입력값은 24개 이하
    */
    sort(v.begin(),v.end());
    long long ans = get_ans();
    long long sca_ans = sca_rec(0,0);

    if(sca_ans != ans){
        /*
        1. v 출력
        2. sca_ans, ans 출력하고 종료
        */
        cout << "Wrong!\n";
        printvector();

        cout << sca_ans << "     " << ans << endl;
        return false;
    }
    else{
        cout << "correct\n";
        cout << v.size() << endl << sca_ans << endl;
        return true;
    }
}

long long sca_rec(int set,int index){
    long long& ret = dp[set];
    if(ret != -1)   return ret;

    if(index == n){
        int min_ind=-1,max_ind;
        for(int i = 0 ; i < n ; i++){
            if(set & (1<<i)){
                if(min_ind == -1){
                    min_ind = i;
                }
                max_ind = i;
            }
        }
        return ret = (v[max_ind] - v[min_ind])%MOD;
    }

    ret = 0;
    ret += sca_rec(set + (1<<index),index+1)%MOD;
    ret += sca_rec(set,index+1)%MOD;
    ret %= MOD;
    return ret;
}
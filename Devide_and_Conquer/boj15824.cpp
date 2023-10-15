#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <random>
#define endl '\n'
#define INF 987654321

using namespace std;

vector<int> v;
int n;
long long MOD = 1e9 + 7;
long long mod = 1e9 + 7;

long long solve(int s,int e);
long long power[300001];
long long sca_code();
void Solve();
void Scapolding();

int main(){
    //cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    //Solve();
    Scapolding();

    return 0;
}

void Scapolding(){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dis(0,2147483647);

    int loop = dis(gen)%1000;

    power[0] = 1;
    for(int i = 1 ; i < n ; i++){
        power[i] = power[i-1]*2;
        power[i] %= MOD;
    }

    for(int c = 0 ; c < 100 ; c++){
        n = dis(gen)%300000 + 1;
        for(int i = 0 ; i < n ; i++){
            v.push_back(dis(gen)%MOD);
        }
        
        sort(v.begin(),v.end());
        int sca = sca_code();
        int me = solve(0,v.size()-1);
        if(sca== me)   cout << "n " << n << "  ans " << sca << endl;
        else    cout << "Error!\n n " << n << " ans " << sca << "  my ans " << me << endl;
    }
}

void Solve(){
    cin >> n;
    int t;
    for(int i = 0 ; i < n ; i++){
        cin >> t;
        v.push_back(t);
    }
    
    power[0] = 1;
    for(int i = 1 ; i < n ; i++){
        power[i] = power[i-1]*2;
        power[i] %= MOD;
    }

    sort(v.begin(),v.end());

    long long ans = solve(0,v.size()-1);

    cout << ans << endl;
}

long long solve(int s,int e){
    //기저 사례
    if(s == e)  return 0;
    if(s == e-1)    return v[e]-v[s];
    
    //분할
    int m = (s+e)/2;

    long long ret = 0;
    ret += solve(s,m);
    ret %= MOD;
    ret += solve(m+1,e);
    ret %= MOD;

    long long min_sum=0;
    for(int i = s ; i <= m ; i++){
        min_sum += v[i]*power[m-i]%MOD;
        min_sum %= MOD;
    }

    for(int j = m+1 ; j <= e ; j++){
        ret += v[j]
    }
    return ret;
}

//스캐폴딩을 위한 다른 사람 코드

long long pw(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}

long long md(long long a, long long b){
	return ((a%b)+b)%b;
}

long long sca_code(){
	long long ans = 0;
	for(int i=0; i<n; i++){
		long long mxcnt = pw(2, i);
		ans += (v[i] % mod) * mxcnt % mod;
		long long mncnt = pw(2, n-i-1);
		ans -= (v[i] % mod) * mncnt % mod;
		ans = md(ans, mod);
	}
    return ans;
}
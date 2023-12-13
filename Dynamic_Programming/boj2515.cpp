/*
스캐폴딩이 쉬운 문제이기 때문에 스캐폴딩으로 깊이 30까지로 무작위로 돌려보기
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'

using namespace std;

const int SIZE = 300001;

vector<pair<int,int>> info;
vector<pair<int,int>> input;
int n,S,info_size;
long long dp[SIZE];
int next_point[SIZE];

void Solve();
void Input();
int binary_search(int start,int num);
long long get_val(int idx);

void printvector(){
    cout << "=======================\n";
    for(int i = 0 ; i < info.size() ; i++){
        cout << info[i].first << ' ' << info[i].second << endl;
    }
    cout << '\n';
}

int main(){
    //cin.tie(NULL);	cout.tie(NULL);
    //ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();
    memset(&dp[0],-1,sizeof(dp));

    //printvector();

    info_size = info.size();

    for(int i = info_size-1 ; i >= 0 ; i--){
        next_point[i+1] = binary_search(i+1,info[i].first);
    }

    long long ans = get_val(-1);

    cout << ans << endl;
}

void Input(){
    cin >> n >> S;
    int h,c;
    for(int i = 0 ; i < n ; i++){
        cin >> h >> c;
        input.push_back({h,c});
    }
    sort(input.begin(),input.end());

    /*
    중복 없앴더니 34% -> 11% 정도로 채점이 막힘. 여기서 뭔가 문제가 있음
    */
    bool same_val[SIZE];
    for(int i = 0 ; i < n-1 ; i++){
        if(input[i].first == input[i+1].first){
            same_val[i] = true;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(!same_val[i])    info.push_back(input[i]);
    }
}

int binary_search(int start,int num){
    int s = start,e = info_size;
    while(s < e){
        int mid = (s+e)/2;
        if(info[mid].first - num >= S){
            if(info[mid-1].first - num < S){
                return mid;
            }

            e = mid;
        }
        else{
            s = mid+1;
        }
    }

    return -1;
}

long long get_val(int idx){
    long long& ret = dp[idx+1];

    if(ret != -1)   return ret;

    ret = 0;

    int last_idx = next_point[next_point[idx+1]+1];
    if(last_idx == -1)  last_idx = info_size;

    for(int i = next_point[idx+1] ; i < last_idx ; i++){// + 1 이 아니라 다음번이 될 수 있는 애부터 찾는게 나을듯
        ret = max(ret,get_val(i)+info[i].second);
    }

    return ret;
}

/*
안보이는 애는 선택 안한 걸로 생각하기
dp[i+1] = i번째를 선택했을 때 최대 판매 비용

6 4
15 80
8 230
10 100
17 200
20 75
26 80
510

8 230
10 100
15 80
17 200
20 75
26 80

510
280
280
155
80
80
0



*/
/*
스캐폴딩으로 깊이 100까지 해봤는데도 안잡힘 + 2%로 줄어듬..도대체 왜?
그리고 도저히 왜 그런지 이해가 안감
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <random>
#include <time.h>
#define endl '\n'

using namespace std;

const int SIZE = 300001;

vector<pair<int,int>> info;
vector<pair<int,int>> input;
int n,S,info_size;
long long ans;
long long dp[SIZE];
int next_point[SIZE];

void Solve();
void Input();
int binary_search(int start,int num);
long long get_val(int idx);

long long brute(int idx){
    if(idx == info_size)    return 0;

    long long ret = brute(idx+1);
    for(int i = idx+1 ; i < info_size ; i++){
        if(idx != -1 && info[i].first - info[idx].first < S) continue;
        ret = max(ret,brute(i)+info[idx].second);
    }

    return ret;
}

void sca_input(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 20000000);

    n = dis(gen)%30 + 80;
    S = dis(gen);
    uniform_int_distribution<int> H_dis(S, 20000000);

    for(int i = 0 ; i < n ; i++){
        input.push_back({H_dis(gen),dis(gen)%1000+1});
    }

    sort(input.begin(),input.end());

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

int scapolding(){
    time_t start_time,end_time;
    double result_time;
    start_time = time(NULL);

    memset(&dp[0],-1,sizeof(dp));
    info.clear();
    input.clear();
    sca_input();

    info_size - info.size();

    for(int i = info_size-1 ; i >= 0 ; i--){
        next_point[i+1] = binary_search(i+1,info[i].first);
    }

    ans = get_val(-1);

    end_time = time(NULL);

    result_time = (double)(end_time - start_time);
    if(result_time >= 2.0){
        cout << "time out!\n";
        return 0;
    }   

    long long sca_ans = brute(-1);
    if(sca_ans != ans){
        cout << "scapolding answer : " << sca_ans << "/tans : " << ans << endl;
        return 0;
    }
    return 1;
}

void printvector(){
    cout << "=======================\n";
    for(int i = 0 ; i < info.size() ; i++){
        cout << info[i].first << ' ' << info[i].second << endl;
    }
    cout << '\n';
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();
    /*
    for(int i = 0 ; i < 1000000 ; i++){
        if(!scapolding())   break;
    }*/

    return 0;
}

void Solve(){
    Input();
    memset(&dp[0],-1,sizeof(dp));

    //printvector();

    info_size = info.size();

    for(int i = info_size-1 ; i >= 0 ; i--){
        next_point[i+1] = binary_search(i+1,info[i].first); //i번째 인덱스 다음에 오면서 판매가 되는 그림이 시작하는 인덱스 번호
    }

    ans = get_val(-1);

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

    if(next_point[idx+1] == -1) return ret;

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
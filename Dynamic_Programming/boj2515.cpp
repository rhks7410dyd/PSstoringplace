/*
97%까지 떡상했는데 3퍼센트 부족인걸로 봐서는 예외 처리를 못한거로 생각됨
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

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}

void Solve(){
    Input();
    fill(&dp[0],&dp[SIZE],-1);
    //printvector();
    
    info_size = info.size();

    next_point[0] = 0;
    for(int i = 0 ; i < info_size ; i++){
        next_point[i+1] = binary_search(i+1,info[i].first); //i번째 인덱스 다음에 오면서 판매가 되는 그림이 시작하는 인덱스 번호
    }

    ans = get_val(-1);

    cout << ans << endl;
}


void Input(){
    cin >> n >> S;
    input.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> input[i].first >> input[i].second;
    }

    sort(input.begin(), input.end());

    // 중복된 높이 제거
    auto it = unique(input.begin(), input.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first == b.first;
    });
    input.resize(distance(input.begin(), it));

    for(auto p : input) {
        info.push_back(p);
    }
    info_size = info.size();
}

/*
void Input(){
    cin >> n >> S;
    int h,c;
    for(int i = 0 ; i < n ; i++){
        cin >> h >> c;
        input.push_back({h,c});
    }

    sort(input.begin(),input.end());

    bool same_val[SIZE];
    for(int i = 0 ; i < n-1 ; i++){
        if(input[i].first == input[i+1].first){
            same_val[i] = true;
        }
        else    same_val[i] = false;
    }
    for(int i = 0 ; i < n ; i++){
        if(!same_val[i])    info.push_back(input[i]);
    }
}
*/

int binary_search(int start,int num){
    int s = start,e = info_size;
    while(s < e){
        int mid = (s+e)/2;
        if(info[mid].first - num >= S){
            if(start == mid || info[mid-1].first - num < S){
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

    int next_idx = next_point[idx+1];//idx 뒤에 올 수 있는 가장 높이가 낮은 그림의 인덱스 번호
    if(next_idx == -1) return ret;

    int last_idx = next_point[next_idx+1];
    if(last_idx == -1)  last_idx = info_size;

    for(int i = next_idx ; i < last_idx ; i++){// + 1 이 아니라 다음번이 될 수 있는 애부터 찾는게 나을듯
        ret = max(ret,get_val(i)+info[i].second);
    }

    return ret;
}

/*
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int picture_num, selling_height;
vector<int> dp, limit;
vector<pair<int,int>> pictures;

int main(){
  ios_base::sync_with_stdio(0);
  cin>>picture_num>>selling_height;

  dp.resize(picture_num+1);
  limit.resize(picture_num+1);
  pictures = vector<pair<int,int>>(picture_num+1);

  int height, cost;
  pictures[0] = {0,0};
  for(int i=1; i<=picture_num ; ++i){
    cin>>height>>cost;
    pictures[i] = {height, cost}; 
  }

  sort(pictures.begin(), pictures.end());

  for(int idx=1; idx<=picture_num ; ++idx){
    for(limit[idx] = limit[idx-1]; limit[idx] <idx ; ++limit[idx])
      if(pictures[idx].first - pictures[limit[idx]].first < selling_height) break;
    --limit[idx];
  }

  for(int idx=1; idx<=picture_num ; ++idx)
    dp[idx] = max(dp[idx-1], dp[limit[idx]] + pictures[idx].second);

  cout<<dp[picture_num]<<'\n';
  return 0;
}
*/

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
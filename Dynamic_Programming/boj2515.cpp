#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'

using namespace std;

const int SIZE = 300001;

vector<pair<int,int>> info;
int n,S;
long long dp[SIZE];

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

    long long ans = get_val(-1);

    cout << ans << endl;
}

void Input(){
    cin >> n >> S;
    int h,c;
    for(int i = 0 ; i < n ; i++){
        cin >> h >> c;
        info.push_back({h,c});
    }
    sort(info.begin(),info.end());

    for(int i = 0 ; i < info.size()-1 ; i++){
        if(info.size() == 0)    break;
        if(info[i].first == info[i+1].first){
            int e = i+2;
            while(e < info.size() && info[i].first == info[e].first)  e++;
            for(int j = i ; j < e-1 ; j++){
                info.erase(info.begin()+i);
            }
        }
    }
}

int binary_search(int start,int num){
    int s = start,e = info.size();
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
    int first_case = -1,next_point = idx + 1;
    if(idx != -1)   next_point = binary_search(idx+1,info[idx].first);

    if(next_point == -1)    return ret = 0;

    for(int i = next_point ; i < info.size() ; i++){// + 1 이 아니라 다음번이 될 수 있는 애부터 찾는게 나을듯
        ret = max(ret,get_val(i)+info[i].second);
        if(first_case == -1)    first_case = i;
        if(first_case != -1 && info[i].first - info[first_case].first >= S) break;
    }

    return ret;
}

/*
문제에서 중요한 것은 얼마나 많은 그림이 세로가 s 이상이 되게 배치되는가? 즉, 완전 탐색으로 모든 경우를 찾아야한다. 그리고 휴리스틱을 사용해서 시간 절약

안보이는 애는 선택 안한 걸로 생각하기
dp[i+1] = i번째를 선택했을 때 최대 판매 비용

*/
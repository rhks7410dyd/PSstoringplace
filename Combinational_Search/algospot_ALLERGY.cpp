//문제 자체는 제대로 푼 건지 테케는 맞지만, 세그폴트가 뜬다
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#define INF 987654321

using namespace std;

int n,m,ans;
map <string,int> m1;
vector<int> food_info[50];
vector<int> pep_info[50];
int valid_count[50];

int solve(int now);
void clear_vector();

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;

    while(C--){
        cin >> n >> m;
        string input;
        for(int i = 0 ; i < n ; i++){
            cin >> input;
            m1[input] = i;
        }

        int t,Max=0;
        for(int i = 0 ; i < m ; i++){
            cin >> t;
            Max = max(Max,t);
            valid_count[i] = t;
            for(int j = 0 ; j < t ; j++){
                cin >> input;
                food_info[i].push_back(m1[input]);
                pep_info[m1[input]].push_back(i);
            }
        }

        ans = INF;

        for(int i = 0 ; i < m ; i++){
            if(valid_count[i] == Max){
                ans = min(ans,solve(i));
            }
        }

        cout << ans << '\n';
        clear_vector();
        memset(valid_count,0,sizeof(valid_count));
    }

    return 0;
}

int solve(int now){
    for(int i = 0 ; i < m ; i++){
        if(valid_count[i])    break;

        return 1;
        //return 1?
    }

    int now_t = valid_count[now];
    for(int i = 0 ; i < now_t ; i++){
        int t = food_info[now][i];
        for(size_t j = 0 ; j < pep_info[t].size() ; j++){
            valid_count[pep_info[t][j]]--;
        }
    }

    int ret = INF,Max = -1;

    for(int i = 0 ; i < m ; i++){
        if(Max < valid_count[i])   Max = valid_count[i];
    }

    for(int i = 0 ; i < m ; i++){
        if(Max == valid_count[i]){
            ret = min(ret,solve(i)+1);
        }
    }

    for(int i = 1 ; i < now_t ; i++){
        int t = food_info[now][i];
        for(size_t j = 0 ; j < pep_info[t].size() ; j++){
            valid_count[pep_info[t][j]]++;
        }
    }

    return ret;
}

void clear_vector(){
    for(int i = 0 ; i < n ; i++){
        pep_info[i].clear();
    }
    for(int i = 0 ; i < m ; i++){
        food_info[i].clear();
    }
}
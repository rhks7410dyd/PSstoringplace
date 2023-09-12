/*
기본적인 구현은 다 된 것 같음. 하지만 휴리스틱 구현을 해야됨.
지금 구현한 것의 문제점은 동일한 사람을 채울 수 있을 때, 가장 앞쪽 인덱스만 선택할 수 있다는 점.
이걸 같은 갯수면 무조건 다 할 수 있게 만들어야 할듯
*/
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
int can_eat_food[50];

int solve(int now);
void clear_vector();
void print_pep_info();
void print_food_info();

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

        int t,max=0;
        for(int i = 0 ; i < m ; i++){
            cin >> t;
            max = min(max,t);
            food_info[i].push_back(t);
            for(int j = 0 ; j < t ; j++){
                cin >> input;
                food_info[i].push_back(m1[input]);
            }
        }

        ans = INF;

        for(int i = 0 ; i < m ; i++){
            if(food_info[i][0] == max){
                ans = min(ans,solve(i));
            }
        }

        cout << ans << '\n';
        clear_vector();
    }

    return 0;
}

int solve(int now){
    for(int i = 0 ; i < n ; i++){
        if(!can_eat_food[i])    break;
        return 0;
        //return 1?
    }

    int ret = INF;

    
}

void clear_vector(){
    for(int i = 0 ; i < n ; i++){
        pep_info[i].clear();
    }
    for(int i = 0 ; i < m ; i++){
        food_info[i].clear();
    }
}

void print_food_info(){
    auto v = food_info;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            cout << v[i][j] << ' ';
        }
    cout << '\n';
    }
}

void print_pep_info(){
    auto v = pep_info;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            cout << v[i][j] << ' ';
        }
    cout << '\n';
    }
}

/*
2
4 6
cl bom dara minzy
2 dara minzy
2 cl minzy
2 cl dara
1 cl
2 bom dara
2 bom minzy
10 7
a b c d e f g h i j
6 a c d h i j
3 a d i
7 a c f g h i j
3 b d g
5 b c f h i
4 b e g j
5 b c g h i
output) 2   1

2
10 7
a b c d e f g h i j
6 a c d h i j
3 a d i
7 a c f g h i j
3 b d g
5 b c f h i
4 b e g j
5 b c g h i
4 6
cl bom dara minzy
2 dara minzy
2 cl minzy
2 cl dara
1 cl
2 bom dara
2 bom minzy

output) 1   1

4
10 7
a b c d e f g h i j
6 a c d h i j
3 a d i
7 a c f g h i j
3 b d g
5 b c f h i
4 b e g j
5 b c g h i
4 6
cl bom dara minzy
2 dara minzy
2 cl minzy
2 cl dara
1 cl
2 bom dara
2 bom minzy
10 7
a b c d e f g h i j
6 a c d h i j
3 a d i
7 a c f g h i j
3 b d g
5 b c f h i
4 b e g j
5 b c g h i
4 6
cl bom dara minzy
2 dara minzy
2 cl minzy
2 cl dara
1 cl
2 bom dara
2 bom minzy

output) 1 1 0 0
*/
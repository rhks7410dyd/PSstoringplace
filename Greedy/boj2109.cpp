#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define INF 987654321

using namespace std;

int n;
vector<pair<int,int>> v;
priority_queue <pair<int,int>> pq;
int have_candidate[10001];

bool compare(pair<int,int>& a,pair<int,int>& b){
    if(a.first == b.first)  return a.second < b.second;
    return a.first > b.first;
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    int a,b;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),compare);

    /*
    1. 자기 날짜 칸이 비어져있다면 그 칸에 값 입력
    2. 자기 날짜 칸이 채워져있다면 '무조건' 더 작은 밸류이기 떄문에 하루 전날에 넣도록 인덱스--
    3. 이 전 날짜도 채워져있다면 미리 적힌 숫자는 '무조건' 더 큰 밸류를 갖기 때문에 얌전히 아래로 내려간다
    4. 빈 날짜가 나올 때까지 반복하다가 0일이 되면 못넣는 숫자라 생각하고 pass 
    */
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        auto& now = v[i];
        if(have_candidate[now.second] != 0){
            int temp = now.second;
            while(temp > 0){
                temp--;
                if(have_candidate[temp] == 0){
                    have_candidate[temp] = now.first;
                }
            }
        }
        else{
            have_candidate[now.second] = now.first;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        ans += have_candidate[i];
    }

    cout << ans << endl;

    return 0;
}

/*
5
3 3
2 3
1 3
100 4
90 4
ans : 195

값을 기준으로 우선순위큐에 넣음
pq의 내부 : {100,4},{90,4},{3,3},{2,3},{1,3}
100,4를 4일 위치에 넣음
90,4를 3일 위치에 넣음
3,3을 2일 위치에 넣음
2,3을 1일 위치에 넣음
-> 195

20
85 8 /
56 11 /
58 12 /
28 20 /
36 12 /
45 9 /
55 4 /
1 3
71 6 /
72 15 /
38 9 /
76 20 /
67 5 /
78 2 /
48 18 /
100 3 /
16 2 /
7 10
95 5 /
42 14 /

ans:1050

최대 날짜 : 20
따라서, 최대로 20개까지 뽑을 수 있음
pq : 100,3/95,5/85,8/78,2/76,20/72,15/71,6/67,5/58,12/56,11/55,4/48,18/45,9/42,14/38,9/36,12/28,20/16,2/7,10/1,3

1       55      4   //
2       78      2      
3       100     3
4       67      5   //
5       95      5
6       71      6
7       38      9   //
8       85      8
9       45      9
10      36      12  //
11      56      11
12      58      12
13
14      42      14
15      72      15
16
17
18      48      18
19      28      20
20      76      20
*/
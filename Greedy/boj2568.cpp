#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

const int SIZE = 100000;

int n;
int smallest_cache[SIZE];
vector<int> cache[SIZE];
vector<pair<int,int>> v;

void Solve();
void Input();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();

    sort(v.begin(),v.end());

    cache[0].push_back(v[0].second);
    smallest_cache[0] = v[0].second;
    for(int i = 1 ; i < n ; i++){
        //continue code...
    }

}

void Input(){
    cin >> n;
    int a,b;
    for(int i = 0 ; i < n ; i++){
        cin a >> b;
        v.push_back({a,b});
    }
}

/*
가장 긴 증가하는 부분 수열
NlogN
vector<int> dp[N];
1. 이분 탐색으로 위치 찾기
2. 
*/


/*
예시 분석
1	1	1
2	2	2
3	3	4
4	4	6
5	6	7
6	7	8
7	9	9
8	10	10

1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

1 6	(5)
3 7	(4)
2 2	(0)
4 1	(3)
5 3	(2)
8 8	(0)
7 5	(2)
6 4	(2)


- 1 6(1 8) 제거 후
2 6	(4)
1 2	(1)
3 1	(2)
4 3	(1)
6 5	(1)
5 4	(1)

-2 6(3 9) 제거 후
1 2	(1)
2 1	(1)
3 3	(0)
5 5	(0)
4 4	(0)

-1 2(4 1) 제거 후
1 1(0)


1. 숫자를 줄여준다 O(N)
2. 가장 편차가 큰 애를 잘라준다. O(NlgN)
3. 자른 애 높이가 a b일 때, A에서 a 초과인 애들 -1 
B에서 b 초과인 애들 -1
4. 높이가 동일해진 애들 삭제 O(N)
5. 모든 전깃줄의 높이가 동일해질 때까지 2로 복귀 
(최악의 경우 N번 반복)

이러면 O(N^2 * lnN)이 되므로 시간초과가 됨 (N <= 100000 이기 떄문)

가장 긴 증가하는 부분 수열로 구현
-> 거기 포함되지 않는 애들은 잘라야되므로 삭제
이러면 NlgN이 됨
[[[*/

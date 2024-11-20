#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 987654321

using namespace std;

int N,vsize;
vector<pair<int,int>> v;

void solve();
void input();
void get_max();

void printvector(){
    for(int i = 0 ; i < vsize ; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
cout << '\n';
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    solve();

    return 0;
}

void solve(){
    input();
    vsize = v.size();
    //printvector();
    get_max();
}

void input(){
    cin >> N;
    int temp;
    for(int i = 0 ; i < N ; i++){
        //continue code...
        cin >> temp;
        if(i == 0 || temp != v[v.size()-1].first){
            v.push_back({temp,1});
        } else{
            v[v.size()-1].second++;
        }
    }
}

void get_max(){
    if(vsize==1){
        cout << v[0].second << endl;
        return;
    }

    int start_point=0,next_point=2;
    int fruit_num[2];
    fruit_num[0] = v[0].first;
    fruit_num[1] = v[1].first;
    int Max = v[0].second+v[1].second;
    int temp = Max;
    while(next_point < vsize){
        if(v[next_point].first == fruit_num[0] || v[next_point].first == fruit_num[1]){
            temp += v[next_point++].second;
        } else{
            start_point = next_point-1;
            temp = v[start_point].second + v[next_point].second;
            fruit_num[0] = v[start_point].first;
            fruit_num[1] = v[next_point++].first;
        }
        Max = max(Max,temp);
    }


    cout << Max << endl;
    
    return;
}

/*
처음에 max 함수를 70번 라인에 뒀다가 맨마지막까지 써야지만 최대 값이 나오는 경우
6
5 2 1 1 3 1
이러한 경우를 못잡았어서 틀렸다가 Max 값을 계속해서 갱신하는 형태로 바꿈
그대로 두고 while 문 밖에다가 max를 한번 더 써도 되는데 그냥 바꿔서 디버깅을 할 경우 좀 더 간편하게 할 수 있게 함

풀이 복귀
메모리 시간 언어 코드 길이
내 풀이
5220	16	C++17	1602

다른 사람 풀이 분석
https://www.acmicpc.net/source/86499406
3472	40	C++17	691
큐를 활용해서 앞에부터 큐에 넣어서 두 종류가 들어가 있는 경우 계속 푸시하고 cnt 함수에 해당 번호 ++, 이후에 만약 3개가 들어갔다면 앞에서부터
하나씩 빼면서 빠진 넘버를 --, 이후 하나가 0이 된 순간(이미 있던 두 종류중 하나가 다 빠진 순간) 빼는 걸 멈추고 다시 푸시 단계로 복귀

https://www.acmicpc.net/source/86489069
3684	12	C++17	525
위의 풀이와 동일 논리지만, arr와 queue를 다르게 둔게 아니라 left,right로 인덱스 번호를 옮기면서 동일 로직으로 진행

https://www.acmicpc.net/source/86467213
2804	16	C++17	633
바로 위와 완전 동일한데 27~28ln의 함축시켜 적어놓은 부분 때문에 조금 더 느린거 같음. 아니면 맨 위의 파트 때문에 조금 더 느린듯
*/
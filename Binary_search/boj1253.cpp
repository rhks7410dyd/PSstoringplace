#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int n;
vector<int> input;

void Solve();
void Input();
bool is_good(int idx);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();

    sort(input.begin(),input.end());

    int cnt = 0;
    for(int i = n-1 ; i >= 0 ; i--){
        //continue code...

        if(is_good(i))   cnt++;
    }

    cout << cnt << endl;
}

void Input(){
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        //continue code...
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
}

bool is_good(int idx){
    int le = 0,ri = n-1, temp;
    while(le < ri && le >= 0 && ri < n){
        temp = input[le] + input[ri];
        if(temp == input[idx] && idx != ri && idx != le ){
            //cout << idx << ':' << le << '&' << ri << ' ' << input[le] << " + " << input[ri]  << " = " << input[idx] << endl;
            return true;
        }
        else if(temp > input[idx])  ri--;
        else if(temp < input[idx])  le++;
        else if(idx == ri){
            if((input[idx] == input[ri-1] && ri-le!=1)||(ri+1 != n && input[idx] == input[ri+1]))   return true;
            ri--;
        }
        else{
            if((input[idx] == input[le+1] && ri-le!=1)||(le != 0 && input[idx] == input[le-1]))   return true;
            le++;
        }
    }
    return false;
}

/*
괜히 엄청 어렵게 구현한 느낌이 강함. else if를 이렇게 박을 필요는 없었을 것 같은데, 처음에 동일한 수가 있거나 양쪽 끝 인덱스,
양수와 음수에 대한 고려가 전혀 없었어서 반례 찾는라 너무 여러 번 시도함
2160	16	C++17 / 수정	1512

https://www.acmicpc.net/source/86675199
2168	212	C++17	1046
upper_bound,lower_bound, map을 활용해서 풀이함. 사용 가능한 stl 함수를 다 써서 편하게 한 느낌이 강함.

https://www.acmicpc.net/source/86675436
2028	12	C++17	676
위의 코드와 동일한 분이 제출한 코드. 사실 가장 정석적인 코드일 것 같아서 더 안봐도 될듯. 난 애매하게 다 쪼개놨는데 그냥 이렇게만 쪼개도 됐었을 듯.
4ms의 차이가 구현에서 else if를 많이 사용하면서 생긴 지연으로 추측됨.
*/
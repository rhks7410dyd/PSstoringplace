#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

vector<int> input_num;
vector<pair<int,int>> target_num;
bool ans[500000];
int n,m;

void Solve();
void Input();
int find_num(int le,int target_num);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();

    sort(input_num.begin(),input_num.end());
    sort(target_num.begin(),target_num.end());

    int start_pos=0;
    for(int i = 0 ; i < m ; i++){
        //continue code...
        int find = find_num(start_pos,target_num[i].first);

        if(find != -1){
            ans[target_num[i].second] = true;
            start_pos = find;
        }
    }

    for(int i = 0 ; i < m ; i++){
        //continue code...
        cout << ans[i] << ' ';
    }
    cout << endl;

    return;
}

void Input(){
    int temp;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        //continue code...
        cin >> temp;
        input_num.push_back(temp);
    }

    cin >> m;
    for(int i = 0 ; i < m ; i++){
        //continue code...
        cin >> temp;
        target_num.push_back({temp,i});
    }
}

int find_num(int le,int target_num){
    int ri = n;
    while(le < ri){
        int mid = (le+ri)/2;
        if(input_num[mid] == target_num)    return mid;
        else if(input_num[mid] > target_num)    ri = mid;
        else    le = mid+1;
    }

    return -1;
}

/*
10836	220	C++17 / 수정	1508
pair를 이용해서 시간을 줄여보려한건데 비슷한 시간대 다수 존재함 + 메모리가 좀 많이 추가된듯

https://www.acmicpc.net/source/86423682
41212	428	C++17   	539
무지성 unorderd_map으로 품. 이것보다는 그래도 내가 효율이 나옴

https://www.acmicpc.net/source/86423804
3976	208	C++17	895
하나씩 입력 때마다 분할 탐색을 실행한 경우인데 시간이 비슷하게 나옴.

https://www.acmicpc.net/source/86574430
5220	204	C++17	479	
STL에 binary_search도 구현되어 있나봄..진짜 이런건 나중에 코테 볼때 한번 정리하면서 암기해야될듯

https://www.acmicpc.net/source/86558534
41212	468	C++17	464
이 사람도 unordered_map을 사용함
*/
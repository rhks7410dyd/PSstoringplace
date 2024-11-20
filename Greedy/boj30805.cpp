#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
#define INF 987654321

using namespace std;

int n_a,n_b,cnt=0;
int arr_a[100];
int arr_b[100];

void Solve();
void Input();
string GetAns(int start_a,int start_b);
int find_fastest_target_num(int start,int target,bool is_arr_a);

void printarray(){
    cout << "==============Array A==============\n";
    for(int i = 0 ; i < n_a ; i++){
        cout << arr_a[i] << endl;
    }
    cout << "==============Array B==============\n";
    for(int i = 0 ; i < n_b ; i++){
        cout << arr_b[i] << endl;
    }
}

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .
    Solve();

    return 0;
}

void Solve(){
    Input();
    //printarray();
    string ans = GetAns(0,0);
    cout << cnt << endl << ans << endl;
    return;
}

void Input(){
    cin >> n_a;
    for(int i = 0 ; i < n_a ; i++){
        //continue code...
        cin >> arr_a[i];
    }
    
    cin >> n_b;
    for(int i = 0 ; i < n_b ; i++){
        //continue code...
        cin >> arr_b[i];
    }    
}

string GetAns(int start_a,int start_b){
    if(start_a >= n_a || start_b >= n_b)    return "";
    for(int i = 100 ; i > 0 ; i--){
        //continue code...
        int target_a = find_fastest_target_num(start_a,i,true);
        int target_b = find_fastest_target_num(start_b,i,false);
        if(target_a != -1 && target_b != -1){
            cnt++;
            return to_string(i) + " " + GetAns(target_a+1,target_b+1);
        }
    }
    return "";
}

int find_fastest_target_num(int start,int target,bool is_arr_a){
    int* arr;
    int N;
    if(is_arr_a){
        arr = arr_a;
        N = n_a;
    }
    else{
        arr = arr_b;
        N = n_b;
    }

    for(int i = start ; i < N ; i++){
        //continue code...
        if(arr[i] == target)    return i;
    }

    return -1;
}


/*
그리드 문제라 시간은 대부분 0ms나옴
2024	0	C++17 / 수정	1902

https://www.acmicpc.net/source/86536833
2024	0	C++17	743
나보다 좀 더 직관적으로 코드를 짜고 더 간편함
c++ STL에 있는 함수를 기본적으로 나보다 더 잘 파악하고, 사용하는 느낌이 들었음. 벡터의 최대값 원소를 찾는 함수가 있는지 처음 알게됨

https://www.acmicpc.net/source/86497219
2020	0	C++17	2111
이 사람은 9의 개수와 마지막 위치, 8의 개수와 마지막 위치, 이런 식으로 쭉 찾은 이후에 거기에 겹쳐서 쓰는? 느낌이었던거 같음. 
사실 나보다 코드가 난해해서 이해가 쉽지만은 않음.
예를 들어, a에는 9가 3개, b에는 2개가 있다면 두 개의 2번째 9의 위치를 찾아서 거기까지 컷 하고 이후에서 다시 8부터 시작하고 이런 느낌의 알고리즘 같음

*/
#include <iostream>
#include <algorithm>
#define endl '\n'
#define INF 987654321

using namespace std;

int n_a,n_b;
int arr_a[100];
int arr_b[100];

void Solve();
void Input();
void GetAns();
int find_max_num(int idx,int lmt);

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
    GetAns();
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

void GetAns(){
    cout << "GetAns\n";
}

int find_max_num(int idx,int lmt){
    int Max = 1;
}
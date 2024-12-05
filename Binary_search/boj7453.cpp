#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define endl '\n'

using namespace std;

int n;
vector<int> input[4];
vector<int> merging[2];

void Solve();
void Input();
void sort_and_merging();
int get_ans();

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}
 
void Solve(){
    Input();

    sort_and_merging();

    cout << get_ans() << endl;
}

void sort_and_merging(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            //continue code...
            merging[0].push_back(input[0][i] + input[1][j]);
            merging[1].push_back(input[2][i] + input[3][j]);
        }
    }

    sort(merging[0].begin(), merging[0].end());
    sort(merging[1].begin(), merging[1].end());
}

void Input(){
    cin >> n;
    int temp;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 4 ; j++){
            //continue code...
            cin >> temp;
            input[j].push_back(temp);
        }
    }
}

int get_ans(){
    /*
    if 문을 통해서 이전 인덱스 값과 지금 값이 같다면 그걸 그대로 가져와주는 형태의 코드를 생각해봤는데,
    이렇게 했을 때, 실행횟수가 n^2만큼 추가가 된다. 따라서 n^2+p*log(n)만큼 실행하게 됨. (p는 이분탐색 실행 횟수)
    반면 무조건적으로 이분탐색을 돌린다면, n^2*log(n)이 되는건가?
    */
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        //continue code...
        int left = 0, right = n*n, mid;
        while(left < right){
            mid = (left + right)/2;
            if(merging[1][mid] < -merging[0][i]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
    }

    return ans;
}
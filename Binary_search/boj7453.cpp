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
void printvector();
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

    //printvector();

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

void printvector(){
    auto v = merging;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            cout << v[i][j] << ' ';
        }
    cout << '\n';
    }
}

int get_ans(){
    /*
    문제에서 무작위 숫자로 해도 되는 형태로 입력이 주어지는 경우에 시간초과가 나는듯함.
    예를 들어
    -1 0 1 0
    으로 n개 입력 받으면
    n^4이 되버려서 문제가 생기는듯
    이러면 결국 동일한 merging 값을 하나에 저장하고 이걸 카운트하는 형태가 되어야될듯
    단순하게 생각하면 머징을 한 뒤에 필터링을 통해 압축하는 형태로 변경되어야됨.
    맵을 사용한다면 간단하지만 맵을 사용했을 때 맵에 접근하는 경우에 시간이 너무 많이 소요되서 안좋을 수도 있을 듯
    */
    int ans = 0;
    for(int i = 0 ; i < n*n ; i++){
        //continue code...
        int target_num = -merging[0][i];
        int left = 0, right = n*n, mid;
        while(left < right){
            mid = (left + right)/2;
            if(target_num > merging[1][mid]){
                left = mid + 1;
            }
            else if(target_num < merging[1][mid]){
                right = mid;
            }
            else{
                ans++;
                int temp = mid;
                while(true){
                    if(temp > 0 && target_num == merging[1][--temp]) ans++;
                    else    break;
                }
                while(true){
                    if(mid < n*n-1 && target_num == merging[1][++mid]) ans++;
                    else    break;
                }
                break;
            }
        }
    }

    return ans;
}
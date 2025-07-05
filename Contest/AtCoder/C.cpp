#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;
    while(C--){
        //continue code. . .
        int n;
        vector<int> over_size;
        int temp,leftest_domino_size,final_domnino_size;
        int max_size_now = -1;

        cin >> n;

        cin >> leftest_domino_size;
        for(int i = 0 ; i < n-2 ; i++){
            //continue code...
            cin >> temp;
            if(leftest_domino_size*2 < temp){
                over_size.push_back(temp);
            }
            else{
                if(max_size_now < temp) max_size_now = temp;
            }
        }
        cin >> final_domnino_size;

        int cnt = 2;
        
        do {
            //cout << "cnt : " << cnt << "\tmax_size_now : " << max_size_now << endl;

            vector<int> temp_arr;
            int temp_max = -1;
            for(int i = 0 ; i < over_size.size() ; i++){
                //continue code...
                if(max_size_now*2 >= over_size[i]){
                    if(temp_max < over_size[i]) temp_max = over_size[i];
                }
                else{
                    temp_arr.push_back(over_size[i]);
                }
            }

            //cout << "temp_max : " << temp_max << endl;

            if(temp_max == -1){
                //더 이상 가능한 애가 없음
                cnt = -2;
                break;
            }

            max_size_now = temp_max;
            over_size.clear();
            for(int i = 0 ; i < temp_arr.size() ; i++){
                //continue code...
                over_size.push_back(temp_arr[i]);
            }
            temp_arr.clear();
            cnt++;
        } while(max_size_now*2 < final_domnino_size);

        if(max_size_now < final_domnino_size)   cnt++;

        cout << cnt << endl;
    }
    return 0;
}
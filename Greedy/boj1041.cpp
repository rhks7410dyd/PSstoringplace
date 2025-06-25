#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    int dice[6];
    int dice_combo[12];
    int dice_triple[8];
    int max_num=-1,sum=0,min_num = 9999;

    for(int i = 0 ; i < 6 ; i++){
        cin >> dice[i];
        sum += dice[i];
        if(max_num < dice[i])   max_num = dice[i];
    }

    if(N == 1){
        cout << sum - max_num << endl;
    }
    else{
        string combo = "01 02 03 04 12 13 15 24 25 34 35 45 ";
        int idx=0;
        for(int i = 0 ; i < 12 ; i++){
            //continue code...
            dice_combo[i] = dice[combo[idx]-'0'];
            dice_combo[i] += dice[combo[++idx]-'0'];
            idx += 2;
            cout << dice_combo[i] << ' ';
        }
        cout << endl;

        string triple = "012 013 024 034 125 135 245 345 ";
        idx = 0;
        for(int i = 0 ; i < 8 ; i++){
            //continue code...
            dice_triple[i] = dice[triple[idx]-'0'];
            dice_triple[i] += dice[triple[++idx]-'0'];
            dice_triple[i] += dice[triple[++idx]-'0'];
            idx += 2;
            cout << dice_triple[i] << ' ';
        }
        cout << endl;
        
        sort(dice,dice+6);
        sort(dice_combo,dice_combo+12);
        sort(dice_triple,dice_triple+8);
        long long answer = (long long)(N-2)*(5*N-6)*dice[0];
        answer += (8*N-4)*dice_combo[0];
        answer += 4*dice_triple[0];
        cout << answer << endl;
    }

    return 0;
}

/*


*/
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //continue code. . .

    string temp;
    map<string,int> cnt;
    vector<string> species;
    int n = 0;

    while(getline(cin,temp)){
        n++;
        if(cnt[temp] > 0){
            cnt[temp]++;
        }
        else{
            species.push_back(temp);
            cnt[temp] = 1;
        }
    }

    sort(species.begin(),species.end());

    int sepcies_size = species.size();

    cout << fixed;
    cout.precision(4);

    for(int i = 0 ; i < sepcies_size ; i++){
        //continue code...
        string now_species = species[i];
        cout << now_species << ' ' << ((double)cnt[now_species]/n)*100 << endl;
    }

    return 0;
}
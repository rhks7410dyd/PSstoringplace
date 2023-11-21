//테스트 케이스 다 틀려버림
#include <iostream>
#include <vector>
#define endl '\n'
#define INF 987654321

using namespace std;

struct line{
    pair<int,int> dot1;
    pair<int,int> dot2;
};

const int SIZE = 3000;

line info[SIZE];
int Uni[SIZE];
int cnt[SIZE];
int n;

int CCW(pair<int,int>& a,pair<int,int>& b,pair<int,int>& c);
int get_root(int num);
void merge_root(int a,int b);
bool is_same_root(int a,int b);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int x1,x2,y1,y2;
    for(int i = 0 ; i < n ; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        info[i] = {{x1,y1},{x2,y2}};
        Uni[i] = i;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int b1 = CCW(info[i].dot1,info[i].dot2,info[j].dot1)*CCW(info[i].dot1,info[i].dot2,info[j].dot2);
            int b2 = CCW(info[j].dot1,info[j].dot2,info[i].dot1)*CCW(info[j].dot1,info[j].dot2,info[i].dot2);
            if(b1 <= 0 && b2 <= 0){
                if(b1 == 0 && b2 == 0){
                    if((info[i].dot1.first - info[j].dot1.first)*(info[i].dot2.first-info[j].dot2.first) < 0){
                        continue;
                    }
                }
                merge_root(i,j);
            }
        }
    }

    int group_num = 0,largest_num = -1;
    for(int i = 0 ; i < n ; i++){
        cnt[get_root(i)]++;
    }

    for(int i = 0 ; i < n ; i++){
        if(cnt[i] != 0){
            group_num++;
            largest_num = largest_num > cnt[i] ? largest_num : cnt[i];
        }
    }

    cout << group_num << endl << largest_num << endl;

    return 0;
}

int CCW(pair<int,int>& a,pair<int,int>& b,pair<int,int>& c){
    int ans = (b.first - a.second)*(c.second - a.second) - (b.second - a.second)*(c.first - a.first);
    if(ans < 0)    return -1;
    else if(ans > 0)    return 1;
    return 0;
}

int get_root(int num){
    if(Uni[num] == num) return num;
    return Uni[num] = get_root(Uni[num]);
}

void merge_root(int a,int b){
    if(Uni[a] != a) a = get_root(a);
    if(Uni[b] != b) b = get_root(b);

    Uni[a] = b;
}

bool is_same_root(int a,int b){
    if(Uni[a] != a) a = get_root(a);
    if(Uni[b] != b) b = get_root(b);

    return a==b;
}

/*
1. 예외처리 부분 완료하기
2. 각 유니온 그룹당 갯수 세기(한번에 세는 것보다 합칠 때 세는게 더 빠름)
3. 반복문으로 그룹 개수 세기(그룹당 원소 개수가 0이 아닌 그룹의 수)

CCW 알고리즘
CCW(A, B, C) * CCW(A, B, D) <= 0 && CCW(C, D, A) * CCW(C, D, B) <= 0이면 교차함
예외 처리 동일 직선인 경우만 해결해주면 됨
*/
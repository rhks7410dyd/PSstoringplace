#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#define endl '\n'

using namespace std;

int n, r, q;

struct node{
    int parent;
    int tot=0;
    vector<int> linked_node;
};

node nodes[100001];

void Input();
int DFS(int root,int parent);

int main(){
    cin.tie(NULL);	cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Input();

    DFS(r,-1);

    for(int i = 0 ; i < q ; i++){
        int temp;
        cin >> temp;
        cout << nodes[temp].tot << endl;
    }

    return 0;
}

void Input(){
    cin >> n >> r >> q;
    int a, b;
    for(int i = 0 ; i < n-1 ; i++){
        cin >> a >> b;
        nodes[a].linked_node.push_back(b);
        nodes[b].linked_node.push_back(a);
    }
}

int DFS(int root, int parent){
    nodes[root].tot = 1;
    auto linked_node = nodes[root].linked_node;
    int edge_size = linked_node.size();
    for(int i = 0 ; i < edge_size ; i++){
        if( linked_node[i] != parent){
            nodes[root].tot += DFS(linked_node[i], root);
        }
    }

    return nodes[root].tot;
}

/*
내 제출
rhks7410dyd	 15681	맞았습니다!!	19172	68	C++17 / 수정	1082

14684	88	C++17	882
완전 동일한 풀이인데 vector를 많이 써서 조금 더 느린듯 함. 대신에 struct로 안 감싸서 메모리 사용량은 더 적은듯

10928	52	C++20	799
1. 방문 노드를 visited로 처리하는 게 확실히 메모리 사용량에서 참조 변수로 던지는 것보다 적게 든다.
2. 나머지는 거의 scanf,printf로 인한 속도 차이 수준인듯함

*/
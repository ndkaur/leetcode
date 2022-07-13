#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class SmallestInfiniteSet {
public:
//  min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> isPresent;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            pq.push(i);
        }
        isPresent= vector<bool>(1001,true);
    }
    
    int popSmallest() {
        int small= pq.top();
        pq.pop();
        isPresent[small]= false;
        return small;
    }
    
    void addBack(int num) {
        if(isPresent[num]==false){
            pq.push(num);
            isPresent[num]= true;
        }
    }
};

int main(){

    return 0;
}
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

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<long long> pq;
        for(auto gift:gifts){
            pq.push(gift);
        }
        long long ans=0;

        while(k--){
            long long t = sqrt(pq.top());
            pq.pop();
            pq.push(t);
        }

        while(pq.size()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};

// gifts = [25,64,9,4,100], k = 4
// pq -> 100, 64, 25, 9, 4
// pq till-> k= 1  {64, 25, 10 , 9 , 4}
// k=2  { 25, 10, 9, 8 ,4}
//  k= 3 { 10, 9, 8 , 5 , 4}
// k=4   {9,8,5,3,4} = 29



int main(){

    return 0;
}
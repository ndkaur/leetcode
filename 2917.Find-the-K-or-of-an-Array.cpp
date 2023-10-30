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
    int findKOr(vector<int>& nums, int k) {
        int sum =0;
        for(int i=0; i<32; i++){
            int cnt = 0;
            // cehcking each bit for each num 
            for(int num:nums){
                if(num & (1<<i))
                    cnt++;
            }
            if(cnt>=k) // 2^ set bit
                sum += pow(2,i);
        }
        return sum;
    }
};

// find if no of set bits at same index in more than k elemts
// 7  -> 0111
// 12->  1100
// 9->   1001
// 8->   1000
// 9->   1001
// 15 -> 1111


int main(){

    return 0;
}
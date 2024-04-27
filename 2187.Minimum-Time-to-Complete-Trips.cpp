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
    long long minimumTime(vector<int>& time, int total) {
        int n = time.size();

        long long left = 1;
        int mx = *max_element(time.begin(), time.end());
        long long right = 1LL * mx * total;

        long long ans = 0;

        while(left <= right){
            long long mid = left + (right-left)/2;
            if(possible(mid, total, time)){
                ans = mid;
                right = mid-1; // try reducing it to get min time
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }

    bool possible(long long mid, int total, vector<int>& time){
        long long sum = 0;
        for(int t:time){
            sum += mid/t;
        }
        return sum >= total; // return true;
    }
};


int main(){

    return 0;
}


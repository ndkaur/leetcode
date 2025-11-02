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
    bool isPossible(long long time, vector<int>& d, vector<int>& r){
        // time when each drone can deliver is when its not recharging
        // we have to check if drone can deliver in the given time or not
        // when its a factor of r, it can deliver , so we check how many hours are those ie time/r[0] = val

        // time (mid) - time when cant deliver
        // no fo days when deliver = total days - days not aavilbele
        // true when days availbe > days requied[d0]
        long long t1 = time - time/r[0];
        long long t2 = time - time/r[1];
        // checking if can deliver individualy 
        if(d[0]>t1 || d[1]>t2)
            return false;

        long long both_can_do = time/lcm(r[0],r[1]);
        return d[0]+d[1]<=time-both_can_do;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        
        // binary serach 
        long long l = 0;
        long long h = 1e18;
        long long ans = -1;

        while(l<=h){
            long long mid = l+(h-l)/2;
            if(isPossible(mid, d, r)){
                ans = mid;
                h = mid-1;
            }
            else 
                l= mid+1;
        }
        return ans;
    }
};

// drone can deliver in hours not divisible by r[i]
// so cant deliver in hours divisible by r[i] where reminder is zero
// 

// 1-> 1
// 3 -> 3 5 7 

// 2-> 1 2
// 1-> 3

// drone can deliver in hours not divisible by r[i]
// so cant deliver in hours divisible by r[i] where reminder is zero
// 

// 1-> 1
// 3 -> 3 5 7 

// 2-> 1 2
// 1-> 3


int main(){

    return 0;
}
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
    bool isPossible(vector<int>& candies, long long k, long long mid){
        int  n = candies.size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += candies[i]/mid;
        }
        return sum>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;
        for(int can:candies){
            sum += can;
        }
        if(sum<k)   
            return 0;

        long long l = 1;
        long long  h = *max_element(candies.begin(), candies.end());
        long long  ans = 0;
        while(l<=h){
            long long  mid = l+(h-l)/2;
            if(isPossible(candies, k, mid)){
                ans = mid;
                l = mid+1;
            }
            else 
                h = mid-1;
        }
        return  (int)ans;
    }
};

int main(){

    return 0;
}
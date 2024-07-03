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
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        int times = n/2;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n-1;
        
        double mini = DBL_MAX;
        for(int t=1; t<=times; t++){
            double mn = nums[i];
            double mx = nums[j];
            double avg = (mn+mx)/2.0;
            i++;
            j--;
            mini = min(mini, avg);
        }
        return mini;
    }
};

int main(){

    return 0;
}
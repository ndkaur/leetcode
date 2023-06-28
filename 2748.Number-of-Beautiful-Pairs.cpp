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
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        int first, last;
        for(int i=0; i<n; i++){
            while(nums[i]){
                first = nums[i]%10;
                nums[i] = nums[i]/10;
            }
            for(int j=i+1; j<n; j++){
                last = nums[j]%10;
                if(__gcd(first,last)==1)
                    cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}
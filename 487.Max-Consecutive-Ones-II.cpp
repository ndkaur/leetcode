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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int  n=  nums.size();
        int i =0;
        int j =0;
        int mx =0; 
        int zcnt=0;

        while(j<n){
            if(nums[j]==0 ){
                zcnt++;
            }
            while(zcnt>1){
                if(nums[i]==0)
                    zcnt--;
                i++;
            }
            
            mx = max(mx, j-i+1);
            j++;
        }
        return mx;
    }
};


int main(){

    return 0;
}
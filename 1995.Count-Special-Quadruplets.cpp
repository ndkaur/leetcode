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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    for(int f=k+1;f<n;f++){
                        if(i<j && j<k && k<f && nums[f]==sum){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};


int main(){

   return 0;
}
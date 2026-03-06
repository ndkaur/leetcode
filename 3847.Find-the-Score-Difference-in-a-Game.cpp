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
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int second = 0;
        bool f = true;
        for(int i=0; i<n; i++){
            if(nums[i]%2==1){
                f = !f;
            }
            if((i+1)%6==0){
                f = !f;
            }
            if(f==true){
                first +=nums[i];
            }
            else{
                second+= nums[i];
            }
        }
        return first-second;
    }
};


int main(){

    return 0;
}
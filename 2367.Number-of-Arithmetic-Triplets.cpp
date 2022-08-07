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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n= nums.size();
        int cnt=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int dif1= nums[k]- nums[j];
                    int dif2= nums[j]-nums[i];
                    if(dif1==diff && dif2==diff)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}
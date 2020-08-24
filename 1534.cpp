#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int count=0;

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    count+= (is_good(arr[i],arr[j],arr[k],a,b,c));
                }
            }
        }
        return count;
    }
        bool is_good(int x,int y,int z,int a,int b,int c){
            bool one = (abs(x-y) <=a);
            bool two= (abs(y-z)<=b);
            bool three =(abs(z-x)<=c);

            return (one && two && three);
        }
};


int main(){
    Solution sol;
    vector<int> arr= {1,1,2,2,3};
    int a=0,b=0,c=1;
    int ans=sol.countGoodTriplets(arr,a,b,c);
    cout<<ans;
    return 0;
}
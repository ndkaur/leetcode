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

// [[1,5],[10,4],[4,3]]
// [[1,5],[4,3],[10,4]]

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
         int n= prop.size();
         sort(prop.begin(),prop.end());
         int count=0;
         int prev=INT_MIN;
         for(int i=0;i<n;i++){
            if(prop[i][1]>prev)
                  count++;
            prev= max(prev,prop[i][1]);
         }
         return count;
    }
    static bool comp(vector<int>&a, vector<int> & b ){
            if(a[0]==b[0])
               return a[1]>b[1];
            return a[0]<b[0]; // assending order acc to first element
    }
};


int main(){
      Solution sol;
      vector<vector<int>> nums={{1,5},{10,4},{4,3}};
      int ans = sol.numberOfWeakCharacters(nums);
      cout<<ans;
      return 0;
}
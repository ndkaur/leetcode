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
    vector<int> findOriginalArray(vector<int>& c) {
        int n= c.size();
        if(n<=1) return {};
        vector<int> ans;
        map<int,int> mp;
        for(int i:c)
            mp[i]++;
		int zcnt = mp[0];
		if(zcnt%2==0){ //even 
			for(int i=0;i<(zcnt/2);i++)
				ans.push_back(0);
		}
		else  // odd
			return {};
        sort(c.begin(),c.end());
        
        for(int i=n-1;i>=0;i--){
            if(c[i]==0 || mp[c[i]]==0){
                  continue;
            }
			if((c[i]%2)!=0) return {}; //no is odd
            if(mp.count(c[i]/2) && mp[c[i]/2]>0){
                ans.push_back(c[i]/2);
                mp[c[i]/2]--;
                mp[c[i]]--;
            }
            else 
                return {};
        }
        return ans;
    }
};

int main(){
      Solution sol;
      vector<int> c={18,20,1,4,2,8,6,1,2,9};
      vector<int> ans =sol.findOriginalArray(c);
      print(ans);
      return 0;
}
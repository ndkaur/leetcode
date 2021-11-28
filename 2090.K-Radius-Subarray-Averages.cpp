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

class Solution0 {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n= nums.size();
		vector<int> ans(n);
		if(k==0) return nums;
		if(k>n) return {-1};
		for(int i=0;i<n;i++){
			if(k>i){
				ans[i]=-1;
			}
			if(i+k>n-1) ans[i]=-1;
			else if(k<=i && i+k<n){
				int sum=0;
				for(int j=i-k;j<=i+k;j++){
					sum+=nums[j];
				}
				int avg= sum/(2*k+1);
				ans[i]=avg;
			}
		}
		return ans;
    }
}; // time limit exceeded 

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n= nums.size();
		vector<int> ans(n,-1);
		if(2*k+1>n) return ans;
		long long int sum=0;
		// first window
		for(int i=0;i<2*k+1;i++){
			sum+=nums[i];
		}
		ans[k]=sum/(2*k+1);
		// start sliding
		for(int i=2*k+1,j=k+1,s=0;i<n;i++,j++,s++){
			sum+= nums[i];
			sum-= nums[s];
			ans[j]=sum/(2*k+1);
		}
		return ans;
    }
};


int main(){
	Solution sol;
	vector<int> nums={7,4,3,9,1,8,5,2,6};
	int k=3;
	vector<int> ans =sol.getAverages(nums,k);
	print(ans);
   return 0;
}
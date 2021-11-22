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
    int maxDistance(vector<int>& colors) {
        int n= colors.size();
        int ans1 =0;
        int i=0,j=n-1;
        while(colors[i]==colors[j]){
            j--;
        }
        if(colors[i]!=colors[j]){
            ans1= abs(i-j);
        }
        int s=0,l=n-1;
        int ans2=0;
        while(colors[s]==colors[l]){
            s++;
        }
        if(colors[s]!=colors[l]){
            ans2 = abs(s-l);
        }
        int a=0;
        a= max(ans1,ans2);
        return a;
    }
};

class Solution {
public:
      int maxDistance(vector<int>& A) {
            int n = A.size();
            int i=0, j=n-1;
            while (A[0] == A[j]) j--;
            while (A[n - 1] == A[i]) i++;
            return max(n-1-i, j);
      }
};

int main(){
	Solution sol;
	vector<int> colors= {1,1,1,6,1,1,1};
	int ans = sol.maxDistance(colors);
	cout<<ans;
	return 0;
}
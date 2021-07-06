#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

class Solution0 {
public:
    bool isUgly(int n) {
        if(n==1) return true;
        if(n<=0) return false;
        for(int i=2;i<6;i++){
            while(n%i==0){
                n /= i;
            }
        }
        return n==1; // if true 
    }
};

class Solution1 {
public:
   bool isUgly(int num) {
	if (num <= 0)
		return false;
    if (num % 5 == 0)
	   return isUgly(num / 5);
	else if (num % 3 == 0)
	   return isUgly(num / 3);
	else if (num % 2 == 0)
	   return isUgly(num / 2);
    if (num == 1)
		return true;
	return false;
   }
};


int main(){
    Solution sol;
    int n=17;
    bool ans = sol.isUgly(n);
    cout<<ans;
    return 0;
}
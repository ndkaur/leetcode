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
    int divisorSubstrings(int num, int k) {
        string temp= to_string(num);
        int count=0;
        // if(temp.size()==1) return 1;
        for(int i=0;i<=temp.size()-k;i++){
            string s=temp.substr(i,k);
            int n= stoi(s);
            if(n!=0 && num%n==0){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    int num=10;
    int k=1;
    int ans= sol.divisorSubstrings(num,k);
    cout<<ans;
    return 0;
}
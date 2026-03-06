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
    int minimumDeletions(string s) {
        int n = s.size();
        
        vector<int> b_before(n,0);
        b_before[0]= s[0]=='b';

        vector<int> a_after(n,0);
        // a cnt int the full reminaing array 
        a_after[0] = count(s.begin(), s.end(), 'a');

        for(int i=1; i<n; i++){
            b_before[i] = b_before[i-1] + (s[i]=='b');
            // a cnt after the current idx, and we are going in i=0->n , so for idx=0 its precalucalted, and if and a is encoutered we subatract it 
            a_after[i] = a_after[i-1] - (s[i-1]=='a');
        }

        int ans = n;
        for(int i=0; i<n; i++){
            ans = min(ans, b_before[i]+a_after[i]-1);    
        }
        return ans;
    }
};



int main(){

    return 0;
}
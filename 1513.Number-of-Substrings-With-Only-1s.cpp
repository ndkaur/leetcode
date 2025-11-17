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
    int mod = 1e9+7;
    int numSub(string s) {
        int n = s.size();
        int i =0;
        int j =0;
        int cnt = 0;
        while(j<n){
            while(s[j]=='0'){
                j++;
            }
            i=j;

            while(s[j]=='1'){
                cnt = (cnt+j-i+1)%mod;
                j++;
            }
        }   
        return cnt;
    }
};


class Solution {
public:
    int mod = 1e9+7;
    int numSub(string s) {
        int n = s.size();
        s+='0';
        int cnt =0;
        int ans = 0;
        for(auto ch:s){
            if(ch=='0'){
                ans = (ans+(cnt*1LL*(cnt+1))/2)%mod;
                cnt=0;
            }
            else  // when consecutive ones exist 
                cnt++;
        }
        return ans;
    }
};


int main(){

    return 0;
}



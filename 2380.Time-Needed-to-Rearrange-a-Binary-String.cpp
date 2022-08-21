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
    int secondsToRemoveOccurrences(string s) {
        int n= s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<n-1;j++){
                if(s[j]=='0' && s[j+1]=='1'){
                    s[j]='1';
                    s[j+1]='0';
                    flag = true;
                    j++;
                }
            }
            if(flag) 
                cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n= s.size();
        int cnt=0;
        int f=1;
        while(f){
            f=1;
            for(int i=0;i<n; i++){
                if(s[i]=='0' && s[i+1]=='1' && i+1<n){
                    swap(s[i],s[i+1]);
                    i++;
                    f=0;
                }
            }
            f= 1-f;
            cnt++;
        }
        return cnt-1;
    }
};



int main(){
    Solution sol;
    string s="0110101";
    int ans = sol.secondsToRemoveOccurrences(s);
    cout<<ans<<endl;
    return 0;
}
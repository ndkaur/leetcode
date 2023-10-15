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
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int cnt =0;
        string ans('0',100);
        int mn = INT_MAX;
        int i=0;
        int j=0;
        
        while(j<n){
            if(s[j]=='1')
                cnt++;
            while(s[i]=='0' || cnt>k){
                if(s[i]=='1')
                    cnt--;
                i++;
            }
            if(cnt==k){ // cnt>=k
                int len = j-i+1;
                string temp = s.substr(i, len);
                if(len<mn){
                    mn = len;
                    ans = temp;
                }
                else {
                    if(mn==len){
                        if(ans>temp){
                            ans = temp;
                        }
                    }
                }
            }
            j++;
        }
        
        return mn==INT_MAX ? "":ans;
    }
};


class Solution0 {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int len = n+1;
       for(int i=0; i<n; i++){
           int cnt=0;
           for(int j=i; j<n; j++){
               if(s[j]=='1'){
                   cnt++;
               }
               if(cnt==k && j-i+1<len){
                   len = j-i+1;
                   break;
               }
           }
       }
       // now we need to find smaller valid len than the curr valid len
        string ans ="";
        for(int i=0; i<n; i++){
            int cnt =0;
            for(int j=i; j<n; j++){
                if(s[j]=='1'){
                    cnt++;
                }
                if(cnt==k && j-i+1==len){
                    if(ans==""){
                        ans= s.substr(i, j-i+1);
                    }
                    else 
                        ans= min(ans, s.substr(i,j-i+1));
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}
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



// brute force
class Solution0 { 
public:
    int strStr(string hay, string needle) {
        int n = hay.size();
        int m = needle.size();
        for(int i=0; i<=n-m; i++){
            int j =0 ;
            for(; j<m; j++){
                if(hay[i+j]!=needle[j])
                    break;
            }
            if(j==m)
                return i;
        }
        return -1;
    }
};

// kmp
class Solution { 
public:
    void computeLps(string& needle, vector<int>& lps){
        int n = needle.size();
        int len = 0;
        int i = 1;
        while(i<n){
            if(needle[i]==needle[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string hay, string needle) {
        int n = hay.size();
        int m = needle.size();
        if(!m)  
            return 0;

        vector<int> lps(m,0);
        computeLps(needle, lps);
        int i = 0;
        int j = 0;
        while(i<n){
            if(hay[i]==needle[j]){
                i++;
                j++;
                if(j==m){
                    return i-j;
                }
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};



// haystack = "leetcode", needle = "leeto"
//  haystack = "sadbutsad", needle = "sad"
class Solution {
public:
    int strStr(string hay, string needle) {
        int n = hay.size();
        int m = needle.size();
        int s = 0; 
        int e = 0;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            cnt = 0;
            if(hay[i] == needle[0]){
                s = i;
                e = i;
                // check remaining chars of needle
                for(auto ch:needle){
                    if(hay[e] != ch)
                        break;
                    cnt++;
                    e++;
                }
                if(cnt == m)
                    return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string hay, string needle) {
        int n= hay.size();
        int m = needle.size();
        if(n<m) 
            return -1;
        int i =0;
        int j=0;
        while(i<n){
            if(hay[i]!=needle[j])
                i++;
            else{
                int ans =i; // starting idx
                string temp ="";
                int sz = needle.size();
                while(sz--){ // neddle size
                    if(i<n){ // hay idx dont get out of bound
                        temp+=hay[i];
                        i++;
                    }
                }
                if(temp==needle)
                    return ans;
                i =  ans+1; // starting the check again from the next idx 
            }
        }
        return -1;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(haystack[i]==needle[cnt]){
                cnt++;
            }
            else{
                i = i-cnt; // eg- if started from idx=0, then start again from idx=1
                cnt = 0;
            }

            if(cnt==m){
                return i-m+1;
            }
        }
        return -1;
    }
};


int main(){

    return 0;
}
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

int main(){

    return 0;
}
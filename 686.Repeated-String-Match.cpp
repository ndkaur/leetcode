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


class Solution0 { // O(sza * szb)
public:
    int repeatedStringMatch(string a, string b) {
        int sza = a.size();
        int szb = b.size();
        // possiblities:- 
        // a = abcd   b = cdabcdab =  cd abcd ab
        // b = prefix + n*a + suffix = 1+n+1 = n+2
        // b = prefix + n*a = 1+n = n+1
        // b= n*a + suffix = n+1 
        // b = n*a = n 

        // so it it clear that solution is either n, n+1,n+2
        int n = (szb / sza); // 8/4 = 2 , add 2 times
        int cnt = n;
        string newStr = "";
        while(cnt--){
            newStr += a;
        }
        // complexity of finding a string in b string = O(size of a) * O(size of b) 
        // check the  presence of b in newstr 
        if(newStr.find(b)!=string::npos) // string found and the returned idx is not equal to last postion 
            return n;
        
        // add 1 time more n+1
        newStr += a;
        if(newStr.find(b)!=string::npos) 
            return n+1;
        
        // add ones again n+2
        newStr += a;
        if(newStr.find(b)!=string::npos)
            return n+2;
        
        return -1;
    }
};


// use kmp -> O(n+m)
class Solution { 
public:
    void computeLPS(string& pattern, vector<int>& lps){
        int n = pattern.size();
        int len = 0;
        int i = 1;
        while(i<n){
            if(pattern[i]==pattern[len]){
                len++;
                // fill the array 
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
    bool KMP(string& str, string& pattern){
        int n = str.size();
        int m = pattern.size();
        vector<int> lps(m, 0);
        computeLPS(pattern, lps);

        int i = 0; // i nver comes back 
        int j = 0;
        
        while(i<n){
            if(str[i]==pattern[j]){
                i++;
                j++;
                if(j==m){ // j reached end of pattern string ie pattern found
                    return true;
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
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int sza = a.size();
        int szb = b.size();
        // possiblities:- 
        // a = abcd   b = cdabcdab =  cd abcd ab
        // b = prefix + n*a + suffix = 1+n+1 = n+2
        // b = prefix + n*a = 1+n = n+1
        // b= n*a + suffix = n+1 
        // b = n*a = n 

        // so it it clear that solution is either n, n+1,n+2
        int n = (szb / sza); // 8/4 = 2 , add 2 times
        int cnt = n;
        string newStr = "";
        while(cnt--){
            newStr += a;
        }
        // complexity of finding a string in b string = O(size of a) * O(size of b) 
        // check the  presence of b in newstr 
        if(KMP(newStr, b)) // string found and the returned idx is not equal to last postion 
            return n;
        
        // add 1 time more n+1
        newStr += a;
        if(KMP(newStr, b)) 
            return n+1;
        
        // add ones again n+2
        newStr += a;
        if(KMP(newStr, b))
            return n+2;
        
        return -1;
    }
};



int main(){

    return 0;
}
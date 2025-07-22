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



// time comp -> O(n+m)
// space -> o(1)
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(str1[i]==str2[j] || str1[i]+1==str2[j] || str1[i]-25==str2[j]){
                j++;
            }
            i++;
        }
        return j==m;
    }
};




class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        if(m > n){ 
            return false; 
        } 
         
        int j = 0; 
         // b-> (98-97) = 1 +1 =2 %26 =2
            // z-> 122 -97 = 25 +1 = 26 %26 = 0 + 97 = 97 
        for(int i=0;i<n && j < m;i++){ 
            if(str1[i] == str2[j]){ 
                j++; 
            } 
            else if(((str1[i] - 'a') + 1)%26 +'a' == str2[j]){ 
                j++; 
            } 
        } 
        return j == m;
    }
};

int main(){

    return 0;
}
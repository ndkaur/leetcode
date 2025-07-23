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
    bool canChange(string start, string target) {
        int n = start.size();
        // conditions when we can move the ptrs 
        // 1 when both the chars are equal 
        // when start[i]==L then i>j 
        // when start[j]==R then i<j so that we can move i right side 
        int i=0;
        int j=0;
        while(i<n || j<n){
            while(i<n && start[i]=='_'){
                i++;
            }
            while(j<n && target[j]=='_'){
                j++;
            }
            // alter condtions of when not equal false break 
            if(i==n || j==n || start[i]!=target[j] || (start[i]=='L' && i<j) || (start[i]=='R' && i>j)){
                break;
            }
            i++;
            j++;
        }
        return i==n && j==n;
    }
};


class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int m = target.size();
        int i = 0; // target
        int j = 0; // start
        while(i<=m && j<=m){
            while(i<m && target[i]=='_'){
                i++;
            }
            while(j<m && start[j]=='_'){
                j++;
            }
            if(i==m || j==m){ // reached last index
                return i==m && j==m;
            }

            if(target[i]!=start[j])  // "R_L_", target = "__LR"
                return false;

            if(target[i]=='L'){
                if(j<i){
                    return false;
                }
            }
            else{ // its R , "_R", target = "R_"
                if(i<j)
                    return false;
            }

            i++;
            j++;
        }
        return true;
    }
};

// / start "_L__R__R_", target = "L______RR"

int main(){

    return 0;
}
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

class Solution0 {
public:
    int countCollisions(string s) {
        int n= s.size();
        int count =0;
        int i=0; 
        int j=n-1;
        while(i<=j && s[i]=='L'){  // starting with left keep on goint left <-   LLLLL
            i++;
        }
        while(i<=j && s[j]=='R'){ // r is prest at last will keep on going r ->  LLLL......RRRR
            j--;
        }
        //  rest all will collide .. after one collison it become S 
        for( ; i<=j;i++){
            count+= (s[i]!='S');
        }
        return count;
    }
};

//  using stack 
//  stack top      direc
//   nothing         R     nothing can come in stack not l not S  -> critical case  only a next S can create a collision
//   R               L
//   S               L
//   R               S

class Solution {
public:
    int countCollisions(string d) {
        int n= d.size();
        if(n==1) return 0;
        stack<char> st;
        st.push(d[0]);
        int count=0;

        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()=='R' && d[i]=='L'){
                count+=2;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && st.top()=='S' && d[i]=='L'){
                count+=1;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && st.top()=='R' && st.top()=='S'){
                count+=1;
                st.pop();
                st.push('S');
            }
            else{ // direction is R with no match on st.top
                st.push(d[i]);
            }
        }
        // nothing matches on st.top with direction R (See below) 
       
        while(!st.empty() && st.top()=='R'){
            st.pop();
        }
        while(!st.empty()){
            if(st.top()=='R')
                count+=1;
            st.pop();
        }
        return count;
    }
};


 // eg -> vector= SSSRRR  stack will store it in reverse order .
// R   so this stack when pop out then ->  it will be in reverse order ->  RRRSSS 
// R    so RRRSSS the starting R's doesnt matter if present or not .. cnat make any collsions
// R     
// S
// S
// S 


int main(){
    Solution sol;
    string s="RLRSLL";
    int ans= sol.countCollisions(s);
    cout<<ans;
    return 0;
}
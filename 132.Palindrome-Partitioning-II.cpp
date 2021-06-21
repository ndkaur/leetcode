#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution0 {
public:
    int minCut(string s) {
        int n = s.size();
        return check(0,n-1,s);
    }
    int check(int i,int j,string& s){
        int ans=INT_MAX;
        if(i>=j) 
            return 0;
        if(isPalindrome(i,j,s))
            return 0;
        for(int k=i;k<j;k++){
            int temp= check(i,k,s) + check(k+1,j,s)+1;
            ans = min(ans,temp);
        }
        return ans;
    }
    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }  
};  // time limit exceeded 


class Solution1 {
    vector<vector<int>> dp;
public:
    int minCut(string s) {
        int n = s.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return check(0,n-1,s);
    }
    int check(int i,int j,string& s){
        int ans=INT_MAX;
        if(i>=j) 
            return 0;
        if(isPalindrome(i,j,s))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<j;k++){
            int temp= check(i,k,s) + check(k+1,j,s)+1;
            if(temp<ans)
                ans=temp;
        }
        return dp[i][j]=ans;
    }
    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    } // tle
};



class Solution2 {
    vector<vector<int>> dp;
public:
    int minCut(string s) {
        int n = s.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return check(0,n-1,s);
    }
    int check(int i,int j,string& s){
        int ans=INT_MAX;
        if(i>=j || isPalindrome(i,j,s))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left,right;
        for(int k=i;k<j;k++){
            if(dp[i][k]!=-1)
                left =dp[i][k];
            else{
                left = check(i,k,s);
                dp[i][k]=left;
            } 
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else{
                right = check(k+1,j,s);
                dp[k+1][j]=right;
            }
            int temp=left+right+1; 
            ans = min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    } // tle 
};


class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pali(n,vector<bool>(n));
        // plaindrome for lenght 1
        for(int i=0;i<n;i++)
            pali[i][i] = true; // diagonals 
        // palindrome for lenght =2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
                pali[i][i+1] = true;
        }
        // for lenght more than 3
        for(int cur=2;cur<n;cur++){
            for(int i=0;i<n-cur;i++){
                int j=i+cur;
                if(s[i]==s[j] && pali[i+1][j-1]) // curr chars are palin and inbetween also palin
                    pali[i][j] =true;
            }
        }
        vector<int> cuts(n,INT_MAX);
        // count the no of cuts required

        for(int i=0;i<n;i++){
            // if is already a plindrome then no cuts needed
            if(pali[0][i])
                cuts[i]=0;
            else{
                int temp=INT_MAX;
                for(int j=0;j<i;j++){
                    if(pali[j+1][i] && cuts[j]+1<temp) // is true at that pos 
                        temp=cuts[j]+1;
                }
                cuts[i]=temp;
            }
        }
        return cuts[n-1];
    }
};

int main(){
    Solution sol;
    string s ="aab";
    int ans=sol.minCut(s);
    cout<<ans;
    return 0;
}
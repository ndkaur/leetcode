/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
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

// @lc code=start

class Solution { //O(N)  O(N)
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s = to_string(x);
        cout<<s<<endl;
        string r= s;
        reverse(r.begin(), r.end());
        cout<<r<<endl;
        for(int i=0;i<s.size(); i++){
            if(s[i]!=r[i])
                return false;
        }
        return true;
    }
};

// reversing only till half of the lenght 
class Solution { // o(logn)  O(1)
public:
    bool isPalindrome(int x) {
        // -ve num or num with 00 like 10 100 1000
        if(x<0 || x%10 == 0 && x!=0) 
            return false;
        int revNum=0;
        // 12321
        while(x > revNum){
            int rem = x%10;
            revNum  = revNum * 10 + rem;
            x= x/10;
        }
        // even num ->1221  x= 12  rev = 12
        // odd len ->12321   x= 12  rev 123 sor the mid 3 doesnot matter we can drop it off
        return x == revNum ||  x == revNum/10;
    }
};


class Solution1 {  // o(N)
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long rev = 0;
        long long num = x; // x will be reduced at the end so store in other num
        while(x!=0){
            int rem = x%10;
            rev = rev * 10 + rem;
            x = x/10;
        }
        return (rev == num);
    }
};

class Solution {  // o(logN)
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0)) // multiple of 10 or trailing 0 at end 
            return false;
        int rev = 0;
        // 12321 
        // rev = 1 , x=1232
        // rev = 12 , x = 123
        // rev = 123 , x = 12 no next while loop
        // if after this num len is odd then 1221 then num and rev will be equal
        // but if len is even then one num will be remaining at center 12321 
        // like rev = 123 and num = 12 so reduce the rev again one time then it should be equal 
        while(x>rev){
            int rem = x%10;
            rev = rev * 10 + rem;
            x = x/10;
        }
        // even len || odd len then reduce the reverse again to make it fully equal 
        return (x == rev) || (x == rev/10);
    }
};

// @lc code=end


int main(){
    Solution sol;
    int x= 100;
    bool ans = sol.isPalindrome(x);
    cout<<ans;
    return 0;
}
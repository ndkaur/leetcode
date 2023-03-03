/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
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

// a b b b b b b b b b b b b 
// ans = 4  as string becomes ab12
// a comes only 1 time so add it to string 

// a a b b c c c 
// a 2 b 2 c 3
// ans = 6

class Solution {
public:
    int compress(vector<char>& chars) {
        // int n = chars.size();
        int ans =0;
        for(int i=0; i<chars.size(); i++){
            const char letter = chars[i];
            int count =0;

            while(i<chars.size() && chars[i] == letter){
                count++;
                i++;
            }
            chars[ans++] = letter;
            
            if(count>1){
                for(const char c: to_string(count)){
                    chars[ans++] = c;
                    
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;

        // iterate through input vector using i pointer
        for (int i = 0; i < chars.size();) {
            const char letter = chars[i]; // current character being compressed
            int count = 0; // count of consecutive occurrences of letter

            // count consecutive occurrences of letter in input vector
            while (i < chars.size() && chars[i] == letter) {
                ++count;
                ++i;
            }

            // write letter to compressed vector
            chars[ans++] = letter;

            // if count is greater than 1, write count as string to compressed vector
            if (count > 1) {
                // convert count to string and iterate over each character in string
                for (const char c : to_string(count)) {
                    chars[ans++] = c;
                }
            }
        }

        // return length of compressed vector
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}
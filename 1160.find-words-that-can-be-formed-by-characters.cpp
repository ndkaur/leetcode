/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        map<char,int> freq; // map for chars
        for(int i=0;i<chars.length();i++) // to count the char and int for chars
            freq[chars[i]]++;
        for(int i=0;i<words.size();i++) // to count chars and int for words
        {
            bool r=1;
            map<char,int> chr_cnt; // map for words
            for(int j=0;j<words[i].length();j++) //for each alphabet in each char
                chr_cnt[words[i][j]]++;
            // map<char,int> :: iterator p;
            for(auto p=chr_cnt.begin();p!=chr_cnt.end();p++)
            {      
                // if alphabet occurence in words is more than the occurence in chars
                // then break the loop
                char c = p->first;
                int cnt = p->second;
                if(cnt>freq[c])
                {
                    r=0;
                    break;
                }
            }
            if(r)
                ans+=words[i].length();
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<string> words={"cat","bt","hat","tree"};
    string chars="atach";
    
    int ans=sol.countCharacters(words,chars);
    cout<<ans;
    return 0;
}
// @lc code=start
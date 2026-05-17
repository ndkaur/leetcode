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
    bool isletter(char ch){
        return 'a'<=ch && ch<='z';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(string& chunk:chunks){
            s+=chunk;
        }

        unordered_map<string,int> mp;
        int n = s.size();
        int i = 0;
        while(i<n){
            if(!isletter(s[i])){
                i++;
                continue;
            }
            string word = "";
            while(i<n){
                if(isletter(s[i])){
                    word+= s[i];
                    i++;
                }
                else if(s[i]=='-'){ // a-b
                    bool left = !word.empty(); // must be a leeter and not empty 
                    bool right = (i+1<n && isletter(s[i+1]));
                    if(left && right){
                        word+= '-';
                        i++;
                    }
                    else 
                        break;
                }
                else // blank space
                    break;
            }
            mp[word]++;
        }

        vector<int> ans;
        for(auto q:queries){
            ans.push_back(mp[q]);
        }
        return ans;
    }
};


// chunks = ["a-b a- -c"]
// queries = ["a","b","c"]
// Output = [1,0,1]  a=1 , b= 0, c=1 , a-b =1


int main(){

    return 0;
}
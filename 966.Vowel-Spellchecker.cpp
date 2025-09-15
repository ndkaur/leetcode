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
    string makeLow(string s){
        string ans = "";
        for(char ch:s){
            ans+= tolower(ch);
        }
        return ans;
    }

    bool isVowel(char ch){
        ch = tolower(ch);
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> mp; // if the same as it is string exist
        unordered_map<string, string> capital; // using the capital rule
        unordered_map<string,string> vowels; // using the vowel rule 

        for(auto i:wordlist){
            mp[i]++;
            string s = makeLow(i);
            if(capital.find(s)==capital.end()){// not in map
                capital[s]=i; // right order-> original
            }

            string withoutVowel = "";
            for(char ch:s){
                if(!isVowel(ch)){
                    withoutVowel += ch;
                }
                else{
                    withoutVowel += '#';
                }
            }
            if(vowels.find(withoutVowel)==vowels.end()){
                vowels[withoutVowel] = i;
            }
        }

        vector<string> ans;
        for(auto s:queries){
            if(mp.find(s)!=mp.end())
                ans.push_back(s);
            else if(capital.find(makeLow(s))!=capital.end()){
                ans.push_back(capital[makeLow(s)]);
            }
            else{ // vowel
                string withoutVowels = "";
                string sLower = makeLow(s);
                for(char ch:sLower){
                    if(!isVowel(ch)){
                        withoutVowels += ch;
                    }
                    else{
                        withoutVowels += '#';
                    }
                }
                // now stirng made ,c heck in map with that key
                if(vowels.find(withoutVowels)!= vowels.end()){
                    ans.push_back(vowels[withoutVowels]);
                }
                else{
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};




int main(){

    return 0;
}
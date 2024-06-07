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




// time complexity is O(NL + M * L')
// N is the number of roots, L is the average length of the roots, M is the number of words in the sentence, and L' is the average length of the words.

//  space complexity is  O(NL + M * L')
class Trie{
public:
    Trie* child[26];
    bool isEnd;
    Trie(){
        for(auto& ch:child){
            ch= NULL;
        }
        isEnd = false;
    }
};


class Solution {
public:
    Trie* root;
    Solution(){
        root = new Trie();
    }

    void insert(string word){
        Trie* node = root;
        for(auto ch:word){
            int val = ch-'a';
            if(!node->child[val]){ // does not exist then add link
                node->child[val] = new Trie();
            }
            node = node->child[val]; 
        }
        node->isEnd = true;
    }

    string search(string word){
        Trie* node = root;
        string ans;
        for(auto ch:word){
            int val = ch-'a';
            if(!node->child[val]){ // words like the , by that doesnt exist return them as it is 
                return word;
            }
            ans += ch;
            if(node->child[val]->isEnd){ // required word formed
                return ans;
            }
            node = node->child[val];
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        int m = sentence.size();

        // add words from dictionary to trie for its formation 
        for(string word:dictionary){
            insert(word);
        }

        // we want to pass each seperate word from sentence by removing space
        stringstream ss(sentence);
        string word;
        string result;

        while(ss>>word){
            if(!result.empty()){
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        int m = sentence.size();
        set<string> st;
        for(auto d:dictionary){
            st.insert(d);
        }

        string temp;
        string ans;
        bool found = 0;

        for(auto ch:sentence){
            if(ch!=' '){// not space
                temp += ch;
                // those words that doesnt exist in set , we add them as it is in the ans string , eg = the , by
                if(!found && st.find(temp)!=st.end()){ // exist in set 
                    ans += temp;
                    found = 1;
                }
            }
            else{ // its a space 
                if(!found){ // if the word isnt added before then add it 
                    ans+=temp;
                }
                ans += ' ';
                temp = "";
                found =0;
            }
        }

        if(!found)
            ans +=temp;
        return ans;
    }
};

int main(){

    return 0;
}
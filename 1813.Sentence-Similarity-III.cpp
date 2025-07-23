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
    bool areSentencesSimilar(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        stringstream str1(s1);
        stringstream str2(s2);
        string word;
        vector<string> w1, w2;
        while(str1>>word){
            w1.push_back(word);
        }
        while(str2>>word){
            w2.push_back(word);
        }
        // we want smaller size first 
        if(w1.size()>w2.size())
            return areSentencesSimilar(s2, s1);
        
        int start = 0;
        int end1 = w1.size()-1;
        int end2 = w2.size()-1;

        while(start<w1.size() && w1[start]==w2[start]){
            start++;
        }

        while(end1>=0 && w1[end1]==w2[end2]){
            end1--;
            end2--;
        }
        // start =1
        //end1=0 , end2 = 2   end1<start
        return  end1<start;
    }
};


int main(){

    return 0;
}
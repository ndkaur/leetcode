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
    string largestMerge(string word1, string word2) {
        int n = word1.size();
        if(n==0)
            return word2;

        int m = word2.size();
        if(m==0)
            return word2;

        int i =0;
        int j =0;
        string ans;
       
        while(i<n && j<m){
            if(word1[i]<word2[j]){
                ans+=word2[j];
                j++;
            }
            else if(word1[i]>word2[j]){
                ans+=word1[i];
                i++;
            }
            else{
                int ii = i;
                int jj = j;
                while(ii<n && jj<m && word1[ii]==word2[jj]){
                    ii++;
                    jj++;
                }
                if(word1[ii]>word2[jj]){
                    ans+=word1[i];
                    i++;
                }
                else if(word1[ii]<word2[jj]){
                    ans+=word2[j];
                    j++;
                }
                else if(ii==n){
                    ans+= word2[j];
                    j++;
                }
                else if(jj==m){
                    ans+=word1[i];
                    i++;
                }
            }
        }
        
        while(i<n){
            ans+=word1[i];
            i++;
        }
        
        
        while(j<m){
            ans+= word2[j];
            j++;
        }
        
        return ans;
    }
};

int main(){

    return 0;
}
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
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int n = words.size();
        int prevCnt =0;
        int numCnt =0;
        
        vector<int>arr;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(words[i]=="prev"){
                prevCnt++;
                if(arr.size()>=prevCnt){
                    ans.push_back(arr[arr.size()-prevCnt]);
                }
                else {
                    ans.push_back(-1);
                }
            }
            else{// is a num    
                arr.push_back(stoi(words[i]));
                prevCnt=0;// non consecutive 
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}
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
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = startGene.size();
        unordered_set<string> st{bank.begin(), bank.end()};
        if(!st.count(endGene))
            return -1;
        
        queue<string> q;
        q.push(startGene);
        int steps = 0;

        while(q.size()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto curr = q.front();
                q.pop();
                if(curr==endGene)
                    return steps;

                st.erase(curr);

                for(int i=0; i<8; i++){
                    string temp = curr;
                    temp[i]='A';
                    if(st.count(temp))
                        q.push(temp);

                    temp[i]='C';
                    if(st.count(temp))
                        q.push(temp);
                    
                    temp[i]='G';
                    if(st.count(temp))
                        q.push(temp);

                    temp[i]='T';
                    if(st.count(temp))
                        q.push(temp);
                }
            }
            steps++;
        }
        return -1;
    }
};



int main(){

    return 0;
}
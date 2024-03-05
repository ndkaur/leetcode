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
    string gameResult(ListNode* head) { 
        int odd = 0;
        int even = 0;
        ListNode* curr = head;
    
        while(curr && curr->next){
            if(curr->val>curr->next->val){
                even++;
            }
            else 
                odd++;
            curr = curr->next->next;
        }
        if(even>odd)
            return "Even";
        else if(odd>even)
            return "Odd";
        else 
            return "Tie";
    }
};


int main(){

    return 0;
}
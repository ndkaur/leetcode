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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        sort(potions.begin(), potions.end());

        vector<int> ans;

        for(int spell:spells){
            // spell*potion >= success 
            // potion >= success/spell 
            // so we need to find that idx of potion after which all are valid 
            long long int potion = success/spell;
            // eg-> 7/5 = 1.4 we need to round = 2 
            // so when the 1*5 =5<7 it cant be valid we need to increase the potion
            if(potion*spell < success){
                potion++;
            }
            // now till here we got the idea that what minium value of potion is required for the current spell , so we will find the index in the potion array after which the curr soell is possible 
            auto itr = lower_bound(potions.begin(), potions.end(), potion);
            // if we found the idx 
            if(itr!=potions.end()){
                int idx = itr-potions.begin();
                // then all the remaing idx will be valid
                ans.push_back(n-idx);
            }
            else{ // no idx found it got out of bounds
                ans.push_back(0);
            }
        }
        return ans;
    }
};



int main(){

    return 0;
}
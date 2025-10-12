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
    long long minTime(vector<int>& skill, vector<int>& capacity) {
        int s = skill.size();
        int c = capacity.size();
        vector<long long > temp(s,0);

        // capacity fixed and skill change 
        // potion moves on to next wizard one by one 
        // we move to next potion only when all the wizrds have brewed the curr potion

        for(int i=0; i<c; i++){ 
            // vector<long long> curr_brew(s,0);
            temp[0] = temp[0] + 1LL*capacity[i]*skill[0];
            
            for(int j=1; j<s; j++){ // going to each wizard
                // the time curr wiazrd will start brewing depend on two factor 
                // 1. is the curr wizrd free from the brewing of prev potion?
                // 2. has the prev wizrd passed the potion to curr wizrd after brewign?
                    temp[j] = max(temp[j], temp[j-1]) + 1LL*capacity[i]*skill[j];
            }
            // now we have to backtrack to check if we have taken the valid times, 
            // if not valid then reset them 
            for(int j=s-1; j>0; j--){
                temp[j-1] = temp[j] - 1LL*capacity[i]*skill[j];
            }
        }
        return temp[s-1];
    }
};

//            potion wizrd 
// capacity     0(1)     1(5)   2(2)    3(4)  
//   0(5)        5        30     40      60
//   1(1)        53,6    58,35   60,42   64
//   2(4)        58,57    78      86     102
//   3(2)        88,60    98     102     110
//            (curr, prev)



int main(){

    return 0;
}
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

// Input: player1 = [4,10,7,9], player2 = [6,5,2,3]
// Output: 1
// Explanation: The score of player1 is 4 + 10 + 2*7 + 2*9 = 46.
// The score of player2 is 6 + 5 + 2 + 3 = 16.
// Score of player1 is more than the score of player2, 
// so, player1 is the winner, and the answer is 1.


class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int m = player2.size();
        
        int s1 =0;
        int t1 =0; // count of 10
        int s2 =0;
        int t2 =0;

        for(int i=0; i<n; i++){
            s1+= player1[i];
            s2+= player2[i];

            if(t1){
                t1--;
                s1+= player1[i]; // if 10 came then add no twice
            }
            if(t2){
                t2--;
                s2+= player2[i];
            }
            // count of 10
            if(player1[i] == 10)
                t1 = 2;
            if(player2[i] == 10)
                t2 = 2;
        }
        

        if(s1 > s2)
            return 1;
        else if(s2 >s1)
            return 2;
        return 0;
    }
};

int main(){

    return 0;
}

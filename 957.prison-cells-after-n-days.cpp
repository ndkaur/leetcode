/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N){
        
        change_next(cells); // to firstly change the values of current cell
        
        if(N==1){ //only 1 row needed
            return cells;
        }
        N--; // the cells in the question is never gonna repeat
        
        set<vector<int>> seen;
        vector<vector<int>> save;

        do{
            seen.insert(cells); //to save value of current cell in seen 
            save.push_back(cells); //saved the previous cell 
            change_next(cells); //changed the required values in next cell
        }while(seen.count(cells)==0);//repeated or not //if already seen the values of current cell
        //to find cell at that Nth position 
        //we find the remainder of N with the total size 
        int size = save.size();
        return save[N%size];
    }

    void change_next(vector<int> &cells){
        vector<int> out(8,0);
        for(int i=1;i<cells.size()-1;i++){
            if(cells[i-1]==cells[i+1]){
                out[i]=1;
            }
            else
                out[i]=0;
        }
        cells=out;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> cells={0,1,0,1,1,0,0,1};
    int N=7;
    vector<int> out=sol.prisonAfterNDays(cells,N);
    print(out);
    return 0;
}
/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
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
    int calPoints(vector<string>& ops){
        int score=0;
        int sum=0;
        vector<int> points;
        for(string i:ops){
            if(i=="C"){ 
                sum=sum-points.back(); // remove previously sdded points in sum
                points.pop_back(); // remove invalid point from points
                continue;
            }
            if(i=="D"){
                score=points.back()*2;// if we directly write points[i]=p.back*2 this will not work because i is indicating to ops 
                sum=sum+score; // score is used to indicate points[i]
            }
            else if(i=="+"){
                score=points[points.size()-1]+points[points.size()-2]; // points[i-1] is wrong cause i indicating ops
                sum=sum+score;   
            }
            else{
                score=stoi(i);// if any numerical numbers are left then convert them into int from string 
                sum=sum+score;
            }
            points.push_back(score);
        }
        return sum;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<string> ops={"5","-2","4","C","D","9","+","+"};
    int sum=sol.calPoints(ops);
    cout<<sum;
    return 0;
}

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

class Solution0 { // wrong answer
public:
    vector<vector<int>> dirs ={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int n = 200;
        vector<vector<int>> visited(n, vector<int>(n,0));
        queue<pair<pair<int,int>, int>> q;
        q.push({{sx,sy},0});
        visited[sx+100][sy+100]=1;
        
        while(q.size()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            if(time > t)
                continue;
            if(i==fx && j==fy)
                return 1;
            
            for(auto dir:dirs){
                int nx = i+dir[0];
                int ny = j+dir[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx+100][ny+100]){
                    visited[nx+100][ny+100] = 1;
                    q.push({{nx,ny},time+1 });
                }
            } 
        }
        return 0;
    }
};



class Solution {
public:
   
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        long long int x = abs(sx-fx);
        long long int y = abs(sy-fy);
        long long int mx = max(x,y);
        
        if(mx>t || (mx==0 && (t<2 && t>0)))
            return false;
        else 
            return true;
    }
};

















int main(){

    return 0;
}
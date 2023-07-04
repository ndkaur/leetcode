/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
// #include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color!=newColor) 
            dfs(image,sr,sc,color,newColor);
        return image;
    }
    void dfs(vector<vector<int>> &image,int r,int c, int color , int newColor){
        if(image[r][c]== color){
            image[r][c] = newColor;
            // above row 
            if(r>=1)
                dfs(image,r-1,c,color,newColor);
            
            //left column
            if(c>=1)
                dfs(image,r,c-1,color,newColor);
            
            //below row
            if(r+1<image.size())
                dfs(image,r+1,c,color,newColor);
            
            //right column
            if(c+1 < image[0].size())
                dfs(image,r,c+1,color,newColor);
            
        }
    }
};


//bfs 
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m =image[0].size();
        int color = image[sr][sc];
        if(color==newColor) return image;

        queue<pair<int,int>> q;                      
        image[sr][sc]= newColor;
        q.push({sr,sc});

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            //above
            if(r>=1 && image[r-1][c]==color){
                image[r-1][c]= newColor;
                q.push({r-1,c});
            }
            //left
            if(c>=1 && image[r][c-1]==color){
                image[r][c-1]=newColor;
                q.push({r,c-1});
            }  
            //down 
            if(r+1<image.size() && image[r+1][c]==color){
                image[r+1][c] =newColor;
                q.push({r+1,c});
            }
            //right 
            if(c+1 < image[0].size() && image[r][c+1]==color){
                image[r][c+1] =newColor;
                q.push({r,c+1});
            }
        }
        return image;
    }
};


class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int scolor=  image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, scolor,color, ans, image);
        return ans;
    }
    void dfs(int row, int col, int& scolor, int& color, vector<vector<int>>& ans, vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();
        ans[row][col]=color;
        for(auto dir:dirs){
            int nrow = row + dir.first;
            int ncol = col + dir.second;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color &&
                image[nrow][ncol]==scolor){
                    dfs(nrow, ncol, scolor, color, ans, image);
                }
        }
    }
};
// @lc code=end


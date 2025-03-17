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


class Spreadsheet {
    public:
        vector<vector<int>> sheet;
        Spreadsheet(int rows) {
            sheet.resize(rows+1, vector<int>(26));
        }
        
        void setCell(string cell, int value) {
            // A10
            int row = stoi(cell.substr(1));
            int col = cell[0]-'A';
            sheet[row][col] = value;
        }
        
        void resetCell(string cell) {
            setCell(cell,0);
        }
        
        int get_val(const string& str){
            if(isdigit(str[0])){ // ifrst digit num then whole string is num 
                return stoi(str);
            }
            // its like A1
            int row = stoi(str.substr(1));
            int col = str[0]-'A';
            return sheet[row][col];
        }
    
        int getValue(string formula) {
            //"=A1+6"
            // removing =
            formula = formula.substr(1);
            // two value before + and after +
            auto plus_idx = formula.find('+');
            // A1+6
            return get_val(formula.substr(0,plus_idx)) + get_val(formula.substr(plus_idx+1));
        }
    };
    
    /**
     * Your Spreadsheet object will be instantiated and called as such:
     * Spreadsheet* obj = new Spreadsheet(rows);
     * obj->setCell(cell,value);
     * obj->resetCell(cell);
     * int param_3 = obj->getValue(formula);
     */

int main(){

    return 0;
}
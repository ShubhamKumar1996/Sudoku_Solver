#include<bits/stdc++.h>
using namespace std;

bool validNum(vector<vector<int>>&mat, int x, int y, int val){
    
    for(int j=0;j<9;j++){
        if(mat[x][j]==val) {
            return false;
        }
    }
    
    for(int i=0;i<9;i++){
        if(mat[i][y]==val) {
            return false;
        }
    }
    
    int start1 = x/3, start2 = y/3;
    
    for(int i=start1*3;i<start1*3+3;i++){
        for(int j=start2*3;j<start2*3+3;j++){
            if(mat[i][j]==val) {
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(vector<vector<int>>&mat, vector<pair<int, int>>&coord, int index){
    if(index==coord.size()){
        return true;
    }
    
    for(int val=1;val<=9;val++){
        int x = coord[index].first;
        int y = coord[index].second;
        if(validNum(mat, x, y, val)==true){
            mat[x][y] = val;
            bool result = solveSudoku(mat, coord, index+1);
            if(result==true){
                return true;
            }
            mat[x][y]=0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>>mat(9, (vector<int>(9)));
    vector<pair<int, int>>coord;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>mat[i][j];
            if(mat[i][j]==0)
                coord.push_back(make_pair(i, j));
        }
    }
    
    bool result = solveSudoku(mat, coord, 0);
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
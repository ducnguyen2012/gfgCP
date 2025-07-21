// check reach in transitive closure of a graph using DFS (i'm not finish, coding in 10 minutes). 

#include <bits/stdc++.h>

using namespace std;


bool checkReach(vector<vector<int>>& matrix, int src, vector<bool>& vis, int N){
    // this function will check reach from 0 - 3 
    
    vis[src]  = true;
    for(int i = 0; i < N; ++i){
        if (!vis[i] && matrix[src][i] == 1) {
            cout<<"check reach: "<<i<<"\n";
            checkReach(matrix,i,vis,N);
            
        }
    }
    if (src == N-1){
        return true;
    }
    return false;
}

int main(){
    
    vector<vector<int>> matrix = {{0,1,1,0},{0,0,1,0},{0,0,0,1},{0,0,0,0}};
    int N = 4;
    vector<bool> vis(N,false);
    cout<<checkReach(matrix,0,vis,N);
    
    return 0;
    
}

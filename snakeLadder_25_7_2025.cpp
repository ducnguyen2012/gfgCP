#include <bits/stdc++.h>

using namespace std;

void dfs(int currPos, vector<int>& moves, int N, map<int,int>vis, int moveMades, int res){
    
    if (moveMades >= res || vis.count(currPos) != 0&& moveMades >= vis[currPos]) return;
    if (currPos == N-1) {res = moveMades; return;} 
    vis[currPos] = moveMades;
    for(int i = 1; i <= 6 && currPos + i < N; ++i){
        int nextPos = currPos + i;
        cout<<"this is next pos: "<<nextPos<<"\n";
        int dest = (moves[nextPos] != -1) ? moves[nextPos] : nextPos;
        
        dfs(dest,moves,N, vis, moveMades+1, res);
    }
}
int getMinDiceThrows(vector<int>& moves, int N){
    
    map<int,int> vis;
    int res = INT_MAX;
    
    dfs(0,moves,N,vis,0,res);
    
    return (res == INT_MAX) ? -1 : res;
}
int main() {
    int n = 30;
    vector<int> moves(n, -1);

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << getMinDiceThrows(moves,n);
    return 0;
}

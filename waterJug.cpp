#include <bits/stdc++.h>

using namespace std;


int countMinSteps(int m, int n, int d){
    vector<vector<int>>vis(m+1,vector<int>(n+1,0));
    int steps = 0;
    queue<vector<int>>q;
    q.push({0,0,steps});
    vis[0][0] = true;
    if (d > max(m,n)) return -1;
    while(!q.empty()){
        int jug1 = q.front()[0];
        int jug2 = q.front()[1];
        int step = q.front()[2];
        q.pop();
        // poor full jug2 to jug1 with m liter
        if (jug1 == d || jug2 == d) return step;
        if (!vis[m][jug2]){
            cout<<"poor jug2 to jug1 with m liter"<<"\n";
            vis[m][jug2] = true;
            q.push({m,jug2,step +1});
        }
        if (!vis[jug1][n]){
            cout<<"poor jug1 to jug2 with n liter"<<"\n";
            vis[jug1][n] = true;
            q.push({jug1,n,step +1});
        }
        if (!vis[0][jug2]){
            cout<<"empty jug1"<<"\n";
            vis[0][jug2] = true;
            q.push({0,jug2,step +1});
        }
        if (!vis[jug1][0]){
            cout<<"empty jug2"<<"\n";
            vis[jug1][0] = true;
            q.push({jug1,0,step +1});
        }
        int poor1to2 = min(jug1,n-jug2); 
        if (!vis[jug1-poor1to2][jug2+poor1to2]){
            cout<<"poor "<<poor1to2<<" liter from 1 to 2"<<"\n";
            vis[jug1-poor1to2][jug2+poor1to2] = true;
            q.push({jug1-poor1to2,jug2+poor1to2,step +1});
        }
        int poor2to1 = min(jug2,m-jug1);
        if (!vis[jug1+poor2to1][jug2-poor2to1]){
            cout<<"poor "<<poor2to1<<" liter from 2 to 1"<<"\n";
            vis[jug1+poor2to1][jug2-poor2to1] = true;
            q.push({jug1+poor2to1,jug2-poor2to1,step +1});
        }
        
    }
    return -1;
}
int main(){
    int m = 4; int n = 3; int d = 2;
    cout<<countMinSteps(m,n,d);
    return 0;
}

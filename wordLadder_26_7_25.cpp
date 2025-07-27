#include <bits/stdc++.h>

using namespace std;

int wordLadder(string start, string target, vector<string>& arr){
    unordered_set<string> s(arr.begin(), arr.end());

    int res = 0;
    int m = start.length();

    queue<string> q;

    q.push(start);
    while(!q.empty()){
        res += 1;

        string curWord = q.front();
        cout<<curWord<<" ";
        q.pop();
        for(int i = 0; i < curWord.length(); ++i){
            char originChar = curWord[i];
            for(char c = 'a'; c <= 'z'; ++c){
                curWord[i] = c;

                if (s.find(curWord) == s.end()) continue;
                
                if (curWord == target) return res+1;
                
                s.erase(curWord);
                
                q.push(curWord);

            }
            curWord[i] = originChar;
        }


    }
}
int main(){
    cout<<"The task is to find the length of the smallest"<<"\n";
    // remember, need to ensure there are only 1 character differ

    vector<string> arr = {"poon", "plee", "same", 
                    "poie", "plie", "poin", "plea"};
    string start = "toon";
    string target = "plea";
    cout << wordLadder(start, target, arr);



    return 0;
}

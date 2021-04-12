#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cstdint>
#include <set>
 
#include <math.h>
using namespace std;
          
struct edge{
    int current;
    int dist;
};

int getLen(edge index, vector<vector<edge>> newVec, int parent){
    vector<char> used (newVec.size(), 0);
    queue <edge> q;
    q.push(index);
    int len = 0;

    while (!q.empty()){
        edge v = q.front();
        q.pop();
        len += v.dist;
        used[v.current] = 1;
        if (newVec[v.current].empty())
            continue;
        
        for (edge i : newVec[v.current])
            if (used[i.current] == 0 && i.current != parent && !newVec[i.current].empty())
                    q.push(i);
        
    }

    return len;

}
 
int main() {
             
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);
    cout.tie(NULL);
     
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n = 38;
    
    vector<vector<edge>> newVec (43);
    
    int x, y, d;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> d;
        x--; 
        y--;
        newVec[x].push_back({y, d}); //x -> y = d
        newVec[y].push_back({x, d});
    }


    for (int i = 0; i < newVec.size(); i++)
    {   
        int minlen = -1;
        for (edge j : newVec[i]){
            int len = getLen(j, newVec, i);
          
            if (len > minlen)
                minlen = len;
            cout << "try len: " << i + 1 << " = " <<  minlen << endl;
        }
        cout << "final len: " << i + 1 << " = " <<  minlen << endl;
    }

    
    return 0;
}

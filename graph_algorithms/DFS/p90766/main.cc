#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<char>> graph;
typedef vector<vector<bool>> visited;

graph g;
visited v;

void read_graph(const int n, const int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) cin >> g[i][j];
    }
}

bool pos_ok(int r, int c)
{
    if (r >= 0 and r < g.size() and c >= 0 and c < g[0].size() and g[r][c] != 'X') return true;
    return false;
}

int dfs_search(int r, int c)
{
    stack<pair<int,int>> p;
    p.push(make_pair(r, c));
    v[r][c] = true;
    int count = 0;
    while (not p.empty())
    {
       int r2 = p.top().first;
       int c2 = p.top().second;
       //cout << r2 << " " << c2 << endl;
       if (g[r2][c2] == 't' and not v[r2][c2]) ++count;
       if (pos_ok(r2-1, c2) and not v[r2-1][c2]) 
       {
            p.push(make_pair(r2-1, c2)); //UP
            //cout << "UP" << endl;
       }
       else if (pos_ok(r2, c2-1) and not v[r2][c2-1])
       {
            p.push(make_pair(r2, c2-1)); //LEFT
            //cout << "LEFT" << endl;
       }
       else if (pos_ok(r2+1, c2) and not v[r2+1][c2])
       {
            p.push(make_pair(r2+1, c2)); //DOWN
            //cout << "DOWN" << endl;
       }
       else if (pos_ok(r2, c2+1) and not v[r2][c2+1]) 
       {
            p.push(make_pair(r2, c2+1)); //RIGHT
            //cout << "RIGHT" << endl;
       }
       else p.pop();
       v[r2][c2] = true;
    }
    return count;
}


int main()
{
    int n, m;
    cin >> n >> m;
    g = graph(n, vector<char>(m));
    read_graph(n, m);
    v = visited(n, vector<bool>(m, false)); //lista de adyaciencias
    int pos_r, pos_c;
    cin >> pos_r >> pos_c;
    cout << dfs_search(pos_r-1, pos_c-1) << endl;
}
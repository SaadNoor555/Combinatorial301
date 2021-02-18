#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int v, e, max_flow= 0;
int grph[10][10];
int res[10][10];
int flow[10][10];
int parent[10];

bool bfs(int s, int t)
{
    bool visited[v];
    memset(visited, 0, sizeof visited);

    queue<int>q;
    q.push(s);
    visited[s]= 1;
    parent[s]= -1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(int i=0; i<v; i++)
            if(!visited[i] && res[u][i])
            {
                q.push(i);
                parent[i]= u;
                visited[i]= 1;
            }
    }

    return visited[t];
}

int main()
{
    cin>> v>> e;
    int s, d, w;


    memset(grph, 0, sizeof grph);
    memset(flow, 0, sizeof flow);

    for(int i=0; i<e; i++)
    {
        cin>> s>> d>> w;
        grph[s][d]= w;
        res[s][d]= w;
    }

    while(bfs(0, v-1))
    {
        int pflow= INT32_MAX;
        
        for(int i=v-1; i; i=parent[i])
        {
            s= parent[i];
            pflow= min(pflow, res[s][i]);
        }

        for(int i=v-1; i; i=parent[i])
        {
            s= parent[i];
            res[s][i]-=pflow;
            res[i][s]+=pflow;
        }

        max_flow+=pflow;
    }

    cout<< max_flow<< '\n';
}
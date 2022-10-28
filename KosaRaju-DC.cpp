// KOSARAJU for strongly connected component in directed graph
#include<bits/stdc++.h>
#define int long long
using namespace std;

void topo(int i, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st)
{
    vis[i]=1;
    for(auto it:adj[i])
        if(!vis[it]) topo(it, adj, vis, st);
    st.push(i);
}

void dfs(int i, vector<vector<int>>&adj, vector<int>&vis, vector<int>&temp)
{
    temp.push_back(i);
    vis[i]=1;

    for(auto it:adj[i])
        if(!vis[it]) dfs(it, adj, vis, temp);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n), rev(n);
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u-1].push_back(v-1);
        rev[v-1].push_back(u-1);
    }

    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++) if(!vis[i]) topo(i, adj, vis, st);

    for(int i=0;i<n;i++) vis[i]=0;
    vector<vector<int>> connected;
    while(!st.empty())
    {
        vector<int> temp;
        int node=st.top(); st.pop();
        if(vis[node]) continue;
        dfs(node, rev, vis, temp);
        connected.push_back(temp);
    }

    vector<int> res(n,0);
    for(auto &v:connected){
        if(v.size()>1) for(auto node:v) res[node]=1;
    }

    for(auto it:res) cout<<it<<" "; cout<<endl;

}

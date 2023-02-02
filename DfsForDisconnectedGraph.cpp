#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<list>
typedef vector<list<int>> vli;

void dfs(vli &adj,int n, bool *visited ,int src )
{
	visited[src] = true;
	cout<<src<<" ";
	for(const auto &elm:adj[src])
	{
		if(!visited[elm])
		{
			dfs(adj,n,visited,elm);
		}
	}
	return ;
}

void addEdge(vli &adj,int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int n,e;
	cin>>n>>e;
	vli adj(n);
	for(int i = 0; i < e; i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			dfs(adj,n,visited,i);
		}
	}
	
	return 0;
}
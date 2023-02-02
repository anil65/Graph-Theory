#include<iostream>
using namespace std;
#include<vector>
#include<list>
typedef vector<list<int>> vli;
bool isCycle(vli &adj, int n, bool *visited , int src, int parent)
{
	visited[src] = true;
	for(const auto &elm:adj[src])
	{
		if(elm != parent)
		{
			if(visited[elm])
			{
				return true;	
			}
			else 
			{
				isCycle(adj,n,visited,elm,src);
			}
		}
	}
	return false;
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
		addEdge(adj, u, v);
	}
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	int src;
	cin>>src;
	if(isCycle(adj,n,visited,src,-1))
	{
		cout<<"Cycle Exist ";
	}
	else 
	{
		cout<<"Cycle Not Exist";
	}
	return 0;
}

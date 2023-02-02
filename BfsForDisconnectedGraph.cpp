#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<queue>
typedef vector<list<int>> vli;

void distanceOfNode(int *dist,int n)
{
  for(int i = 0; i < n; i++)
  {
   cout<<i<<" dist -> "<<dist[i]<<endl;	
  }	
}

//bfs algorithm
void bfs(vli &adj,int n,bool *visited,int *dist,int src)
{
		queue<int> que;
		que.push(src);
		visited[src] = true;
		while(!que.empty())
		{
			int f = que.front();
			cout<<f<<" ";
			que.pop();
			for(const auto &elm:adj[f])
			{
				if(!visited[elm])
				{
					que.push(elm);
					visited[elm] = true;
					dist[elm] = dist[f] + 1;
				}
			}
		}
}

//for undirected graph
void addEdge(vli &adj,int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int n,e;
	cin>>n>>e;
	bool *visited = new bool[n];
	vli adj(n);
	for(int i = 0; i < e; i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	
	//making all nodes as unvisited 
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	
	//	making all nodes distance 0
	int *dist = new int[n];
	for(int i = 0; i < n; i++)
	{
		dist[i] = 0;	
	}
	
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			bfs(adj,n,visited,dist,i);
		}
	}
	cout<<endl;
	distanceOfNode(dist,n);
	return 0;
}
#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<queue>
typedef vector<list<int>> vli;

void shortestPathUnweightedGraph(vli &adj, int n, int src,int dest )
{
	bool *visited = new bool[n];
	int *dist = new int[n];
	int *path = new int[n];
	for(int i = 0; i < n; i++)
	{
		visited[i] = 0;
		dist[i] = 0;
		path[i] = -1;
	}
	visited[src] = true;
	queue<int> que;
	que.push(src);
	while(!que.empty())
	{
		int f = que.front();
		que.pop();
		for(const auto &elm:adj[f])
		{
			if(!visited[elm])
			{
				que.push(elm);
				visited[elm] = true;
				dist[elm] = dist[f] + 1;
				path[elm] = f;
			}
		}
	}
	vector<int> p;
	int tmp = dest;
	while(tmp != -1)
	{
		p.push_back(tmp);
		tmp = path[tmp];
	}
	cout<<"Shortest Distance : "<<dist[dest]<<endl;
	cout<<"Shortest Path : ";
	for(int i = p.size()-1; i >= 0; i--)
	{
		cout<<p[i]<<" ";
	}
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
		int u, v;
		cin>>u>>v;
		addEdge(adj, u, v);	
	}
	int src,dest;
	cin>>src>>dest;
	shortestPathUnweightedGraph(adj,n,src,dest);
	
	return 0;
}
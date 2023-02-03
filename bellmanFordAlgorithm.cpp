#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<climits>

typedef vector<list<pair<int,int>>> vlpi;
#define INF INT_MAX


void bellManFordAlgorithm(vlpi &adj,int n, int e,int src)
{
	int *dist = new int[n];
	for(int i = 0; i < n; i++)
	{
		dist[i] = INF;
	}
	dist[src] = 0;
	for(int i = 0; i <= n-1; i++)
	{
		for(const auto &elm:adj[i])
		{
			int u = i;
			int v = elm.first;
			int weight = elm.second;
			if(weight + dist[i] < dist[v])
			{
				dist[v] = weight + dist[i];
			}
		}
	}
	
	cout<<"Distance of all vertices throught bellman Ford  "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<i<<" "<<dist[i]<<endl;
	}
	
	for(int i = 0; i < e; i++)
	{
		for(const auto &elm:adj[i])
		{
			int u = i;
			int v = elm.first;
			int w = elm.second;
			if(dist[u] != INF && (dist[u] + w < dist[v]))
			{
				cout<<"Graph contain Negative weight edge "<<endl;
			}
		}
	}
	return ;
}

void addEdge(vlpi &adj,int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
}

int main()
{
	int n,e;
	cin>>n>>e;
	vlpi adj(n);
	for(int i = 0; i < e; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(adj,u,v,w);
	}
	int src;
	cin>>src;
	bellManFordAlgorithm(adj,n,e,src);
	return 0;
}
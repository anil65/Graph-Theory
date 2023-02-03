#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<set>
#include<climits>

typedef vector<list<pair<int,int>>> vlpi;
#define INF INT_MAX

void dijkstraAlgorithm(vlpi &adj,int n,int src)
{
	int *dist = new int[n];
	for(int i = 0; i < n; i++)
	{
		dist[i] = INF;
	}
	dist[src] = 0;
	set<pair<int,int>> s;
	s.insert(make_pair(dist[src],src));
	while(!s.empty())
	{
		auto start = *(s.begin());
		int weight = start.first;
		int node = start.second;
		s.erase(s.find(make_pair(dist[node],node)));
		for(const auto &elm:adj[node])
		{
		 int v = elm.first;
		 int w = elm.second;
		 if(weight + w < dist[v])
		 {
		  	if(s.find(make_pair(dist[v],v)) != s.end())
			  {
			    s.erase(make_pair(dist[v],v));	
			  }
			dist[v] = (weight + w);
			s.insert(make_pair(dist[v],v)); 	
		 }	
		} 
	}
	for(int i = 0; i < n; i++)
	{
		cout<<i<<" "<<dist[i]<<endl;
	}
	return ;
}

void addEdge(vlpi &adj,int u, int v,int w)
{
   adj[u].push_back(make_pair(v,w));	
}

int main()
{
	int n,e;
	cin>>n>>e;
	vlpi adj(n+1);
	for(int i = 0; i < e; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(adj,u,v,w);
	}
	int src;
	cin>>src;
	dijkstraAlgorithm(adj,n,src);
	return 0;
}
#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<queue>
typedef vector<list<int>> vli;

void degreeOfEachNode(int *inDegree,int *outDegree, int *degree, int n)
{
  	for(int i = 0; i < n; i++)
  	{
  		degree[i] = inDegree[i] + outDegree[i];	
	}
	for(int i = 0; i < n ; i++)
	{
		cout<<"InDegree : "<<inDegree[i]<<"->  OutDegre : "<<outDegree[i]<<" ->Degree : "<<degree[i]<<endl;
	}
	for(int i = 0; i < n ; i++)
	{
		if(inDegree[i] == 0)
		{
			cout<<"Source Vertex : "<<i<<endl;
		}
		if(outDegree[i] == 0)
		{
			cout<<"Sink Vertex : "<<i<<endl;
		}
	}
}

void bfs(vli &adj,int n, bool *visited,int src )
{
	queue<int> que;
	visited[src] = true;
	que.push(src);
	
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
			}
		}
	}
}

void addEdge(vli &adj, int *inDegree,int *outDegree, int u, int v)
{
	adj[u].push_back(v);
	inDegree[v]++;
	outDegree[u]++;
}

int main()
{
	int n,e;
	cin>>n>>e;
	vli adj(n);
	
	bool *visited = new bool[n];
	int *inDegree = new int[n];
	int *outDegree = new int[n];
	int *degree = new int[n];
	
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
		inDegree[i] = 0;
		outDegree[i] = 0;
		degree[i] = 0;
	}
	
	for(int i = 0; i < e;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,inDegree,outDegree,u,v);	
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			cnt++;
			bfs(adj,n,visited,i);
		}
	}
	if(cnt == 1)
	{
		cout<<"Graph is Connected "<<endl;
	}
	else 
	{
		cout<<"Graph is Disconnect "<<endl;
		cout<<"Number of Components connected "<<cnt<<endl;
	}
	degreeOfEachNode(inDegree,outDegree,degree,n);
	
	return 0;
}
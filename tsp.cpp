#include<bits/stdc++.h>
using namespace std;
int n;
int graph[100][100];
int travellingSalesman(int s)
{
	vector<int> vertex;
	for(int i=0;i<n;i++){
		if(i!=s)
		vertex.push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<graph[i][j]<<" ";
		cout<<"\n";
	}
	
	int minPath=INT_MAX;
	do{
		int currentWeight=0;
		int k=s;
		
		for(int i=0;i<vertex.size();i++)
		{
			cout<<vertex[i]<<"\n";
			currentWeight+=graph[k][vertex[i]];
			k=vertex[i];
		}
		currentWeight+=graph[k][s];
		minPath=min(currentWeight,minPath);
		cout<<"MIn path"<<minPath<<"\n";
	}while(next_permutation(vertex.begin(),vertex.end()));
			
	return minPath;
}

int main()
{
	int i,j,u,v,w,e;
	cout<<"Enter no of nodes and edges in your graph\n";
	cin>>n>>e;
	memset(graph,0,sizeof(graph));
	for(i=0;i<e;i++)
	{
		cout<<"Enter starting,ending node and weight\n";
		cin>>u>>v>>w;
		graph[u-1][v-1]=w;
		graph[v-1][u-1]=w;
	}
	cout<<"Minimum path is "<<travellingSalesman(0);
}

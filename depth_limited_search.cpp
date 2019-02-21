#include<bits/stdc++.h>
using namespace std;
bool visited[100]={false};
stack<int> pathStack;
bool flag=false;
void dfs(vector<int> vec[],int source,int destination,int heightOfTree,int depth)
{
	cout<<"hello\n";
	if(!flag)
	{
		if(heightOfTree<depth)
		{
			if(source==destination){
				pathStack.push(destination);
			    cout<<"pathStack top"<<pathStack.top();
				cout<<" Reached destination\n";
				flag=true;
				return;
			}
			cout<<"source="<<source<<"\n";
			visited[source]=true;
			pathStack.push(source);
			cout<<"pathStack top"<<pathStack.top();
			for(int i=0;i<vec[source].size();i++)
			{
				if(!visited[vec[source][i]])
				{
					cout<<" nxt node"<<vec[source][i]<<"\n";
					dfs(vec,vec[source][i],destination,heightOfTree+1,depth);
				}
			}

		}
		if(!flag)
		{
			if(!pathStack.empty())
			{
				// cout<<" popping "<<pathStack.top()<<"\n";
				pathStack.pop();
			}
			heightOfTree--;

			}
		
	}
}
int main()
{
	int n,e,i,j,u,v,depth,source,destination;
	cout<<"Enter no. of vertices and edges\n";
	cin>>n>>e;
	cout<<"Enter the depth limit of graph\n";
	cin>>depth;
	cout<<"Enter source and destination vertices\n";
	cin>>source>>destination;
	vector<int> vec[n+1];
	for(i=0;i<e;i++)
	{
		cin>>u>>v;
		vec[u].push_back(v);
	}
	// for(i=0;i<100;i++)
	// 	cout<<visited[i]<<" ";
	for(i=0;i<n;i++)
	{
		cout<<i<<"--> ";
		for(j=0;j<vec[i].size();j++)
		cout<<vec[i][j]<<" ";
	    cout<<"\n";
	}
	dfs(vec,source,destination,0,depth);
	int a[100],k;
	cout<<"stack size"<<pathStack.size()<<"\n";
	if(flag){
		while(!pathStack.empty()){
			a[k++]=pathStack.top();
			pathStack.pop();
		}
		cout<<"path is \n";
		for(i=k-1;i>=0;i--){
			// i==0?cout<<a[i]:cout<<a[i]+"->";
			if(i==0)
				cout<<a[i]<<"\n";
			else
			    cout<<a[i]<<"->";
		}
 	}
 	else{
 		cout<<"Using given depth there is no any path from source to destination\n";
 	}
}
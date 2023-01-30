#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int>adj[N];
vector<int>vis(N,0);

void makeGraph( int nodes, int edges){


	for (int k = 0; k < edges; ++k)
{
		int u,v;
		cin>>u>>v;
	adj[u].push_back(v);
	adj[v].push_back(u);
}
}
void printGraph(int nodes)
{
	for (int i = 1; i < nodes; ++i)
	{
		cout<<i<<"->";
		for(auto j : adj[i])
			cout<<j<<" ";
		cout<<endl;
	}
}

// dfs  -> recurrsive traversal
void dfs(int nodes){

	cout<<nodes<<" ";
	vis[nodes]=1;

	for(auto it : adj[nodes]){
		if(!vis[it])
			dfs(it);
	}
}

//bfs traversal
void bfs(int nodes){
	
	for (int i = 1; i <= nodes; ++i)
	{
		if(!vis[i]){
			queue<int> q;
			q.push(i);
			vis[i]=1;

			while(!q.empty()){
				int n = q.front();     // time complexity -> o(n+edges)
				cout<<n<<" ";       // sp compl -> o(n+e)+o(n)+o(n)
				q.pop();
				
				for(auto it : adj[n]){
					if (!vis[it])
					{
						q.push(it);
						vis[it]=1;
					}
				}

			}
			cout<<endl;

		}
	}
}

// cycle detection using bfs
bool detectCycle(int nodes){
	for (int i = 1; i <= nodes; ++i)
	{
		if(!vis[i]){
			queue<pair<int,int>>q;
			vis[i]=1;
			q.push({i,nodes});

			while(!q.empty()){
				int child = q.front().first;
				int parent = q.front().second;
				q.pop();
				for(auto it : adj[child]){
					if(!vis[it]){
						vis[it]=1;
						q.push({it,child});
					}
					else if(parent != it)return true;
				}

			}
			return false;
		}
	}
}

int main(){

int nodes,edges;
cin>>nodes>>edges;
//vector<int>adj[nodes+1];
//vector<int>vis(nodes+1,0);
makeGraph(nodes,edges);

printGraph(nodes);
// bfs and dfs code not running together
//dfs(nodes);
bfs(nodes);
if(detectCycle(nodes)){
	cout<<"Cycle is present in the graph"<<endl;
}
else{
	cout<<"Cycle not present"<<endl;
}

}
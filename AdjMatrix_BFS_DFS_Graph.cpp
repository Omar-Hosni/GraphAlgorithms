#include <iostream>
#include <vector>

using namespace std;


void printDFS(vector<vector<int>> v, int startVertex, vector<bool> &visited)
{
  cout<<startVertex<<endl;
  
  visited[startVertex] = true;
  
  int n = v.size();
  
  for(int i=0; i < n; i++)
  {
    if(v[startVertex][i] && visited[i] == false)
    {
      printDFS(v,i,visited);
    }
  }
}

void printBFS(vector<vector<int>> v, int startVertex, vector<bool> &visited)
{
  int n = v.size();
  vector<bool> visited(n,false);
  queue<int> q;
  q.push(startVertex);
  visited[startVertex] = true;

  while(!q.empty())
  {
    int currentVertex = q.top();
    q.pop();
    
    cout<<currentVertex<<endl;
    for(int i=0; i < n; i++)
    {
      if(v[currentVertex][i]==1 && visited[i]==false)
      {
        q.push(i);
        visited[i]=true;
      }
    }
  }
}


int main()
{
  int n,e;
  cin>>n>>e;
  
  vector<vector<int>> matrix(n,vector<int>(n,0));
  
  for(int i=0; i <= e; i++)
  {
    int firstVertex, startVertex;
    cin>>firstVertex>>startVertex;
    matrix[firstVertex][startVertex] = 1;
  }
  
  vector<bool> visited(n,false);
  
  printDFS(matrix,0,visited);
  printBFS(matrix,0,visited);
  
}

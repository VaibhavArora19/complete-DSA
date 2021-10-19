#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void printDFS(vector<vector<int>> matrix, int fv, vector<bool> & ans)
{
    
     cout<<fv<<endl;
    int n = ans.size();
    ans[fv] = true;
    for(int i =0; i<n; i++)
    {
        if(matrix[fv][i] == 1 && ans[i] == false)
        {
            printDFS(matrix, i, ans);
        }
    }
}
void DFS(vector<vector<int>> matrix)
{
    int  count =0;
    int n = matrix.size();
vector<bool> ans(n, false);
for(int i =0; i<n; i++)
{
    if(!ans[i])
    {
        count++;
        printDFS(matrix, i , ans);
    }
}
cout<<"the no. of connected components are : "<<count<<endl;
}
void printBFS(vector<vector<int>> matrix, int fv, vector<bool> &ans)
{
    int n = matrix.size();
  //vector<bool> ans(n, false); 
queue<int> q;
q.push(fv);
ans[fv] = true;
while(!q.empty())
{
    int p = q.front();
    q.pop();
    cout<<p<<endl;
    
    int n = ans.size();
      for(int i =0; i<n; i++)
      {
        if(matrix[p][i] ==1 && ans[i] == false)
        {
            q.push(i);
            ans[i] = true;
        } 
      }

}
}
void BFS(vector<vector<int>> matrix)
{
    int count =0;
int n = matrix.size();
vector<bool> ans(n, false);
for(int i =0; i<n; i++)
{
    if(!ans[i])
    {
        count++;
        printBFS(matrix, i,ans);
    }
}
cout<<"the no. of connected components are : "<<count<<endl;
}
int main()
{
int n;
int e;
 //taking vertices and edges as input
cin>>n;
cin>>e;
vector<vector<int>> matrix(n, vector<int>(n,0));
for(int i =1; i<=e; i++)
{
    int fv,sv;
    cin>>fv>>sv;
    matrix[fv][sv] =1;
    matrix[sv][fv] =1;
}

cout<<"DFS order tarversal is "<<endl;
DFS(matrix);
cout<<"*************************"<<endl;
cout<<"BFS order traversal is "<<endl;
BFS(matrix);


}

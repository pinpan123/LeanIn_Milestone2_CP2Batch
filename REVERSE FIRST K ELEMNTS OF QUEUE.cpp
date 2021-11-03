#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
void reverse(queue<int> &q)
{
    if(q.size()==0)
        return;
        
    int front=q.front();
    q.pop();
    reverse(q);
    q.push(front);
}

queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}

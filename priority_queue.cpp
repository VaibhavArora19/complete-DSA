#include<bits/stdc++.h>
using namespace std;
class priority_Queue
{
vector<int> pq;
public:
bool isempty()
{
    return pq.size() ==0; 
}
int getsize()
{
    return pq.size();
}
int getmin()
{
    if(isempty()) return 0;
    return pq[0];
}
void insert(int element)
{
    pq.push_back(element);
    int cI = pq.size()-1;
    while(cI>0)
    {
        int pI = (cI-1)/2;
        if(pq[pI]>pq[cI])
        {
            swap(pq[pI], pq[cI]);
            cI = pI;
        }
        else
        {
            break;
        }
    }
}
int  removemin()
{
    if(isempty())
    {
        return 0;
    }
        int pi =0;
         int ans = pq[0];
        swap(pq[pi], pq[pq.size()-1]);
        pq.pop_back();
        while(true)
        {
        int lci = 2*pi +1;
        int rci = 2*pi +2;
        int mini=pi;
        if(lci<pq.size() && pq[lci] < pq[mini])
        {
            mini = lci;
        }
        if(rci<pq.size() && pq[rci] <pq[mini])
        {
            mini = rci;
        }
        if(pi == mini)
        {
            break;
        }
        swap(pq[pi], pq[mini]);
        pi = mini;
        }
        return ans;
}

};
int main()
{
     priority_Queue p;
p.insert(100);
p.insert(10);
p.insert(15);
p.insert(4);
p.insert(17);
p.insert(21);
p.insert(67);
cout<<p.getsize()<<endl;
cout<<p.getmin()<<endl;
while(!p.isempty())
{
    cout<<p.removemin()<<" ";
}
}
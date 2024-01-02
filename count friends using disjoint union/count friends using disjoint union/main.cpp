#include <iostream>
#include<vector>
#include<list>
#include<stdlib.h>
#include<set>

using namespace std;
vector<int>friends(1000);
class djoint
{
public:

    djoint(int u )
    {
        friends.resize(u);
        for(int i=0; i<u; i++)
        {

            friends[i]=i;
        }
    }
    int find_set(int x)
    {

        if(friends[x]==x)
            return x;
        else
            return find_set(friends[x]);

    }

    int unite(int x,int y)
    {
        int fx=find_set(x);
        int fy=find_set(y);
        if(fx!=fy)
            friends[fx]=fy;

        return 0;

    }

};


int main()
{
    int p;
    cin>>p;
    djoint frn(p);


    int q;
    cin>>q;

    for(int i=0; i<q; i++)
    {
        int x,y;
        cin>>x>>y;
        frn.unite(x,y);



    }
    int in;
    int count=0;
    cin>>in;
    int par=frn.find_set(in);
   // cout<<"friends"<<in<<endl;
    for(int i=0; i<p; i++)
    {

        if(frn.find_set(i)==par)
        {

            count++;
           // cout<<i<<" ";

        }
        cout<<endl;
    }

    cout<<count<<endl;
    return 0;
}

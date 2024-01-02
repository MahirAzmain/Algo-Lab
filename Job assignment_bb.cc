#include<bits/stdc++.h>
using namespace std;
const int N = 4;


class Node
{
public:
    int parent; // parent node
    int nodeNo;
    int pathCost; // total cost so far.
    int promisingCost; // least promising cost.
    int workerID; // which worker will be assigned
    int jobID; // which job has been assigned.
    vector<bool>assigned; // which jobs are available.

    Node() {}
    Node(int w_id, int j_id,vector<bool>_assigned, int node_num,int par)
    {
        workerID = w_id;
        jobID = j_id;
        assigned = _assigned;
        if(jobID+1) assigned[jobID] = true;
        parent = par;
        nodeNo = node_num;
    }
    bool operator<(const Node& other)const
    {
        return promisingCost > other.promisingCost;
    }
};
// Calculate the least promising cost.
int calculateCost(vector<vector<int>>costMatrix, int worker, int job, vector<bool>assigned)
{

    int cost = 0;
    vector<bool>available(N,true);

    for(int i = worker+1; i<N; i++)
    {
        int minimum = INT_MAX;
        int min_index = -1;
        for(int j=0; j<N; j++)
        {
            if(!assigned[j] and available[j] and costMatrix[i][j]<minimum)
            {
                min_index = j;
                minimum = costMatrix[i][j];
            }
        }
        cost+= minimum;
        available[min_index] = false;
    }

    return cost;
}

vector<Node>nodes;
void printAssignments(int node_num)
{
    Node u = nodes[node_num];
    if(u.parent==-1)
        return;

    printAssignments(u.parent);
    cout << "Assign Worker " << char(u.workerID + 'A')
         << " to Job " << u.jobID << endl;

}
int findMinCost(vector<vector<int>>costMatrix)
{


    priority_queue<Node>pq;

    vector<bool>assigned(N,false);


    Node root(-1,-1,assigned,0,-1);
    root.pathCost = root.promisingCost = 0;
    root.workerID = -1;
    nodes.push_back(root);
    pq.push(root);


    while(pq.size())
    {
        Node u = pq.top();
        pq.pop();

        int i = u.workerID+1;

        //cout<<i<<endl;
        //every worker has been assigned.
        if(i==N)
        {
            printAssignments(u.nodeNo);
            return u.pathCost;
        }

        for(int j = 0; j<N; j++)
        {
            if(!u.assigned[j])
            {
                Node v;
                v = Node(i,j,u.assigned,(int)nodes.size(),u.nodeNo);

                v.pathCost = u.pathCost + costMatrix[i][j];

                v.promisingCost = v.pathCost+calculateCost(costMatrix, i, j, v.assigned);
                nodes.push_back(v);
                pq.push(v);
            }
        }
    }

}
int main()
{

    vector<vector<int>>costMatrix =
    {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    cout<<findMinCost(costMatrix)<<endl;
}

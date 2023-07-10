# dsu-snippet
A snippet for DSU in C++

# Use DSU When
1.) Dynamic Graph is present or grpah is changing or being created

2.) Merging different components into single component

3.) Counting the number of components

4.) to tell if 2 nodes are connected or not in O(1) Time

5.) Uses O(1) time for all of the functions , uses O(N) Space

# How to use this snippet
1.) intialize dsu by writing dsu ds(n); creating dsu upto n vertices

2.) ds.findPar(int n) => returns the parent n

3.) ds.unionNodesRank(int a, int b)

   => merge the nodes a & b into single component using Rank vector

4.) ds.unionNodesSize(int a, int b) // Use when you are required to find the size of a component
    
    => merge the nodes a & b into single component using Size vector. To find out the size of 
    component using a node, find out its parent and then return its size.

5.) ds.findVertex(int i, int j, int totalCol)
    
    => Convert the curRow, curCol to the Vertex

# Code Snippet

class dsu {
public:

    vector<int> parent;

    vector<int> rank;
    
    vector<int> size;

    dsu(int n)
    {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]); // Path compression
    }

    void unionNodesRank(int a, int b)
    {
        int parentA = findParent(a);
        int parentB = findParent(b);

        if (parentA == parentB) return;

        if (rank[parentA] < rank[parentB])
        {
            parent[parentB] = parentA;
        }
        else if (rank[parentB] < rank[parentA])
        {
            parent[parentA] = parentB;
        }
        else
        {
            parent[parentB] = parentA;
            rank[parentA]++;
        }
    }

    void unionNodesSize(int a, int b)
    {
        int parentA = findParent(a);
        int parentB = findParent(b);

        if (parentA == parentB) return;
        if (size[parentA] < size[parentB])
        {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
        else
        {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        }
    }

    // To convert {i,j} ( curRowIndex, curColumnIndex, totalColumn) to its vertex number
    int findVertex(int i,int j, int n)
    {
        return i*n+j;
    }
 };

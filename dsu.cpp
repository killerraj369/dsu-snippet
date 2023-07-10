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

    // to convert {i,j}( curRowIndex, curColumnIndex, totalColumn) to its vertex number
    int findVertex(int i,int j, int n)
    {
        return i*n+j;
    }
};
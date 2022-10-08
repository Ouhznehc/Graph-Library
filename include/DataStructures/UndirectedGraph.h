#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include <DataStructures/Graph.h>
using namespace std;

class UndirectedGraph : public Graph
{
    public:
       UndirectedGraph();
       ~UndirectedGraph();
    
    public:
        bool AddEdge(int vertex1, int vertex2);
        bool RemoveEdge(int vertex1, int vertex2);
        int CountEdges() const;
        vector<Edge> GetEdges() const;
        int GetDegree(int vertex) const;
    protected:
        int trival_circle_num = 0;
};
#endif
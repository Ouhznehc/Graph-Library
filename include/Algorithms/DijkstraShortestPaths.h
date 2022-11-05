#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#include "ShortestPaths.h"


template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue>
{
    public:
        DijkstraShortestPaths(const TGraph<TValue> *graph, int source)
        : ShortestPaths<TGraph, TValue>(graph, source)
        , dijkstra()
        {
            if(!graph->ContainsVertex(source)) return;
            while(dijkstra.size()) dijkstra.pop();

        }
        ~DijkstraShortestPaths(){}
    private:
        struct node 
        {  
            int index; 
            TValue value;
            node(int index = int(), TValue value = TValue())
            : index(index), value(value) {}
            bool operator< (const node &b) const {return value < b.value;}
        };
        std::priority_queue<node> dijkstra;
        virtual bool HasPathTo(int destination) const;
};


#endif
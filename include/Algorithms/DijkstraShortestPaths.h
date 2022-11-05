#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#include "ShortestPaths.h"


template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue>
{
    public:
        DijkstraShortestPaths(const TGraph<TValue> *Graph, int source)
        : ShortestPaths<TGraph, TValue>(Graph, source)
        , dijkstra()
        {
            if(!this->graph->ContainsVertex(source)) return;
            while(dijkstra.size()) dijkstra.pop();
            this->distance.clear();
            this->distance[source] = TValue();
            dijkstra.push(node(source, this->distance[source]));
            while(dijkstra.size()){
                auto now  = dijkstra.top().index; dijkstra.pop();
                for(auto to: this->graph->GetOutgoingEdges(now)){
                    int idx = to.GetDestination();
                    TValue dist = this->distance[now] + to.GetWeight();
                    if(!this->HasPathTo(idx) || dist < this->distance[idx]){
                        this->distance[idx] = dist;
                        this->pi[idx] = now; 
                        dijkstra.push(node(idx, this->distance[idx]));
                    }
                }
            }
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
};


#endif
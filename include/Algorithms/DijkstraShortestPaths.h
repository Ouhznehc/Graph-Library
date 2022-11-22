#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#include "ShortestPaths.h"


template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue>
{
    static_assert(std::is_default_constructible_v<TValue>);
    public:
        DijkstraShortestPaths(const TGraph<TValue> *Graph, int Source)
        : ShortestPaths<TGraph, TValue>(Graph, Source)
        , dijkstra()
        {  
            if(!this->graph->ContainsVertex(this->source)) return;
            this->pi[this->source] = this->source;
            this->distance[this->source] = TValue();
            dijkstra.push(node(this->source, TValue()));
            while(dijkstra.size()){
                auto now = dijkstra.top().index; dijkstra.pop();
                for(auto to: this->graph->GetOutgoingEdges(now)){
                    int idx = to.GetDestination();
                    TValue dist = this->distance[now] + to.GetWeight();
                    if((!this->HasPathTo(idx)) || dist < this->distance[idx]){
                        this->distance[idx] = dist;
                        this->pi[idx] = now; 
                        dijkstra.push(node(idx, dist));
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
            node(int index = int(), TValue value = TValue()):index(index), value(value) {}
            bool operator< (const node &b) const {return b.value < value;}
        };
        std::priority_queue<node> dijkstra;
};


#endif
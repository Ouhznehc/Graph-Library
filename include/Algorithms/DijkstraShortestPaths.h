#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#include "ShortestPaths.h"

template <typename TGraph>
class DijkstraShortestPaths : public ShortestPaths<TGraph>
{
    public:
        DijkstraShortestPaths(const TGraph *Graph, int Source)
        : ShortestPaths<TGraph>(Graph, Source)
        , dijkstra()
        {  
            if(!this->graph->ContainsVertex(this->source)) return;
            this->pi[this->source] = this->source;
            this->distance[this->source] = typename TGraph::TValue();
            dijkstra.push(node(this->source, typename TGraph::TValue()));
            while(dijkstra.size()){
                auto now = dijkstra.top().index; dijkstra.pop();
                for(auto to: this->graph->GetOutgoingEdges(now)){
                    int idx = to.GetDestination();
                    typename TGraph::TValue dist = this->distance[now] + to.GetWeight();
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
            typename TGraph::TValue value;
            node(int index = int(), typename TGraph::TValue value = typename TGraph::TValue()):index(index), value(value) {}
            bool operator< (const node &b) const {return b.value < value;}
        };
        std::priority_queue<node> dijkstra;
};


#endif
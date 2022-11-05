#ifndef DIJKSTRA_SHORTEST_PATHS
#define DIJKSTRA_SHORTEST_PATHS

#include "ShortestPaths.h"


template <template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue>
{
    public:
        DijkstraShortestPaths(const TGraph<TValue> *Graph, int Source)
        : ShortestPaths<TGraph, TValue>(Graph, Source)
        , dijkstra()
        {
            if(!this->graph->ContainsVertex(this->source)) return;
            std::unordered_map<int, bool> visit;
            while(dijkstra.size()) dijkstra.pop();
            this->distance.clear();
            this->pi.clear();
            this->distance[this->source] = TValue();
            visit[this->source] = true;
            dijkstra.push(node(this->source, this->distance[this->source]));
            while(dijkstra.size()){
                auto now  = dijkstra.top().index; dijkstra.pop();
                if(visit.find(now) != visit.end()) continue;
                visit[now] = true;
                for(auto to: this->graph->GetOutgoingEdges(now)){
                    int idx = to.GetDestination();
                    TValue dist = this->distance.at(now) + to.GetWeight();
                    if(dist < this->distance[idx]){
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
            node(int index = int(), TValue value = TValue()):index(index), value(value) {}
            bool operator< (const node &b) const {return b.value < value;}
        };
        std::priority_queue<node> dijkstra;
};


#endif
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
            if(this->graph->ContainsVertex(this->source)) return;
            unordered_multiset<int> visit;
            while(dijkstra.size()) dijkstra.pop();
            this->distance.clear();
            this->pi.clear();
            this->distance[this->source] = TValue();
            visit.insert(this->source);
            dijkstra.push(node(this->source, this->distance[this->source]));
            while(dijkstra.size()){
                auto now  = dijkstra.top().index; dijkstra.pop();
                for(auto to: this->graph->GetOutgoingEdges(now)){
                    int idx = to.GetDestination();
                    TValue dist = this->distance[now] + to.GetWeight();
                    if(visit.find(idx) == visit.end() || dist < this->distance[idx]){
                        this->distance[idx] = dist;
                        this->pi[idx] = now; 
                        visit.insert(idx);
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
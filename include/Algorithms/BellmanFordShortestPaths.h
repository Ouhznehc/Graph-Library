#ifndef BELLMANFORDSHORTESTPATHS_H
#define BELLMANFORDSHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>
#include <DataStructures/WeightedEdge.h>

template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph>{
    static_assert(std::is_default_constructible_v<typename TGraph::TValue>, "TGraph requires default-constructible elements");
    public:
        BellmanFordShortestPaths(const TGraph *Graph, int Source)
            : ShortestPaths<TGraph>(Graph, Source){
            if(!this->graph->ContainsVertex(this->source)) return;
            std::vector<int> vertices = this->graph->GetVertices();  
            this->distance[this->source] = typename TGraph::TValue();
            this->pi[this->source] = this->source;
            spfa.push(this->source);
            while (spfa.size()) {
                int now = spfa.front(); spfa.pop();
                for(auto edge : this->graph->GetOutgoingEdges(now)){
                    int y = edge.GetDestination();
                    if(this->distance.find(y) == this->distance.end()){
                        this->distance[y] = this->distance[now] + edge.GetWeight();
                        this->pi[y] = now;
                        spfa.push(y);
                    }
                    else if(this->distance[y] > this->distance[now] + edge.GetWeight()){
                        this->distance[y] = this->distance[now] + edge.GetWeight();
                        this->pi[y] = now;
                        spfa.push(y);
                    }
                }
            }
        }
        virtual ~BellmanFordShortestPaths();
    private:
        std::queue<int> spfa;

};

#endif

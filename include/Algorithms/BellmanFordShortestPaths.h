#ifndef BELLMAN_FORD_SHORTEST_PATHS_H
#define BELLMAN_FORD_SHORTEST_PATHS_H

#include <Algorithms/ShortestPaths.h>
#include <DataStructures/WeightedEdge.h>
#include <Exceptions/NegativeCycleException.h>

template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph>{
    public:
        BellmanFordShortestPaths(const TGraph *Graph, int Source)
            : ShortestPaths<TGraph>(Graph, Source){
            if(!this->graph->ContainsVertex(this->source)) return;
            int vertex_num = this->graph->CountVertices();
            std::vector<int> vertices = this->graph->GetVertices();  
            this->distance[this->source] = typename TGraph::TValue();
            this->pi[this->source] = this->source;
            spfa.push(this->source);
            while (spfa.size()) {
                int now = spfa.front(); spfa.pop();
                for(auto edge : this->graph->GetOutgoingEdges(now)){
                    int to = edge.GetDestination();
                    if(this->distance.find(to) == this->distance.end()){
                        this->distance[to] = this->distance[now] + edge.GetWeight();
                        this->pi[to] = now;
                        spfa.push(to);
                    }
                    else if(this->distance[to] > this->distance[now] + edge.GetWeight()){
                        this->distance[to] = this->distance[now] + edge.GetWeight();
                        this->pi[to] = now;
                        release_time[to]++;
                        if(release_time[to] > vertex_num){
                            throw NegativeCycleException("Bellman-Ford");
                        }
                        spfa.push(to);
                    }
                }
            }
        }
        virtual ~BellmanFordShortestPaths(){};
    private:
        std::queue<int> spfa;
        std::map<int, int> release_time;
};

#endif

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
            while (q.size()) {
                int now = q.front();
                q.pop();
                this->vis[now] = false;

                std::vector<WeightedEdge<typename TGraph::value_type>> edges= graph->GetOutgoingEdges(now);
                for(auto ed : edges){
                int y = ed.GetDestination();
                if(this->d.find(y) == this->d.end()){
                    this->d[y] = this->d[now] + ed.GetWeight();
                    this->pre[y] = now;
                    q.push(y);
                    this->vis[y] = true;
                }
                else if(this->d[y] > this->d[now] + ed.GetWeight()){
                    this->d[y] = this->d[now] + ed.GetWeight();
                    this->pre[y] = now;
                    if(this->vis[y] == false){
                    this->vis[y] = true;
                    q.push(y);
                    }
                }
                }
            }
        }
        virtual ~BellmanFordShortestPaths();
    private:
        std::queue<int> spfa;

};

#endif

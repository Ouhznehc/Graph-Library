#ifndef BELLMANFORDSHORTESTPATHS_H
#define BELLMANFORDSHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>
#include <DataStructures/WeightedEdge.h>

template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph>{
 static_assert(std::is_default_constructible_v<typename TGraph::TValue>, "TGraph requires default-constructible elements");
 public:
  BellmanFordShortestPaths(const TGraph *graph, int source);
  virtual ~BellmanFordShortestPaths();
};

template<typename TGraph>
BellmanFordShortestPaths<TGraph>::BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source){
  if(!graph->ContainsVertex(source))return;
  int n = graph->CountVertices();
  this->d[source] = typename TGraph::value_type();
  this->pre[source] = source;
  this->vis[source] = true;
  std::vector<WeightedEdge<typename TGraph::value_type>> edges = graph->GetEdges();
  for(int k = 1; k <= n - 1; k ++){
    for(auto ed:edges){
        int x = ed.GetSource(), y = ed.GetDestination();
        // printf("%d %d s%d\n",k,x,y);
        if(this->d.find(x) == this->d.end())continue;
        if(this->d.find(y) == this->d.end()){
            this->d[y] = this->d[x] + ed.GetWeight();
            this->pre[y] = x;
            this->vis[y] = true;
            // printf("%d %d s%d %d\n",k,x,y,this->d[y]);
        }
        else if(this->d[y] > this->d[x] + ed.GetWeight()){
            this->d[y] = this->d[x] + ed.GetWeight();
            this->pre[y] = x;
            // printf("%d %d s%d %d\n",k,x,y,this->d[y]);
        }
    }
  }
  // if(!graph->ContainsVertex(source))return;
  // std::vector<int>vert = graph->GetVertices();  
  // this->d[source] = typename TGraph::value_type();
  // this->pre[source] = source;
  // std::queue<int>q;
  // q.push(source);
  // while (q.size()) {
  //   int now = q.front();
  //   q.pop();
  //   this->vis[now] = false;

  //   std::vector<WeightedEdge<typename TGraph::value_type>> edges= graph->GetOutgoingEdges(now);
  //   for(auto ed : edges){
  //     int y = ed.GetDestination();
  //     if(this->d.find(y) == this->d.end()){
  //       this->d[y] = this->d[now] + ed.GetWeight();
  //       this->pre[y] = now;
  //       q.push(y);
  //       this->vis[y] = true;
  //     }
  //     else if(this->d[y] > this->d[now] + ed.GetWeight()){
  //       this->d[y] = this->d[now] + ed.GetWeight();
  //       this->pre[y] = now;
  //       if(this->vis[y] == false){
  //         this->vis[y] = true;
  //         q.push(y);
  //       }
  //     }
  //   }
  // }
}

template<typename TGraph>
BellmanFordShortestPaths<TGraph>::~BellmanFordShortestPaths(){}

#endif

#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <bits/stdc++.h>

template <typename TGraph>
class DepthFirstSearcher {
  public:
    static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
    static std::optional<int> FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
  private:
    static void dfsAction(const TGraph *graph, int now, std::map<int,bool> *visit, std::function<void(int)> action);
    static std::optional<int> dfsPredicate(const TGraph *graph, int now, std::map<int,bool> *visit, std::function<bool(int)> predicate);
    
};

template <typename TGraph>
void DepthFirstSearcher<TGraph>::dfsAction(const TGraph *graph, int now, std::map<int,bool> *visit, std::function<void(int)> action){
  visit->insert({now, true});
  action(now);
  std::vector<int> to = graph->GetNeighbors(now);
  for(auto it : to){
    if(visit->find(it) != visit->end()) continue;
    dfsAction(graph, it, visit, action);
  }
  return;
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::dfsPredicate(const TGraph *graph, int now, std::map<int,bool> *visit, std::function<bool(int)> predicate){
  visit->insert({now, true});
  if(predicate(now))return (std::optional<int>) now;
  std::vector<int> to = graph->GetNeighbors(now);
  for(auto it : to){
    if(visit->find(it) != visit->end())continue;
    std::optional<int> res = dfsPredicate(graph, it, visit, predicate);
    if(res != std::nullopt)
      return res;
  }
  return std::nullopt;
}

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action){
  if(!graph->ContainsVertex(start))return;
  std::map<int,bool>visit;
  dfsAction(graph, start, &visit, action);
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate){
  if(!graph->ContainsVertex(start))return std::nullopt;
  std::map<int,bool>visit;
  return dfsPredicate(graph, start, &visit, predicate);
}
#endif

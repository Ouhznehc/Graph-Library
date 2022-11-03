#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <bits/stdc++.h>

template <typename TGraph>
class BreadthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action);
  static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate);
};

template <typename TGraph>
void BreadthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, std::function<void(int)> action){
  if(!graph->ContainsVertex(start))return;
  std::map<int,bool> visit; visit.clear();
  std::queue<int> q; q.push(start);
  while(q.size()){
    int now = q.front(); q.pop();
    if(visit.find(now) != visit.end()) continue;
    action(now);
    visit.insert({now, true});
    std::vector<int> to = graph->GetNeighbors(now);
    for(auto it: to){
      if(visit.find(it) != visit.end()) continue;
      q.push(it);
    }
  }
}

template <typename TGraph>
std::optional<int> BreadthFirstSearcher<TGraph>::TryFindFirstVertex(const TGraph *graph, int start, std::function<bool(int)> predicate){
  if(!graph->ContainsVertex(start))return std::nullopt;
  std::map<int,bool>visit; visit.clear();
  std::queue<int> q; q.push(start);
  while(q.size()){
    int now = q.front(); q.pop();
    if(visit.find(now) != visit.end()) continue;
    if(predicate(now)) return (std::optional<int>) now;
    visit.insert({now, true});
    std::vector<int> to = graph->GetNeighbors(now);
    for(auto it: to){
      if(visit.find(it) != visit.end()) continue;
      q.push(it);
    }
  }
  return std::nullopt;
}

#endif
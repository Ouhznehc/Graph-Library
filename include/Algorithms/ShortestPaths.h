#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <bits/stdc++.h>

template <typename TGraph>
class ShortestPaths {
    static_assert(std::is_default_constructible_v<typename TGraph::TValue>, "TValue requires default constructor");
    //static_assert(std::is_same_v<TGraph, WeightedGraph<typename TGraph::TValue>> || std::is_same_v<TGraph, WeightedGraph<typename TGraph::TValue>>, "TGraph should be weighted");
    //static_assert(requires(typename TGraph::TValue a, typename TGraph::TValue b){a + b;}, "TValue requires operator+");
 public:
  ShortestPaths() = delete;
  ShortestPaths(const TGraph *graph, int source):source(source), graph(graph), distance(), pi(){}
  virtual ~ShortestPaths(){}
 public:
  bool HasPathTo(int destination) const {return distance.find(destination) != distance.end();}
  std::optional<typename TGraph::TValue> TryGetDistanceTo(int destination) const
  {
    if(!HasPathTo(destination)) return std::nullopt;
    else return std::optional<typename TGraph::TValue>(distance.at(destination));
  }
  std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
  {
    if(!HasPathTo(destination)) return std::nullopt;
    std::vector<int> res;
    while(destination != source){
      res.push_back(destination);
      destination = pi.at(destination);
    }
    res.push_back(source);
    std::reverse(res.begin(), res.end());
    return std::optional<std::vector<int>>(res);
  }
  protected:
    std::unordered_map<int, typename TGraph::TValue> distance;
    std::unordered_map<int, int> pi;
    const TGraph *graph;
    const int source;
};

#endif


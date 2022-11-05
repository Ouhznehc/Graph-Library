#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <bits/stdc++.h>

template <template<typename> class TGraph, typename TValue>
class ShortestPaths {
 public:
  ShortestPaths() = delete;
  ShortestPaths(const TGraph<TValue> *graph, int source):source(source), distance(), pi(){}
  virtual ~ShortestPaths();
 public:
  bool HasPathTo(int destination) const {return distance.find(destination) != distance.end();}
  std::optional<TValue> TryGetDistanceTo(int destination) const
  {
    if(!HasPathTo(destination)) return std::nullopt;
    else return distance[destination];
  }
  std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const
  {
    if(!HasPathTo(destination)) return std::nullopt;
    std::vector<int> res;
    while(destination != source){
      res.push_back(destination);
      destination = pi[destination];
    }
    std::reverse(res.begin(), res.end());
    return std::optional<std::vector<int>>res;
  }
  protected:
    std::unordered_map<int, TValue> distance;
    std::unordered_map<int, int> pi;
    int source;
};

#endif


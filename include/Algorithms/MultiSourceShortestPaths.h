#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>
#include <unordered_map>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>

template <typename TGraph>
class MultiSourceShortestPaths 
{
  static_assert(std::is_default_constructible_v<typename TGraph::TValue>, "TValue requires default constructor");
  public:
    MultiSourceShortestPaths() = delete;
    explicit MultiSourceShortestPaths(const TGraph *graph)
    {
      auto edges = graph->GetAllEdges();
      for(auto edge : edges){
        int source = edge.GetSource();
        int destination = edge.GetDestination();
        int weight = edge.GetWeight();
        distance.emplace(std::make_pair(source, destination), weight);
        pi.emplace(std::make_pair(source, destination), destination);
      }
      auto vertices = graph->GetVertices();
      for(auto vertex : vertices){
        distance.emplace(std::make_pair(vertex, vertex), typename TGraph::TValue());
      }
    };
    virtual ~MultiSourceShortestPaths(){}
  public:
    bool HasPathOf(int source, int destination) const {
      return distance.find(std::make_pair(source, destination)) != distance.end();
    }
    std::optional<typename TGraph::TValue> TryGetDistanceOf(int source, int destination) const {
      if(!HasPathOf(source, destination)) return std::nullopt;
      else return std::optional<typename TGraph::TValue>(distance.at(std::make_pair(source, destination)));
    }
    std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const {
      if(!HasPathOf(source, destination)) return std::nullopt;
      std::vector<int> ans;
      while(source != destination){
        ans.push_back(destination);
        destination = pi.at(std::make_pair(source, destination));
      }
      ans.push_back(source);
      std::reverse(ans.begin(), ans.end());
      return std::optional<std::vector<int>>(ans);
    }
  protected:
    std::map<std::pair<int, int>, typename TGraph::TValue> distance;
    std::map<std::pair<int,int>, int> pi;
};

#endif

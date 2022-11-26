#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>

template <typename TGraph>
class MultiSourceShortestPaths 
{
  static_assert(std::is_default_constructible_v<typename TGraph::TValue>, "TValue requires default constructor");
  public:
    MultiSourceShortestPaths() = delete;
    explicit MultiSourceShortestPaths(const TGraph *graph):graph(graph), distance(), pi(){};
    virtual ~MultiSourceShortestPaths(){};
  public:
    bool HasPathOf(int source, int destination) const;
    std::optional<typename TGraph::TValue> TryGetDistanceOf(int source, int destination) const;
    std::optional<std::vector<int>> TryGetShortestPathOf(int source, int destination) const;
  protected:
    std::unordered_map<std::pair<int, int>, typename TGraph::TValue> distance;
    std::unordered_map<int, int> pi;
    const TGraph *graph;
};

#endif
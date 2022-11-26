#include <DataStructures/Edge.h>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <Algorithms/DijkstraShortestPaths.h>
#include <Algorithms/ShortestPaths.h>
#include <Algorithms/BellmanFordShortestPaths.h>
#include <Algorithms/MultiSourceShortestPaths.h>
#include <Algorithms/FloydShortestPaths.h>

using namespace std;

struct strict_int {
    int val;
    strict_int(int v): val(v) {}
    strict_int();
};

int main()
{
   return 0;
}
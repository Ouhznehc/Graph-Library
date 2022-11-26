#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "WeightedEdge.h"
#include "DataStructures/Graph.h"
#include <set>
#include <map>
#include <unordered_map>

template <typename T>
class WeightedGraph : public Graph
{
    public:
        typedef T TValue;
        WeightedGraph(){};
        ~WeightedGraph(){};
    public:
        virtual bool AddEdge(int vertex1, int vertex2, T weight){
            bool flag = Graph::AddEdge(vertex1, vertex2);
            if(flag) WeightMap.emplace(Edge(vertex1, vertex2), weight);
            return flag;    
        }

        virtual bool RemoveEdge(int vertex1, int vertex2){
            bool flag = Graph::RemoveEdge(vertex1, vertex2);
            if(flag) WeightMap.erase(Edge(vertex1, vertex2));
            return flag;
        }

    public:
        T GetWeight(int vertex1, int vertex2) const {
            if(WeightMap.find(Edge(vertex1, vertex2)) == WeightMap.end()) return 0;
            else return WeightMap.at(Edge(vertex1, vertex2));
        }

        std::vector<WeightedEdge<T>> GetEdges() const {
            std::vector<WeightedEdge<T>> edges;
            for(auto it: Edges)
                edges.push_back(WeightedEdge<T>(it.GetSource(), it.GetDestination(), GetWeight(it.GetSource(), it.GetDestination())));
            return edges;
        }

        std::vector<WeightedEdge<T>> GetAllEdges() const {
            return GetEdges();
        }
        
        std::vector<WeightedEdge<T>> GetIncomingEdges(int vertex) const {
            std::vector<WeightedEdge<T>> null;
            if(IncomingEdges.find(vertex) != IncomingEdges.end()){
                for(auto it: IncomingEdges.at(vertex)){
                    auto tmp = WeightedEdge<T>(it.GetSource(), it.GetDestination(), GetWeight(it.GetSource(), it.GetDestination()));
                    null.push_back(tmp);
                }
            }
            return null;
        }

        std::vector<WeightedEdge<T>> GetOutgoingEdges(int vertex) const{
            std::vector<WeightedEdge<T>> null;
            if(OutgoingEdges.find(vertex) != OutgoingEdges.end()){
                for(auto it : OutgoingEdges.at(vertex)){
                    auto tmp = WeightedEdge<T>(it.GetSource(), it.GetDestination(), GetWeight(it.GetSource(), it.GetDestination()));
                    null.push_back(tmp);
                }
            }
            return null;
        }
        
    protected:
        std::map<Edge, T> WeightMap;
};

#endif
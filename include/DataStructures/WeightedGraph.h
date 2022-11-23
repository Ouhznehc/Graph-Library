#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "WeightedEdge.h"
#include "DataStructures/Graph.h"
#include <bits/stdc++.h>

template <typename weightType>
class WeightedGraph : public Graph
{
    static_assert(std::is_default_constructible_v<weightType>, "TValue requires default constructor");
    public:
        typedef weightType TValue;
        WeightedGraph(){};
        ~WeightedGraph(){};
    public:
        virtual bool AddEdge(int vertex1, int vertex2, weightType weight){
            bool flag = Graph::AddEdge(vertex1, vertex2);
            if(flag) WeightedEdges.insert(WeightedEdge<weightType>(vertex1, vertex2, weight));
            return flag;    
        }

        virtual bool RemoveEdge(int vertex1, int vertex2){
            bool flag = Graph::RemoveEdge(vertex1, vertex2);
            if(flag) WeightedEdges.erase(WeightedEdge<weightType>(vertex1, vertex2, GetWeight(vertex1, vertex2)));
            return flag;
        }

    public:
        weightType GetWeight(int vertex1, int vertex2) const{
            if(WeightedEdges.find(WeightedEdge<weightType>(vertex1, vertex2, weightType())) == WeightedEdges.end()) return weightType();
            else return WeightedEdges.find(WeightedEdge<weightType>(vertex1, vertex2, weightType()))->GetWeight();
        }

        std::vector<WeightedEdge<weightType>> GetEdges() const{
            std::vector<WeightedEdge<weightType>> edges;
            for(auto it: WeightedEdges)
                edges.push_back(it);
            return edges;
        }

        std::vector<WeightedEdge<weightType>> GetIncomingEdges(int vertex) const{
            std::vector<WeightedEdge<weightType>> null;
            if(IncomingEdges.find(vertex) != IncomingEdges.end()){
                for(auto it : IncomingEdges.at(vertex)){
                    auto tmp = WeightedEdge<weightType>(it.GetSource(), it.GetDestination(), GetWeight(it.GetSource(), it.GetDestination()));
                    null.push_back(tmp);
                }
            }
            return null;
        }

        std::vector<WeightedEdge<weightType>> GetOutgoingEdges(int vertex) const{
            std::vector<WeightedEdge<weightType>> null;
            if(OutgoingEdges.find(vertex) != OutgoingEdges.end()){
                for(auto it : OutgoingEdges.at(vertex)){
                    auto tmp = WeightedEdge<weightType>(it.GetSource(), it.GetDestination(), GetWeight(it.GetSource(), it.GetDestination()));
                    null.push_back(tmp);
                }
            }
            return null;
        }
        
    protected:
        std::set<WeightedEdge<weightType>> WeightedEdges;

};

#endif
#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "WeightedEdge.h"
#include "DataStructures/Graph.h"
#include <bits/stdc++.h>
using namespace std;

template <typename weightType>
class WeightedGraph : public Graph
{
    public:
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
            return WeightedEdges.find(WeightedEdge<weightType>(vertex1, vertex2, 0))->GetWeight();
        }

        vector<WeightedEdge<weightType>> GetEdges() const{
            vector<WeightedEdge<weightType>> edges;
            for(auto it: WeightedEdges)
                edges.push_back(it);
            return edges;
        }

        vector<WeightedEdge<weightType>> GetIncomingEdges(int vertex) const{
            vector<WeightedEdge<weightType>> null;
            if(IncomingEdges.find(vertex) != IncomingEdges.end()){
                for(auto it : IncomingEdges.at(vertex)){
                    auto tmp = WeightedEdge<weightType>(it.GetSource(), it.GetDestination(), GetWeight(it.GetSource(), it.GetDestination()));
                    null.push_back(tmp);
                }
            }
            return null;
        }

        vector<WeightedEdge<weightType>> GetOutgoingEdges(int vertex) const{
            vector<WeightedEdge<weightType>> null;
            if(OutgoingEdges.find(vertex) != OutgoingEdges.end()){
                for(auto it : OutgoingEdges.at(vertex)){
                    auto tmp = WeightedEdge<weightType>(it.GetSource(), it.GetDestination(), GetWeight(it.GetSource(), it.GetDestination()));
                    null.push_back(tmp);
                }
            }
            return null;
        }
        
    protected:
        set<WeightedEdge<weightType>> WeightedEdges;

};

#endif
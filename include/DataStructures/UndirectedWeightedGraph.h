#ifndef UNDIRECTED_WEIGHTED_GRAPH_H
#define UNDIRECTED_WEIGHTED_GRAPH_H

#include <DataStructures/WeightedGraph.h>

template <typename weightType>
class UndirectedWeightedGraph : public WeightedGraph<weightType>
{
    public:
        typedef weightType TValue;
        UndirectedWeightedGraph(){};
       ~UndirectedWeightedGraph(){};
    
    public:
        bool AddEdge(int vertex1, int vertex2, weightType weight){
            if(vertex1 == vertex2){
                bool flag = WeightedGraph<weightType>::AddEdge(vertex1, vertex2, weight);
                if(flag)trival_circle_num++;
                return flag;
            }
            else{
                return WeightedGraph<weightType>::AddEdge(vertex1, vertex2, weight) && WeightedGraph<weightType>::AddEdge(vertex2, vertex1, weight);
            }
        }

        bool RemoveEdge(int vertex1, int vertex2){
            if(vertex1 == vertex2){
                bool flag = WeightedGraph<weightType>::RemoveEdge(vertex1, vertex2);
                if(flag) trival_circle_num--;
                return flag;
            }
            else {
                return WeightedGraph<weightType>::RemoveEdge(vertex1, vertex2) && WeightedGraph<weightType>::RemoveEdge(vertex2, vertex1);
            }    
        }

        int CountEdges() const{
            return (WeightedGraph<weightType>::CountEdges() + trival_circle_num) / 2;
        }

        std::vector<WeightedEdge<weightType>> GetEdges() const{
            std::vector<WeightedEdge<weightType>> ans;
            for(auto i = WeightedGraph<weightType>::WeightedEdges.begin(); i != WeightedGraph<weightType>::WeightedEdges.end(); i++){
                ans.push_back(*i);
                if(i->GetSource() != i->GetDestination()) i++;
            }
            return ans;
        }

        int GetDegree(int vertex) const{
            if(WeightedGraph<weightType>::ContainsEdge(vertex, vertex))
                return WeightedGraph<weightType>::GetNeighbors(vertex).size() + 1;
            else
                return WeightedGraph<weightType>::GetNeighbors(vertex).size();
        }
        
    protected:
        int trival_circle_num = 0;
};
#endif
#ifndef UNDIRECTED_WEIGHTED_GRAPH_H
#define UNDIRECTED_WEIGHTED_GRAPH_H

#include <DataStructures/WeightedGraph.h>

template <typename T>
class UndirectedWeightedGraph : public WeightedGraph<T>
{
    //static_assert(std::is_default_constructible_v<T>, "TGraph requires default-constructible elements");
    public:
        typedef T TValue;
        UndirectedWeightedGraph(){};
       ~UndirectedWeightedGraph(){};
    
    public:
        bool AddEdge(int vertex1, int vertex2, T weight){
            if(vertex1 == vertex2){
                bool flag = WeightedGraph<T>::AddEdge(vertex1, vertex2, weight);
                if(flag)trival_circle_num++;
                return flag;
            }
            else{
                return WeightedGraph<T>::AddEdge(vertex1, vertex2, weight) && WeightedGraph<T>::AddEdge(vertex2, vertex1, weight);
            }
        }

        bool RemoveEdge(int vertex1, int vertex2){
            if(vertex1 == vertex2){
                bool flag = WeightedGraph<T>::RemoveEdge(vertex1, vertex2);
                if(flag) trival_circle_num--;
                return flag;
            }
            else {
                return WeightedGraph<T>::RemoveEdge(vertex1, vertex2) && WeightedGraph<T>::RemoveEdge(vertex2, vertex1);
            }    
        }

        int CountEdges() const{
            return (WeightedGraph<T>::CountEdges() + trival_circle_num) / 2;
        }

        std::vector<WeightedEdge<T>> GetEdges() const{
            std::vector<WeightedEdge<T>> ans;
            for(auto i = Edges.begin(); i != Edges.end(); i++){
                ans.push_back(WeightedEdge(it->GetSource(), it->GetDestination(), GetWeight(it->GetSource(), it->GetDestination())));
                if(i->GetSource() != i->GetDestination()) i++;
            }
            return ans;
        }

        int GetDegree(int vertex) const{
            if(WeightedGraph<T>::ContainsEdge(vertex, vertex))
                return WeightedGraph<T>::GetNeighbors(vertex).size() + 1;
            else
                return WeightedGraph<T>::GetNeighbors(vertex).size();
        }
        
    protected:
        int trival_circle_num = 0;
};
#endif
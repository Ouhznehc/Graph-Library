#ifndef FLOYD_SHORTEST_PATHS
#define FLOYD_SHORTEST_PATHS

#include "MultiSourceShortestPaths.h"
#include <Exceptions/NegativeCycleException.h>

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    public:
        FloydShortestPaths(const TGraph *graph)
           :MultiSourceShortestPaths<TGraph>(graph)
        {
            auto vertices = graph->GetVertices();
            for(auto mid : vertices)
                for(auto i : vertices)
                    for(auto j : vertices){
                        if(!this->HasPathOf(i, mid) || !this->HasPathOf(mid, j)) continue;
                        typename TGraph ::TValue dist = this->distance.at(std::make_pair(i, mid)) + this->distance.at(std::make_pair(mid, j));
                        if(!this->HasPathOf(i, j) || dist < this->distance.at(std::make_pair(i, j))){
                            this->distance[std::make_pair(i, j)] = dist;
                            this->pi[std::make_pair(i, j)] = this->pi[std::make_pair(i, mid)];
                        }
                    }
            for(auto i : vertices){
                if(this->distance[std::make_pair(i, i)] < typename:TGraph :: TValue()){
                    throw NegativeCycleException("Floyd");
                }
            }
        }
        ~FloydShortestPaths(){}
};

#endif
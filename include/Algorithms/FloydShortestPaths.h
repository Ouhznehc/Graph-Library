#ifndef FLOYD_SHORTEST_PATHS
#define FLOYD_SHORTEST_PATHS

#include "MultiSourceShortestPaths.h"

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
                        typename TGraph ::TValue dist = this->TryGetDistanceOf(i, mid) + this->TryGetDistanceOf(mid, j);
                        if(!this->HasPathOf(i, j) || dist < this->distance.at(std::make_pair(i, j))){
                            this->distance.emplace(std::make_pair(i, j), dist);
                            this->pi.emplace(std::make_pair(i, j), mid);
                        }
                    }
        }
        ~FloydShortestPaths(){}
};

#endif
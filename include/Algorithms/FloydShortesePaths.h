#ifndef FLOYD_SHORTEST_PATHS
#define FLOYD_SHORTEST_PATHS

#include "MultiSourceShortestPaths.h"

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph>
{
    public:
        FloydShortestPaths(const TGraph *Graph)
            :MultiSourceShortestPaths<TGraph>(Graph)
        {
            auto vertices = this->graph->GetVertices();
            for(auto mid : vertices)
                for(auto i : vertices)
                    for(auto j : vertices){
                        typename TGraph ::TValue dist = this->distance.at((*i, *mid)) + this->distance.at(*mid, *j);
                        if(!this->HasPathOf(*i, *j) || dist < this->distance.at((*i, *j))){
                            this->distance.emplace((*i, *j), dist);
                            this->pi.emplace((*i, *j), *mid);
                        }
                    }
        }
};

#endif
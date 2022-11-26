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
            for(auto mid : vertices){
                for(auto i : vertices){
                    for(auto j : vertices){
                        if(){
                            this->distance.emplace()
                        }
                        else{

                        }
                    }
                }
            }
        }
};

#endif
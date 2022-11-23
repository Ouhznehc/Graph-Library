#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

#include "Edge.h"
template <typename weightType>
class WeightedEdge: public Edge
{
    public:
        WeightedEdge(int source, int destination, weightType weight):Edge(source, destination), weight(weight){};
        WeightedEdge(int source, int destination):Edge(source, destination){};
        ~WeightedEdge(){};
        bool operator==(const WeightedEdge<weightType> &b) const {
            return this->source == b.source && this->destination == b.destination;
        }
        bool operator< (const WeightedEdge<weightType> &b) const{
            if(this->source < b.source) return true;
            if(this->source == b.source) return this->destination < b.destination;
            return false;
        }
    public:
        weightType GetWeight() const{ return this->weight;}
    private:
        weightType weight;
};

#endif
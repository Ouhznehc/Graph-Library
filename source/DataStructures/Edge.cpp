#include <DataStructures/Edge.h>

Edge::Edge(int source, int destination){
    this->source = source;
    this->destination = destination;
}

Edge::~Edge(){}


int Edge::GetDestination() const {
    return destination;
}

int Edge::GetSource() const {
    return source;
}
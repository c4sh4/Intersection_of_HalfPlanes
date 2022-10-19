#ifndef NTERSECTION_OF_HALFPLANES_WITH_THE_BOX__INTERALG_H
#define NTERSECTION_OF_HALFPLANES_WITH_THE_BOX__INTERALG_H
#pragma once
//STL
#include <iostream>
#include <vector>
#include <deque>
//myIncludes
#include "halfPlane.h"

//
class interAlg {
public:
    std::deque<halfPlane> deq;
    std::vector<Vec> vertex;
    //constructor
    interAlg();
    //build intersection of half-planes in a n(log(n))
    void getIntersection(polytopes& pt);
    //vertex calculation
    static Vec vert(halfPlane& hp1, halfPlane& hp2);
    //checking a point for belonging to a half-plane
    static bool checkin(halfPlane& hp1, halfPlane& hp2, halfPlane& plane);
    //
    void getVertexes();
};
//ostream
std::ostream& operator<<(std::ostream& os, const interAlg& alg);


#endif //NTERSECTION_OF_HALFPLANES_WITH_THE_BOX__INTERALG_H

#ifndef NTERSECTION_OF_HALFPLANES_WITH_THE_BOX__HALFPLANE_H
#define NTERSECTION_OF_HALFPLANES_WITH_THE_BOX__HALFPLANE_H
#pragma once
//STL
#include <iostream>
#include <vector>
//myIncludes
#include "Vec.h"

// Ax+By+C>=0
class halfPlane {
public:
    double A;
    double B;
    double C;
    Vec site; //interior point of halfPlane
    //constructor
    halfPlane();
    halfPlane(Vec p1, Vec p2, Vec ip);  // p1 and p2 - pair of points, ip - interior point
    //check function
    double pointStatus(Vec& vec) const; // status of random point - interior or not

};
std::ostream& operator<<(std::ostream& os, const halfPlane& hp);


//collections of halfPlanes
class polytopes{
public:
    std::vector<halfPlane> mPlanes;
    //constructor
    polytopes();
    //sort by normal
    void sortPolytopes();
    //collinear check
    static bool isCollinear(halfPlane& hp1, halfPlane& hp2);
    //method for tracking of included half-planes
    void checkIncl(std::vector<halfPlane>& ch);
    //boundary box
    void boundaryBox();
};
bool simCoefficient(halfPlane& hp1, halfPlane& hp2);

#endif //NTERSECTION_OF_HALFPLANES_WITH_THE_BOX__HALFPLANE_H

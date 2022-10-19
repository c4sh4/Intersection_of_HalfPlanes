//STL
#include <iostream>
//myIncludes
#include "interAlg.h"

int main() {
    int size = 0;
    polytopes Pl;
    Pl.boundaryBox();
    std::cin >> size;
    for(int i = 0; i < size; ++i){
        double x1, y1, x2, y2, x0, y0;
        //halfPlane Hp;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x0 >> y0;
        halfPlane Hp(Vec {x1,y1}, Vec {x2,y2}, Vec {x0, y0});
        Pl.mPlanes.emplace_back(Hp);
        std::cin.clear();
    }
    Pl.sortPolytopes();
    interAlg test;
    test.getIntersection(Pl);
    test.getVertexes();
    for (auto vert : test.vertex){
        std::cout << "Vertex: " << vert.x << ", " << vert.y << std::endl;
    }
    return 0;
}

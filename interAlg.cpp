#include "interAlg.h"
//STL

//
interAlg::interAlg(): deq(), vertex() {}
//
void interAlg::getIntersection(polytopes& pt) {
    for (auto hp : pt.mPlanes) {
        while (deq.size() > 1 && !checkin(deq.at(deq.size()-2), deq.back(), hp)) {
            deq.pop_back();
        }
        while (deq.size() > 1 && !checkin(deq.at(1), deq.front(), hp)) {
            deq.pop_front();
        }
        deq.emplace_back(hp);
    }
    while (deq.size() > 2 && !checkin(deq.front(), deq.at(1), deq.back())) {
        deq.pop_back();
    }
    while (deq.size() > 2 && !checkin(deq.back(), deq.at(deq.size() - 2), deq.front())) {
        deq.pop_front();
    }
    if (deq.size() <= 2) {
        std::cout << "Set is empty" << std::endl;
    }
}
//
Vec interAlg::vert(halfPlane &hp1, halfPlane &hp2) {
    double x, y;
    x = (-hp1.C * hp2.B + hp2.C * hp1.B)/(hp1.A * hp2.B - hp2.A * hp1.B);
    y = (-hp1.A * hp2.C + hp2.A * hp1.C)/(hp1.A * hp2.B - hp2.A * hp1.B);
    Vec apex(x,y);
    return apex;
}
//
bool interAlg::checkin(halfPlane& hp1, halfPlane& hp2, halfPlane& plane) {
    Vec vector = vert(hp1, hp2);
    return plane.pointStatus(vector) >= 0;
}
//
void interAlg::getVertexes() {
    int i = 0;
    do {
        vertex.emplace_back(vert(deq.at(i), deq.at(i+1)));
        ++i;
    } while (i < deq.size()-1);
    vertex.emplace_back(vert(deq.front(), deq.back()));
}
//
std::ostream& operator<<(std::ostream& os, const interAlg& alg) {
    os << "" << "" << "" << std::endl;
    return os;
}
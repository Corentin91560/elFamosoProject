//
// Created by Sandrine Patin on 22/01/2021.
//

#ifndef TEST_POINT_H
#define TEST_POINT_H


#include <string>

class Point {
private :
    int posx {};
    int posy {};

public:
    Point(int x, int y);

    std::string getcontent();

};


#endif //TEST_POINT_H

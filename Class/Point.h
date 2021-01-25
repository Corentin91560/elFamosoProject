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

    int getposX();
    int getposY();

    std::string getcontent();
};


#endif //ELFAMOSOPROJECT_POINT_H

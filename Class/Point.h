//
// Created by Sandrine Patin on 22/01/2021.
//

#ifndef TEST_POINT_H
#define TEST_POINT_H


#include <string>

class Point {
private :
    float posx {};
    float posy {};

public:
    Point(float x, float y);

    Point();

    void setPosx(float posx);

    void setPosy(float posy);

    float getposX();
    float getposY();

    std::string getcontent();


};


#endif //ELFAMOSOPROJECT_POINT_H

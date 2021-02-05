//
// Created by Sandrine Patin on 22/01/2021.
//

#include "Point.h"

Point::Point(float x, float y) {
    Point::posx = x;
    Point::posy = y;
}

Point::Point() {}

float Point::getposX(){
    return posx;
}

float Point::getposY(){
    return posy;
}

void Point::setPosx(float posx) {
    Point::posx = posx;
}

void Point::setPosy(float posy) {
    Point::posy = posy;
}

std::string Point::getcontent(){
    std::string content;
    content = "("
            + std::to_string(posx)
            + ","
            + std::to_string(posy)
            + ")";
    return content;
}
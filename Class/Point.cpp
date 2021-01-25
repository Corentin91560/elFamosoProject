//
// Created by Sandrine Patin on 22/01/2021.
//

#include "Point.h"

Point::Point(int x, int y) {
    Point::posx = x;
    Point::posy = y;
}

std::string Point::getcontent(){
    std::string content;
    content+="(";
    content+=std::to_string(posx);
    content+=",";
    content+=std::to_string(posy);
    content+=")";
    return content;
}

int Point::getposX(){
    return posx;
}

int Point::getposY(){
    return posy;
}

//
// Created by corentin delage on 13/01/2021.
//

#include "Circle.h"

Circle::~Circle() {

}

void Circle::setRadius(float radius) {
    Circle::radius = radius;
}

void Circle::setPosx(float posx) {
    Circle::posx = posx;
}

void Circle::setPosy(float posy) {
    Circle::posy = posy;
}

void Circle::setFill(const std::string &fill) {
    Circle::fill = fill;
}

Circle::Circle() {}

std::string Circle::getContent() {
    std::string content;
        +" Cercle de raduis : "
        +std::to_string(radius)
        +" , et son centre est en x : "
        +std::to_string(posx)
        +" et en y : "
        +std::to_string(posy);
    return content;
}

std::string Circle::getSVGContent() {
    std::string content;
    content="<circle cx=\""
            +std::to_string(posx)
            +"\" cy=\""
            +std::to_string(posy)
            +"\" r=\""
            +std::to_string(radius)
            +"\" fill=\""
            +fill
            +"\" />\n";
    return content;
}

std::string Circle::getJsonContent() {
    std::string content;
    content="{\"type\":\"cercle\",\"radius\":"+std::to_string(radius)+",\"posx\":"+std::to_string(posx)+",\"posy\":"+std::to_string(posy)+",\"fill\":\""+fill+"\"},";
    return content;
}

void Circle::extendShape(float coef) {
    Circle::radius = radius * coef;
}

void Circle::reduceShape(float coef) {
    Circle::radius = radius / coef;
}

void Circle::moveShapeX(float coef) {
    Circle::posx = posx + coef;
}

void Circle::moveShapeY(float coef) {
    Circle::posy = posy + coef;
}

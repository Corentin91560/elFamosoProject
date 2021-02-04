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

std::string Circle::getcontent() {
    std::string content;
    content+=" Circle de raduis : ";
    content+=std::to_string(radius);
    content+=" , et son centre est en x : ";
    content+=std::to_string(posx);
    content+=" et en y : ";
    content+=std::to_string(posy);
    return content;
}

std::string Circle::getsvgcontent() {
    std::string content;
    content+="<circle cx=\"";
    content+=std::to_string(posx);
    content+="\" cy=\"";
    content+=std::to_string(posy);
    content+="\" r=\"";
    content+=std::to_string(radius);
    content+="\" fill=\"";
    content+=fill;
    content+="\" />\n";
    return content;
}

std::string Circle::getjsoncontent() {
    std::string content;
    content+="{\"type\":\"cercle\",\"radius\":"+std::to_string(radius)+",\"posx\":"+std::to_string(posx)+",\"posy\":"+std::to_string(posy)+",\"fill\":\""+fill+"\"},";
    return content;
}

void Circle::agrandirforme(float coef) {
    Circle::radius = radius * coef;
}

void Circle::reduireforme(float coef) {
    Circle::radius = radius / coef;
}

void Circle::movexforme(float coef) {
    Circle::posx = posx + coef;
}

void Circle::moveyforme(float coef) {
    Circle::posy = posy + coef;
}

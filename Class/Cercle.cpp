//
// Created by corentin delage on 13/01/2021.
//

#include "Cercle.h"

Cercle::~Cercle() {

}

void Cercle::setRadius(float radius) {
    Cercle::radius = radius;
}

void Cercle::setPosx(float posx) {
    Cercle::posx = posx;
}

void Cercle::setPosy(float posy) {
    Cercle::posy = posy;
}

void Cercle::setFill(const std::string &fill) {
    Cercle::fill = fill;
}

Cercle::Cercle() {}

std::string Cercle::getcontent() {
    std::string content;
        +" Cercle de raduis : "
        +std::to_string(radius)
        +" , et son centre est en x : "
        +std::to_string(posx)
        +" et en y : "
        +std::to_string(posy);
    return content;
}

std::string Cercle::getsvgcontent() {
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

std::string Cercle::getjsoncontent() {
    std::string content;
    content="{\"type\":\"cercle\",\"radius\":"+std::to_string(radius)+",\"posx\":"+std::to_string(posx)+",\"posy\":"+std::to_string(posy)+",\"fill\":\""+fill+"\"},";
    return content;
}

void Cercle::agrandirforme(float coef) {
    Cercle::radius = radius*coef;
}

void Cercle::reduireforme(float coef) {
    Cercle::radius = radius/coef;
}

void Cercle::movexforme(float coef) {
    Cercle::posx = posx+coef;
}

void Cercle::moveyforme(float coef) {
    Cercle::posy = posy+coef;
}

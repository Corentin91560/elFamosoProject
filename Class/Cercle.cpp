//
// Created by corentin delage on 13/01/2021.
//

#include "Cercle.h"

Cercle::Cercle(int radius) : radius(radius) {}

Cercle::~Cercle() {

}

void Cercle::setRadius(int radius) {
    Cercle::radius = radius;
}

void Cercle::setPosx(int posx) {
    Cercle::posx = posx;
}

void Cercle::setPosy(int posy) {
    Cercle::posy = posy;
}

void Cercle::setFill(const std::string &fill) {
    Cercle::fill = fill;
}

Cercle::Cercle() {}

int Cercle::getRadius() const {
    return radius;
}

std::string Cercle::getcontent() {
    std::string content;
    content+=" Cercle de raduis : ";
    content+=std::to_string(radius);
    content+=" , et son centre est en x : ";
    content+=std::to_string(posx);
    content+=" et en y : ";
    content+=std::to_string(posy);
    return content;
}

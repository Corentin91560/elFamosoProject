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
    content+=" Cercle de raduis : ";
    content+=std::to_string(radius);
    content+=" , et son centre est en x : ";
    content+=std::to_string(posx);
    content+=" et en y : ";
    content+=std::to_string(posy);
    return content;
}

std::string Cercle::getsvgcontent() {
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

std::string Cercle::getjsoncontent() {
    std::string content;
    content+="{\"type\":\"cercle\",\"radius\":"+std::to_string(radius)+",\"posx\":"+std::to_string(posx)+",\"posy\":"+std::to_string(posy)+",\"fill\":\""+fill+"\"},";
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

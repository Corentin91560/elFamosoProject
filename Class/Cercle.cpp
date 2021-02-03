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
    content+=" Cercle de radius : ";
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
    content+="\"cercle\":{"
             "\n\"radius\":"+std::to_string(radius)+",\n\"posx\":"+std::to_string(posx)+",\n\"posy\":"+std::to_string(posy)+",\n\"fill\":"+fill+"}";
    return content;
}

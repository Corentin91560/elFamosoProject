//
// Created by Sandrine Patin on 22/01/2021.
//

#include "Polygone.h"

Polygone::Polygone() {}

Polygone::~Polygone() {

}

void Polygone::setPosx(int posx) {
    Polygone::posx = posx;
}

void Polygone::setPosy(int posy) {
    Polygone::posy = posy;
}

void Polygone::setFill(const std::string &fill) {
    Polygone::fill = fill;
}

void Polygone::setListePoints(std::vector<Point*> liste) {
    Polygone::listePoints = liste;
}

std::string Polygone::getcontent(){
    std::string content;
    content+="Polygone avec ";
    content+=std::to_string(listePoints.size());
    content+=" cotés";
    return content;
}

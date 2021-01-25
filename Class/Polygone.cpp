//
// Created by Sandrine Patin on 22/01/2021.
//

#include "Polygone.h"

Polygone::Polygone() {}

Polygone::~Polygone() {}

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

std::string Polygone::getsvgcontent() {
    std::string content;
    std::string listePointsSvg;

    int i;
    for(i = 0; i < listePoints.size(); i++){
        Point* point = Polygone::listePoints.at(i);
        if(i != 0){
            listePointsSvg += " ";
        }
        listePointsSvg += std::to_string(point->getposX());
        listePointsSvg += ",";
        listePointsSvg += std::to_string(point->getposY());
    }

    content+="<polyline points=\"";
    content+=listePointsSvg;
    content+="\" fill=\"";
    content+=fill;
    content+="\" />\n";
    return content;
}

std::string Polygone::getjsoncontent() {
    std::string content;
    //content+="\"cercle\":{"
    //         "\n\"radius\":"+std::to_string(radius)+",\n\"posx\":"+std::to_string(posx)+",\n\"posy\":"+std::to_string(posy)+",\n\"fill\":"+fill+"}";
    return content;
}
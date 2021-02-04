//
// Created by Sandrine Patin on 22/01/2021.
//

#include "Polygone.h"

Polygone::Polygone() {}

Polygone::~Polygone() {}

void Polygone::setPosx(float posx) {
    Polygone::posx = posx;
}

void Polygone::setPosy(float posy) {
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
    content+="Polygone avec "
            +std::to_string(listePoints.size())
            +" cotés";
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

    content="<polyline points=\""
            +listePointsSvg
            +"\" fill=\""
            +fill
            +"\" />\n";
    return content;
}

std::string Polygone::getjsoncontent() {
    std::string content;
    std::string listePointsSvg;

    int i;
    for(i = 0; i < listePoints.size(); i++){
        Point* point = Polygone::listePoints.at(i);
        if(i != 0){
            listePointsSvg += " ";
        }
        listePointsSvg += std::to_string(point->getposX());
        listePointsSvg += ";";
        listePointsSvg += std::to_string(point->getposY());
    }

    content+="{\"type\":\"polygone\",\"point\":\""+listePointsSvg+"\",\"fill\":\""+fill+"\"},";
    return content;
}

void Polygone::agrandirforme(float coef) {
    int i;
    for(i = 0; i < listePoints.size(); i++){
        Point* point = Polygone::listePoints.at(i);
        point->setPosx(point->getposX()*coef);
        point->setPosy(point->getposY()*coef);
    }
}

void Polygone::reduireforme(float coef) {
    int i;
    for(i = 0; i < listePoints.size(); i++){
        Point* point = Polygone::listePoints.at(i);
        point->setPosx(point->getposX()*coef);
        point->setPosy(point->getposY()*coef);
    }
}

void Polygone::movexforme(float coef) {
    int i;
    for(i = 0; i < listePoints.size(); i++){
        Point* point = Polygone::listePoints.at(i);
        point->setPosx(point->getposX()+coef);
    }
}

void Polygone::moveyforme(float coef) {
    int i;
    for(i = 0; i < listePoints.size(); i++){
        Point* point = Polygone::listePoints.at(i);
        point->setPosy(point->getposY()+coef);
    }
}

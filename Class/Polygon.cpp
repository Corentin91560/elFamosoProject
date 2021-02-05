//
// Created by Sandrine Patin on 22/01/2021.
//

#include "Polygon.h"

Polygon::Polygon() {}

void Polygon::setPosx(float posx) {
    Polygon::posx = posx;
}

void Polygon::setPosy(float posy) {
    Polygon::posy = posy;
}

void Polygon::setListPoints(std::vector<Point*> liste) {
    Polygon::listPoints = liste;
}

void Polygon::setFill(const std::string &fill) {
    Polygon::fill = fill;
}

std::string Polygon::getContent(){
    std::string content;
    content = " Polygon avec "
            + std::to_string(listPoints.size())
            + " cotés";
    return content;
}

std::string Polygon::getSVGContent() {
    std::string content;
    std::string listePointsSvg;

    int i;
    for(i = 0; i < listPoints.size(); i++){
        Point* point = Polygon::listPoints.at(i);
        if(i != 0){
            listePointsSvg += " ";
        }
        listePointsSvg += std::to_string(point->getposX());
        listePointsSvg += ",";
        listePointsSvg += std::to_string(point->getposY());
    }

    content = "<polyline points=\""
            + listePointsSvg
            + "\" fill=\""
            + fill
            + "\" />\n";
    return content;
}

std::string Polygon::getJsonContent() {
    std::string content;
    std::string listePointsSvg;

    int i;
    for(i = 0; i < listPoints.size(); i++){
        Point* point = Polygon::listPoints.at(i);
        if(i != 0){
            listePointsSvg += " ";
        }
        listePointsSvg += std::to_string(point->getposX());
        listePointsSvg += ";";
        listePointsSvg += std::to_string(point->getposY());
    }

    content = "{\"type\":\"polygone\",\"point\":\""
            + listePointsSvg
            + "\",\"fill\":\""
            + fill
            + "\"},";
    return content;
}

void Polygon::extendShape(float coef) {
    int i;
    for(i = 0; i < listPoints.size(); i++){
        Point* point = Polygon::listPoints.at(i);
        point->setPosx(point->getposX()*coef);
        point->setPosy(point->getposY()*coef);
    }
}

void Polygon::reduceShape(float coef) {
    int i;
    for(i = 0; i < listPoints.size(); i++){
        Point* point = Polygon::listPoints.at(i);
        point->setPosx(point->getposX()*coef);
        point->setPosy(point->getposY()*coef);
    }
}

void Polygon::moveShapeX(float coef) {
    int i;
    for(i = 0; i < listPoints.size(); i++){
        Point* point = Polygon::listPoints.at(i);
        point->setPosx(point->getposX()+coef);
    }
}

void Polygon::moveShapeY(float coef) {
    int i;
    for(i = 0; i < listPoints.size(); i++){
        Point* point = Polygon::listPoints.at(i);
        point->setPosy(point->getposY()+coef);
    }
}

//
// Created by corentin delage on 03/02/2021.
//

#include "Segment.h"

std::string Segment::getContent() {
    std::string content;
    content="Ligne 1er point x :"
            + std::to_string(point1.getposX())
            + " y :"
            + std::to_string(point1.getposY())
            + " , 2eme point x :"
            + std::to_string(point2.getposX())
            + " y :"
            + std::to_string(point2.getposY())
            + " , de couleur :"
            + fill;
    return content;
}

std::string Segment::getSVGContent() {
    std::string content;
    content ="<line x1=\""
            + std::to_string(point1.getposX())
            + "\" y1=\""
            + std::to_string(point1.getposY())
            + "\" x2=\""
            + std::to_string(point2.getposX())
            + "\" y2=\""
            + std::to_string(point2.getposY())
            + "\" stroke=\""
            + fill;
            + "\" />\n";
    return content;
}

std::string Segment::getJsonContent() {
    std::string content;
    content+="{\"type\":\"line\",\"x1\":"+std::to_string(point1.getposX())+",\"y1\":"+std::to_string(point1.getposY())+",\"x2\":"+std::to_string(point2.getposX())+",\"y2\":"+std::to_string(point2.getposY())+",\"fill\":\""+fill+"\"},";
    return content;
}


Segment::Segment(const Point &point1, const Point &point2) : point1(point1), point2(point2) {}

Segment::~Segment() {

}

void Segment::setPoint1(const Point &point1) {
    Segment::point1 = point1;
}

void Segment::setPoint2(const Point &point2) {
    Segment::point2 = point2;
}

void Segment::setPosx(float posx) {

}

void Segment::setPosy(float posy) {

}

void Segment::setFill(const std::string &fill) {
    Segment::fill = fill;
}

Segment::Segment() {}

void Segment::extendShape(float coef) {

    point1.setPosx(point1.getposX()*coef);
    point1.setPosy(point1.getposY()*coef);
    point2.setPosx(point2.getposX()*coef);
    point2.setPosy(point2.getposY()*coef);
}

void Segment::reduceShape(float coef) {
    point1.setPosx(point1.getposX()/coef);
    point1.setPosy(point1.getposY()/coef);
    point2.setPosx(point2.getposX()/coef);
    point2.setPosy(point2.getposY()/coef);
}

void Segment::moveShapeX(float coef) {
    point1.setPosx(point1.getposX()+coef);
    point2.setPosx(point2.getposX()+coef);
}

void Segment::moveShapeY(float coef) {
    point1.setPosy(point1.getposY()+coef);
    point2.setPosy(point2.getposY()+coef);
}

//
// Created by corentin delage on 03/02/2021.
//

#include "Segment.h"

std::string Segment::getcontent() {
    std::string content;
    content+="Ligne 1er point x :";
    content+=std::to_string(point1.getposX());
    content+=" y :";
    content+=std::to_string(point1.getposY());
    content+=" , 2eme point x :";
    content+=std::to_string(point2.getposX());
    content+=" y :";
    content+=std::to_string(point2.getposY());
    content+=" , de couleur :";
    content+=fill;
    return content;
}

std::string Segment::getsvgcontent() {
    std::string content;
    content+="<line x1=\"";
    content+=std::to_string(point1.getposX());
    content+="\" y1=\"";
    content+=std::to_string(point1.getposY());
    content+="\" x2=\"";
    content+=std::to_string(point2.getposX());
    content+="\" y2=\"";
    content+=std::to_string(point2.getposY());
    content+="\" stroke=\"";
    content+=fill;
    content+="\" />\n";
    return content;
}

std::string Segment::getjsoncontent() {
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

void Segment::setPosx(int posx) {

}

void Segment::setPosy(int posy) {

}

void Segment::setFill(const std::string &fill) {
    Segment::fill = fill;
}

Segment::Segment() {}

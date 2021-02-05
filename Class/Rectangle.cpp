//
// Created by corentin delage on 12/01/2021.
//

#include "Rectangle.h"

Rectangle::Rectangle() {}


Rectangle::~Rectangle() {

}

void Rectangle::setWidth(float width) {
    Rectangle::width = width;
}

void Rectangle::setHeight(float height) {
    Rectangle::height = height;
}

void Rectangle::setPosx(float posx) {
    Rectangle::posx = posx;
}

void Rectangle::setPosy(float posy) {
    Rectangle::posy = posy;
}

void Rectangle::setFill(const std::string &fill) {
    Rectangle::fill = fill;
}

std::string Rectangle::getContent() {
    std::string content;
    content = "Rectangle de largueur :"
            + std::to_string(width)
            + " , de hauteur :"
            + std::to_string(height)
            + " , de couleur :"
            + fill
            + " , de position en x :"
            + std::to_string(posx)
            + " , de position en y :"
            + std::to_string(posy);
    return content;
}

std::string Rectangle::getSVGContent() {
    std::string content;
    content = "<rect x=\""
            + std::to_string(posx)
            + "\" y=\""
            + std::to_string(posy)
            + "\" width=\""
            + std::to_string(width)
            + "\" height=\""
            + std::to_string(height)
            + "\" fill=\""
            + fill
            + "\" />\n";
    return content;
}

std::string Rectangle::getJsonContent() {
    std::string content;
    content += "{\"type\":\"rectangle\",\"width\":" + std::to_string(width) + ",\"height\":" + std::to_string(height) + ",\"posx\":" + std::to_string(posx) + ",\"posy\":" + std::to_string(posx) + ",\"fill\":\"" + fill + "\"},";
    return content;
}

void Rectangle::extendShape(float coef) {
    Rectangle::width = width*coef;
    Rectangle::height = height*coef;

}

void Rectangle::reduceShape(float coef) {
    Rectangle::width = width/coef;
    Rectangle::height = height/coef;
}

void Rectangle::moveShapeX(float coef) {
    Rectangle::posx = posx+coef;
}

void Rectangle::moveShapeY(float coef) {
    Rectangle::posy = posy+coef;
}



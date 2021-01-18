//
// Created by corentin delage on 12/01/2021.
//

#include "Rectangle.h"

Rectangle::Rectangle() {}

Rectangle::Rectangle(int width, int height) {
    this->width=width;
    this->height=height;
}

Rectangle::~Rectangle() {

}

void Rectangle::setWidth(int width) {
    Rectangle::width = width;
}

void Rectangle::setHeight(int height) {
    Rectangle::height = height;
}

void Rectangle::setPosx(int posx) {
    Rectangle::posx = posx;
}

void Rectangle::setPosy(int posy) {
    Rectangle::posy = posy;
}

void Rectangle::setFill(const std::string &fill) {
    Rectangle::fill = fill;
}

std::string Rectangle::getcontent() {
    std::string content;
    content+="Rectangle de largueur :";
    content+=std::to_string(width);
    content+=" , de hauteur :";
    content+=std::to_string(height);
    content+=" , de couleur :";
    content+=fill;
    content+=" , de position en x :";
    content+=std::to_string(posx);
    content+=" , de position en y :";
    content+=std::to_string(posy);
    return content;
}

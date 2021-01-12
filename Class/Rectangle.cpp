//
// Created by corentin delage on 12/01/2021.
//

#include "Rectangle.h"

Rectangle::Rectangle(double posx, double posy, int width, int height, const std::string &fill){
    this->posx = posx;
    this->posy = posy;
    this->width = width;
    this->height = height;
    this->fill = fill;
}

double Rectangle::getPosx() const {
    return posx;
}

double Rectangle::getPosy() const {
    return posy;
}

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

const std::string &Rectangle::getFill() const {
    return fill;
}

Rectangle::Rectangle() {}

Rectangle::Rectangle(Forme forme) {

}

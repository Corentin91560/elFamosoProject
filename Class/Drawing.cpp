//
// Created by corentin delage on 12/01/2021.
//

#include "Drawing.h"

Drawing::Drawing(const std::vector<Shape *> &formes, float height, float width) : listShapes(formes), height(height),
                                                                                  width(width) {}
Drawing::Drawing(const std::vector<Shape *> &shapes) : listShapes(shapes) {}

float Drawing::getHeight() const {
    return height;
}

float Drawing::getWidth() const {
    return width;
}

void Drawing::setHeight(float height) {
    Drawing::height = height;
}

void Drawing::setWidth(float width) {
    Drawing::width = width;
}
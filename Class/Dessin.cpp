//
// Created by corentin delage on 12/01/2021.
//

#include "Dessin.h"

Dessin::Dessin(const std::vector<Shape *> &formes, float height, float width) : formes(formes), height(height),
                                                                                width(width) {}

float Dessin::getHeight() const {
    return height;
}

float Dessin::getWidth() const {
    return width;
}

void Dessin::setHeight(float height) {
    Dessin::height = height;
}

void Dessin::setWidth(float width) {
    Dessin::width = width;
}

Dessin::Dessin(const std::vector<Shape *> &formes) : formes(formes) {}



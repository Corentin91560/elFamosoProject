//
// Created by corentin delage on 12/01/2021.
//

#include "Dessin.h"

Dessin::Dessin(const std::vector<Forme *> &formes, double height, double width) : formes(formes), height(height),
                                                                                  width(width) {}

double Dessin::getHeight() const {
    return height;
}

double Dessin::getWidth() const {
    return width;
}

void Dessin::setHeight(double height) {
    Dessin::height = height;
}

void Dessin::setWidth(double width) {
    Dessin::width = width;
}

Dessin::Dessin(const std::vector<Forme *> &formes) : formes(formes) {}



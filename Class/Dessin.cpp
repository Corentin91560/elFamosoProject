//
// Created by corentin delage on 12/01/2021.
//

#include "Dessin.h"

Dessin::Dessin(const std::vector<Forme *> &formes, int height, int width) : formes(formes), height(height),
                                                                                  width(width) {}

int Dessin::getHeight() const {
    return height;
}

int Dessin::getWidth() const {
    return width;
}

void Dessin::setHeight(int height) {
    Dessin::height = height;
}

void Dessin::setWidth(int width) {
    Dessin::width = width;
}

Dessin::Dessin(const std::vector<Forme *> &formes) : formes(formes) {}



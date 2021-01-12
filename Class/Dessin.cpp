//
// Created by corentin delage on 12/01/2021.
//

#include "Dessin.h"

Dessin::Dessin(double width, double height, const std::vector<Forme> &formes) {
    this->width=width;
    this->height=height;
    this->formes=formes;
}
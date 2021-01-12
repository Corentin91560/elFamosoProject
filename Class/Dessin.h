//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_DESSIN_H
#define ELFAMOSOPROJECT_DESSIN_H


#include <vector>
#include "Forme.h"

class Dessin {
private:

public:
    Dessin(double width, double height, const std::vector<Forme> &formes);

    std::vector<Forme> formes;
    double height;
    double width;

};


#endif //ELFAMOSOPROJECT_DESSIN_H

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
    double getHeight() const;

    double getWidth() const;

    Dessin(const std::vector<Forme *> &formes, double height, double width);

    std::vector<Forme*> formes;
    double height;
    double width;

    void setHeight(double height);

    void setWidth(double width);

    Dessin(const std::vector<Forme *> &formes);

};


#endif //ELFAMOSOPROJECT_DESSIN_H

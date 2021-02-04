//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_DESSIN_H
#define ELFAMOSOPROJECT_DESSIN_H


#include <vector>
#include "Shape.h"

class Dessin {
private:

public:
    float getHeight() const;

    float getWidth() const;

    Dessin(const std::vector<Shape *> &formes, float height, float width);

    std::vector<Shape*> formes;
    float height;
    float width;

    void setHeight(float height);

    void setWidth(float width);

    Dessin(const std::vector<Shape *> &formes);

};


#endif //ELFAMOSOPROJECT_DESSIN_H

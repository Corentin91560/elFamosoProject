//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_DESSIN_H
#define ELFAMOSOPROJECT_DESSIN_H


#include <vector>
#include "Shape.h"

class Drawing {
private:

public:
    float getHeight() const;

    float getWidth() const;

    Drawing(const std::vector<Shape *> &formes, float height, float width);

    std::vector<Shape*> listShapes;
    float height;
    float width;

    void setHeight(float height);

    void setWidth(float width);

    Drawing(const std::vector<Shape *> &shapes);

};


#endif //ELFAMOSOPROJECT_DESSIN_H

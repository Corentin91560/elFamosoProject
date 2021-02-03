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
    int getHeight() const;

    int getWidth() const;

    Dessin(const std::vector<Forme *> &formes, int height, int width);

    std::vector<Forme*> formes;
    int height;
    int width;

    void setHeight(int height);

    void setWidth(int width);

    Dessin(const std::vector<Forme *> &formes);

};


#endif //ELFAMOSOPROJECT_DESSIN_H

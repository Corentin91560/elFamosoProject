//
// Created by Sandrine Patin on 22/01/2021.
//

#ifndef ELFAMOSOPROJECT_POLYGONE_H
#define ELFAMOSOPROJECT_POLYGONE_H


#include <vector>
#include "Point.h"
#include "Shape.h"

class Polygon : public Shape{
public:
    std::vector<Point*> listPoints;//TODO faire le choix du nombre de points : taille tot = taille choisie + 1 pour le retour au pt de départ

    Polygon();

    virtual ~Polygon();

    void setPosx(float posx) override;

    void setPosy(float posy) override;

    void setFill(const std::string &fill) override;

    void setListPoints(std::vector<Point*> liste);

    std::string getContent() override;
    std::string getSVGContent() override;
    std::string getJsonContent() override;

    void extendShape(float coef) override;

    void reduceShape(float coef) override;

    void moveShapeX(float coef) override;

    void moveShapeY(float coef) override;

};


#endif //ELFAMOSOPROJECT_POLYGONE_H

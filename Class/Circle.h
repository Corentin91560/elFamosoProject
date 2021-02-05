//
// Created by corentin delage on 13/01/2021.
//

#ifndef ELFAMOSOPROJECT_CERCLE_H
#define ELFAMOSOPROJECT_CERCLE_H
#include "Shape.h"

class Circle : public Shape{
public:
    float radius;

    Circle();

    void setRadius(float radius);

    void setPosx(float posx) override;
    void setPosy(float posy) override;
    void setFill(const std::string &fill) override;
    std::string getContent() override;
    std::string getSVGContent() override;
    std::string getJsonContent() override;
    void extendShape(float coef) override;
    void reduceShape(float coef) override;
    void moveShapeX(float coef) override;
    void moveShapeY(float coef) override;

};


#endif //ELFAMOSOPROJECT_CERCLE_H

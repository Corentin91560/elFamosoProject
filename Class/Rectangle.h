//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_RECTANGLE_H
#define ELFAMOSOPROJECT_RECTANGLE_H

#include <string>
#include "Shape.h"



class Rectangle : public Shape{
public:

    float width;
    float height;

    Rectangle();


    void setWidth(float width);

    void setHeight(float height);

    virtual ~Rectangle();

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


#endif //ELFAMOSOPROJECT_RECTANGLE_H

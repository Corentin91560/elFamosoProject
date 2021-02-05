//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_FORME_H
#define ELFAMOSOPROJECT_FORME_H

#include <string>

class Shape {
protected:
    float posx;
    float posy;
    std::string fill;

public:
    virtual ~Shape();

    virtual void setPosx(float posx) = 0;

    virtual void setPosy(float posy) = 0;

    virtual void setFill(const std::string &fill) = 0;
    virtual std::string getContent()=0;
    virtual std::string getSVGContent()=0;
    virtual std::string getJsonContent()=0;
    virtual void extendShape(float coef)=0;
    virtual void reduceShape(float coef)=0;
    virtual void moveShapeX(float coef)=0;
    virtual void moveShapeY(float coef)=0;
};

#endif //ELFAMOSOPROJECT_FORME_H

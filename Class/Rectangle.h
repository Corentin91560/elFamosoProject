//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_RECTANGLE_H
#define ELFAMOSOPROJECT_RECTANGLE_H

#include <string>
#include "Forme.h"



class Rectangle : public Forme{
private:
    double posx{};
    double posy{};
    int width{};
    int height{};
    std::string fill;

public:
    Rectangle();

    Rectangle(double posx, double posy, int width, int height, const std::string &fill);

    double getPosx() const;

    double getPosy() const;

    int getWidth() const;

    int getHeight() const;

    const std::string &getFill() const;

    Rectangle(Forme forme);
};


#endif //ELFAMOSOPROJECT_RECTANGLE_H

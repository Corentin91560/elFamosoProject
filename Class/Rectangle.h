//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_RECTANGLE_H
#define ELFAMOSOPROJECT_RECTANGLE_H

#include <string>
#include "Forme.h"



class Rectangle : public Forme{
private:
    int width{};
    int height{};

public:

    Rectangle();

    Rectangle( int width, int height);

    void setWidth(int width);

    void setHeight(int height);

    virtual ~Rectangle();

    void setPosx(int posx) override;

    void setPosy(int posy) override;

    void setFill(const std::string &fill) override;

    std::string getcontent() override;

    std::string getsvgcontent() override;

    std::string getjsoncontent() override;

};


#endif //ELFAMOSOPROJECT_RECTANGLE_H

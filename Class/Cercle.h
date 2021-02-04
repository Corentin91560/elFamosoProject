//
// Created by corentin delage on 13/01/2021.
//

#ifndef ELFAMOSOPROJECT_CERCLE_H
#define ELFAMOSOPROJECT_CERCLE_H


#include "Forme.h"

class Cercle : public Forme{
public:
    float radius;

    Cercle();

    virtual ~Cercle();

    void setPosx(float posx) override;

    void setPosy(float posy) override;

    void setFill(const std::string &fill) override;

    void setRadius(float radius);

    std::string getcontent() override;
    std::string getsvgcontent() override;
    std::string getjsoncontent() override;

    void agrandirforme(float coef) override;

    void reduireforme(float coef) override;

    void movexforme(float coef) override;

    void moveyforme(float coef) override;

};


#endif //ELFAMOSOPROJECT_CERCLE_H

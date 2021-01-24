//
// Created by corentin delage on 13/01/2021.
//

#ifndef ELFAMOSOPROJECT_CERCLE_H
#define ELFAMOSOPROJECT_CERCLE_H


#include "Forme.h"

class Cercle : public Forme{
public:
    int radius;

    Cercle();

    Cercle(int radius);

    virtual ~Cercle();

    void setPosx(int posx) override;

    void setPosy(int posy) override;

    void setFill(const std::string &fill) override;

    void setRadius(int radius);

    int getRadius() const;

    std::string getcontent() override;
    std::string getsvgcontent() override;
    std::string getjsoncontent() override;


};


#endif //ELFAMOSOPROJECT_CERCLE_H

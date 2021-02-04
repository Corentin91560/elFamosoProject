//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_FORME_H
#define ELFAMOSOPROJECT_FORME_H

#include <string>

class Forme {
protected:
    float posx;
    float posy;
    std::string fill;

public:
    virtual ~Forme();

    virtual void setPosx(float posx) = 0;

    virtual void setPosy(float posy) = 0;

    virtual void setFill(const std::string &fill) = 0;
    virtual std::string getcontent()=0;
    virtual std::string getsvgcontent()=0;
    virtual std::string getjsoncontent()=0;
    virtual void agrandirforme(float coef)=0;
    virtual void reduireforme(float coef)=0;
    virtual void movexforme(float coef)=0;
    virtual void moveyforme(float coef)=0;

};

#endif //ELFAMOSOPROJECT_FORME_H

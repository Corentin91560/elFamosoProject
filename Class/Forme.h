//
// Created by corentin delage on 12/01/2021.
//

#ifndef ELFAMOSOPROJECT_FORME_H
#define ELFAMOSOPROJECT_FORME_H

#include <string>

class Forme {
protected:
    int posx;
    int posy;
    std::string fill;

public:
    virtual ~Forme();

    virtual void setPosx(int posx) = 0;

    virtual void setPosy(int posy) = 0;

    virtual void setFill(const std::string &fill) = 0;
    virtual std::string getcontent()=0;

};

#endif //ELFAMOSOPROJECT_FORME_H

//
// Created by Sandrine Patin on 22/01/2021.
//

#ifndef ELFAMOSOPROJECT_POLYGONE_H
#define ELFAMOSOPROJECT_POLYGONE_H


#include <vector>
#include "Point.h"
#include "Forme.h"

class Polygone : public Forme{
public:
    std::vector<Point*> listePoints;

    Polygone();

    virtual ~Polygone();

    void setPosx(int posx) override;

    void setPosy(int posy) override;

    void setFill(const std::string &fill) override;

    void setListePoints(std::vector<Point*> liste);

    std::string getcontent() override;
    std::string getsvgcontent() override;
    std::string getjsoncontent() override;

};


#endif //ELFAMOSOPROJECT_POLYGONE_H

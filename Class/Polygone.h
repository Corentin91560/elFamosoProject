//
// Created by Sandrine Patin on 22/01/2021.
//

#ifndef ELFAMOSOPROJECT_POLYGONE_H
#define ELFAMOSOPROJECT_POLYGONE_H


#include <vector>
#include "Point.h"
#include "Forme.h"

class Polygone : public Forme{
private:
    std::vector<Point*> listePoints;//TODO faire le choix du nombre de points : taille tot = taille choisie + 1 pour le retour au pt de départ
    //TODO faire le choix des coordonnées des points


public:
    Polygone();

    virtual ~Polygone();

    void setPosx(int posx) override;

    void setPosy(int posy) override;

    void setFill(const std::string &fill) override;

    void setListePoints(std::vector<Point*> liste);

    std::string getcontent() override;

};


#endif //TEST_POLYGONE_H

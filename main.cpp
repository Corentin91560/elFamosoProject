#include <iostream>
#include <list>
#include "Class/Rectangle.h"
#include "Class/Dessin.h"


void affichemenu(){
    std::cout << "MENU : \n" << std::endl;

    std::cout << "Créer un dessin : 1" << std::endl;
    std::cout << "Charger un dessin : 2" << std::endl;
    std::cout << "Fusionner 2 dessins : 3" << std::endl;
    std::cout << "Quitter : 9" << std::endl;
}

void affichemenuedition(){

    std::cout << "MENU EDITION DESSIN : \n" << std::endl;

    std::cout << "Rajouter une forme : 1" << std::endl;
    std::cout << "Sauvegarder le dessin : 2" << std::endl;
    std::cout << "Exporter en SVG : 3" << std::endl;
    std::cout << "Quitter sans sauvegarder : 9" << std::endl;

}

void addformemenu(){
    std::cout << "CHOIX DE FORME : \n" << std::endl;

    std::cout << "Rectangle 1" << std::endl;
    std::cout << "Cercle 2" << std::endl;
    std::cout << "Segment 3" << std::endl;
    std::cout << "Polygone 4" << std::endl;

}

void selectforme(){
    Rectangle rectangle = Rectangle(10,40,20,15,"pink");
    std::vector<Forme> formes;
    formes.push_back(rectangle);
    Dessin dessin = Dessin(150,200,formes);
    std::vector<Forme> forme = dessin.formes;
    Rectangle rect1 = forme[0]; //rectangle

    int selection = 0;
    bool selectable = false;
    while (!selectable){
        addformemenu();
        std::cin >> selection;
        switch (selection) {
            case 1:
                printf("%f",rectangle.getPosx());
                selectable = true;
                break;
            case 2:
                selectable = true;
//cercle
                break;
            case 3:
                selectable = true;
//segment
                break;
            case 4:
                selectable = true;
//polygone
                break;
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

void editionmenu(){
    int selection = 0;
    bool selectable = false;
    while (!selectable){
        affichemenuedition();
        std::cin >> selection;
        switch (selection) {
            case 1:
                selectable = true;
                selectforme();
                break;
            case 2:
                selectable = true;
                printf("ok 2");
                break;
            case 3:
                selectable = true;
                printf("ok 3");
                break;
            case 9:
                selectable = true;
                affichemenu();
                break;
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

void affichermenucreation(int* dimension){
    std::cout << "MENU CREATION DESSIN : \n" << std::endl;
    std::cout << "Hauteur :" << std::endl;
    std::cin >> dimension[0];
    std::cout << "Largeur :" << std::endl;
    std::cin >> dimension[1] ;
    std::cout << "Hauteur : " << dimension[0] << "Largeur : " << dimension[1] << std::endl;
}

void creationdessin(){
    int dimension[2];
    affichermenucreation(dimension);
    editionmenu();
}

void startprogram(){
    int selection = 0;
    bool selectable = false;
    while (!selectable){
        affichemenu();
        std::cin >> selection;
        switch (selection) {
            case 1:
                selectable = true;
                creationdessin();
                break;
            case 2:
                selectable = true;
                printf("ok 2");
                break;
            case 3:
                selectable = true;
                printf("ok 3");
                break;
            case 9:
                selectable = true;
                break;
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

int main() {
    std::cout << "SVG Creator\n" << std::endl;
    std::cout << "\n" << std::endl;
    startprogram();
    return 0;
}

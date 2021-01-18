#include <iostream>
#include <list>
#include "Class/Rectangle.h"
#include "Class/Dessin.h"
#include "Class/Cercle.h"


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
Rectangle createRectangle(){
    Rectangle rectangle;
    int height;
    int width;
    int posx;
    int posy;
    std::string fill;
    std::cout << "MENU CREATION RECTANGLE : \n" << std::endl;
    std::cout << "Hauteur :" << std::endl;
    std::cin >> height;
    std::cout << "Largeur :" << std::endl;
    std::cin >> width ;
    std::cout << "posx :" << std::endl;
    std::cin >> posx;
    std::cout << "posy :" << std::endl;
    std::cin >> posy ;
    std::cout << "fill :" << std::endl;
    std::cin >> fill;
    rectangle.setHeight(height);
    rectangle.setWidth(width);
    rectangle.setPosx(posx);
    rectangle.setPosy(posy);
    rectangle.setFill(fill);
    return rectangle;
}
Cercle createCercle(){
    Cercle cercle;
    int radius;
    int posx;
    int posy;
    std::string fill;
    std::cout << "MENU CREATION RECTANGLE : \n" << std::endl;
    std::cout << "Radius :" << std::endl;
    std::cin >> radius;
    std::cout << "posx :" << std::endl;
    std::cin >> posx;
    std::cout << "posy :" << std::endl;
    std::cin >> posy ;
    std::cout << "fill :" << std::endl;
    std::cin >> fill;
    cercle.setRadius(radius);
    cercle.setPosx(posx);
    cercle.setPosy(posy);
    cercle.setFill(fill);
    return cercle;
}
void describeDessin(Dessin &dessin){
    std::cout<<"Hauteur du dessin : "<<dessin.getHeight()<<"et Largueur : "<<dessin.getWidth()<<std::endl;
    printf("%lu",dessin.formes.size());
    for (int i = 0; i < dessin.formes.size(); ++i) {
        std::cout<<dessin.formes[i]->getcontent()<<std::endl;
    }
}

Dessin selectforme(Dessin dessin){

    printf("%lu",dessin.formes.size());

    int selection = 0;
    while (true){
        addformemenu();
        std::cin >> selection;
        switch (selection) {
            case 1:
                dessin.formes.push_back(new Rectangle(createRectangle()));
                break;
            case 2:
                dessin.formes.push_back(new Cercle(createCercle()));
//cercle
                break;
            case 3:

//segment
                break;
            case 4:

//polygone
                break;
            case 5:
                describeDessin(dessin);
                break;
            case 9:
                printf("%lu",dessin.formes.size());
                return dessin;
//polygone
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

void editionmenu(Dessin &dessin){
    printf("test %lu debut",dessin.formes.size());

    int selection = 0;
    bool selectable = false;
    while (!selectable){
        affichemenuedition();
        std::cin >> selection;
        switch (selection) {
            case 1:
                printf("test %lu end1",dessin.formes.size());
                dessin = Dessin(selectforme(dessin));
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

Dessin affichermenucreation(Dessin &dessin){
    int height;
    int width;
    std::cout << "MENU CREATION DESSIN : \n" << std::endl;
    std::cout << "Hauteur :" << std::endl;
    std::cin >> height;
    std::cout << "Largeur :" << std::endl;
    std::cin >> width ;
    dessin.setHeight(height);
    dessin.setWidth(width);
    std::cout << "Hauteur : " << height << "Largeur : " << width << std::endl;
    return dessin;
}

void creationdessin(){
    std::vector<Forme*> formes;
    Dessin dessin = Dessin(formes);
    affichermenucreation(dessin);
    editionmenu(dessin);
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

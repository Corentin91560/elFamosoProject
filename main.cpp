#include <iostream>
#include <list>
#include <vector>
#include "Class/Rectangle.h"
#include "Class/Dessin.h"
#include "Class/Cercle.h"
#include "Class/Polygone.h"

#include <fstream>
#include <sstream>
#include <map>


void exporttosvg(Dessin currentDessin);
void saveasjson(Dessin currentDessin);

//TODO : bloquer les erreurs d'entrées
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
// TODO quit the menu
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
    std::cout << "MENU CREATION CERCLE : \n" << std::endl;
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

Polygone createPolygone(){
    Polygone polygone;
    std::vector<Point*> listePoints;
    int nbPoints;
    std::string fill;
    std::cout << "MENU CREATION POLYGONE : \n" << std::endl;
    std::cout << "Nombre de points:" << std::endl;
    std::cin >> nbPoints;
    std::cout << "fill :" << std::endl;
    std::cin >> fill;
    polygone.setFill(fill);

    int i = 0;
    while (i < nbPoints){
        int x;
        int y;
        std::cout << "Coordonnées du point n°" << i+1 << std::endl;
        std::cout << "x :" << std::endl;
        std::cin >> x;
        std::cout << "y :" << std::endl;
        std::cin >> y;
        Point* point = new Point(x, y);
        listePoints.push_back(point);
        i++;
    }
    polygone.setListePoints(listePoints);
    return polygone;

}

void describeDessin(Dessin &dessin){
    std::cout<<"Hauteur du dessin : "<<dessin.getHeight()<<" et Largueur : "<<dessin.getWidth()<<std::endl;
    for (int i = 0; i < dessin.formes.size(); ++i) {
        std::cout<<dessin.formes[i]->getcontent()<<std::endl;
    }
}

Dessin selectforme(Dessin dessin){
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
                dessin.formes.push_back(new Polygone(createPolygone()));
//polygone
                break;
            case 5:
                describeDessin(dessin);
                break;
            case 9:
                return dessin;
//polygone
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

void editionmenu(Dessin &dessin){

    int selection = 0;
    bool selectable = false;
    while (!selectable){
        affichemenuedition();
        std::cin >> selection;
        switch (selection) {
            case 1:
                dessin = Dessin(selectforme(dessin));
                break;
            case 2:
                selectable = true;
                saveasjson(dessin);
                break;
            case 3:
                selectable = true;
                exporttosvg(dessin);
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

void exporttosvg(Dessin currentDessin) {
    std::string filename;
    std::cout<<"veuillez saisir le nom du fichier"<<std::endl;
    std::cin>>filename;
    std::ofstream outfile(filename+".svg");
    outfile << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
               "<svg width=\""<<currentDessin.width<<"\" height=\""<<currentDessin.height<<"\" xmlns=\"http://www.w3.org/2000/svg\">\n"
               "<rect fill=\"#fff\" stroke=\"#000\" x=\"0\" y=\"0\" width=\""<<currentDessin.width<<"\" height=\""<<currentDessin.height<<"\"/>\n"<<std::endl;

    for (int i = 0; i < currentDessin.formes.size(); ++i) {
        outfile<<currentDessin.formes[i]->getsvgcontent();
    }

    outfile<<"</svg>";
    //TODO app crash after out the svg
}

void saveasjson(Dessin dessin){
    std::string filename;
    std::cout<<"veuillez saisir le nom du fichier"<<std::endl;
    std::cin>>filename;
    std::ofstream outfile(filename+".json");
    outfile << "{"<<std::endl;

    for (int i = 0; i < dessin.formes.size(); ++i) {
        outfile<<dessin.formes[i]->getjsoncontent();
    }

    outfile<<"}";
    //TODO app crash after save
}

std::string getValue(const std::string& property){
    std::istringstream iss2(property);
    std::string mot;
    std::string res;
    int i = 0;
    while ( std::getline( iss2, mot, ':' ) )
    {
        if(i!=0){ res = mot; }
        i++;
    }
    return res;
}

Dessin readJson(std::ifstream &fic){ //TODO CleanCode !!!!!
    std::string line;

    std::vector<Forme*> formes;
    Dessin dessin = Dessin(formes);

    while(getline(fic, line))
    {//TODO correct line to text between {}
        if(line.find("height_dessin") < line.size()){
            std::string value = getValue(line);
            value.pop_back();
            dessin.setHeight(std::stod(value));
        } else if(line.find("width_dessin") < line.size()) {
            std::string value = getValue(line);
            value.pop_back();
            dessin.setWidth(std::stoi(getValue(line)));
        } else if(line.find("rectangle") < line.size()){
                Rectangle rectangle;
                int height;
                int width;
                int posx;
                int posy;
                std::string fill;

                std::size_t pos = line.find("{");
                std::string forme = line.substr(pos);

                std::istringstream iss(forme);
                std::string property;
                while(getline(iss, property, ',')){
                    if(property.find("width") < property.size()){
                        width = std::stoi(getValue(property));

                    } else if(property.find("height") < property.size()){
                        height = std::stoi(getValue(property));

                    } else if(property.find("posx") < property.size()){
                        posx = std::stoi(getValue(property));

                    } else if(property.find("posy") < property.size()){
                        posy = std::stoi(getValue(property));

                    } else if(property.find("fill") < property.size()){
                        std::string value = getValue(property);

                        std::size_t firstpos = value.find("\"");
                        std::size_t secondpos = value.find("\"", firstpos+1);

                        fill = value.substr (firstpos+1, secondpos-firstpos-1);
                    }
                }
                rectangle.setWidth(width);
                rectangle.setHeight(height);
                rectangle.setPosx(posx);
                rectangle.setPosy(posy);
                rectangle.setFill(fill);
                dessin.formes.push_back(new Rectangle(rectangle));

        } else if (line.find("cercle") < line.size()){
            Cercle cercle;
            int radius;
            int posx;
            int posy;
            std::string fill;

            std::size_t pos = line.find("{");
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("radius") < property.size()){
                    radius = std::stoi(getValue(property));
                } else if(property.find("posx") < property.size()){
                    posx = std::stoi(getValue(property));

                } else if(property.find("posy") < property.size()){
                    posy = std::stoi(getValue(property));

                } else if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstpos = value.find("\"");
                    std::size_t secondpos = value.find("\"", firstpos+1);

                    fill = value.substr (firstpos+1, secondpos-firstpos-1);
                }

            }
            cercle.setRadius(radius);
            cercle.setPosx(posx);
            cercle.setPosy(posy);
            cercle.setFill(fill);
            dessin.formes.push_back(new Cercle(cercle));

        } else if (line.find("line") < line.size()){
            std::string fill;

            std::size_t pos = line.find("{");
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstpos = value.find("\"");
                    std::size_t secondpos = value.find("\"", firstpos+1);

                    fill = value.substr (firstpos+1, secondpos-firstpos-1);
                }

            }
        } else if (line.find("polygone") < line.size()){
            std::string fill;

            std::size_t pos = line.find("{");
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstpos = value.find("\"");
                    std::size_t secondpos = value.find("\"", firstpos+1);

                    fill = value.substr (firstpos+1, secondpos-firstpos-1);
                }

            }

        }

        //Définition des formes
            //PosX
            //PoxY
            //Fill
            //Définition des paramètres des formes
            //Line
            //Polygone
                //Points

    }
    describeDessin(dessin);
    return dessin;
}

Dessin openJson(const std::string& filename){
    std::ifstream fic(filename, std::ios::in);

    Dessin dessin = readJson(fic);
    fic.close();

    return dessin;
}

bool verifyJson(const std::string& filename){
    std::ifstream fic(filename, std::ios::in);

    if(fic){
        fic.close();
        return true;
    }
    std::cout<<"Fichier Introuvable"<<std::endl;
    return false;

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

Dessin creationdessin(){
    std::vector<Forme*> formes;
    Dessin dessin = Dessin(formes);
    affichermenucreation(dessin);
    editionmenu(dessin);
    return dessin;
}

void startprogram(){
    int selection = 0;
    bool selectable = false;
    while (!selectable){
        affichemenu();
        std::cin >> selection;
        std::string filename;
        switch (selection) {
            case 1:
                selectable = true;
                creationdessin();
                break;
            case 2:

                std::cout<<"Veuillez saisir le nom du fichier :"<<std::endl;
                std::cin>>filename;

                selectable = false;
                if(verifyJson(filename)){
                    Dessin dessin = openJson(filename);
                    editionmenu(dessin);
                }

                break;
            case 3:
                selectable = true;


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

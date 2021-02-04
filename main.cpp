#include <iostream>
#include <list>
#include "Class/Rectangle.h"
#include "Class/Dessin.h"
#include "Class/Circle.h"
#include "Class/Polygone.h"
#include "Class/Segment.h"
#include <fstream>
#include <sstream>
#include <string>


void exporttosvg(Dessin currentDessin);
void saveasjson(Dessin currentDessin);

void affichemenu(){
    std::cout << "MENU : \n" << std::endl;

    std::cout << "Créer un dessin : 1" << std::endl;
    std::cout << "Charger un dessin : 2" << std::endl;
    std::cout << "Fusionner 2 dessins : 3" << std::endl;
    std::cout << "Quitter : 9" << std::endl;
}

void affichemenuresizemove(){
    std::cout << "MENU : \n" << std::endl;

    std::cout << "Agrandir : 1" << std::endl;
    std::cout << "Reduire : 2" << std::endl;
    std::cout << "Décaler sur les X : 3" << std::endl;
    std::cout << "Décaler sur les Y : 4" << std::endl;
    std::cout << "Quitter : 9" << std::endl;
}

void affichemenuedition(){

    std::cout << "MENU EDITION DESSIN : \n" << std::endl;

    std::cout << "Rajouter une forme : 1" << std::endl;
    std::cout << "Sauvegarder le dessin : 2" << std::endl;
    std::cout << "Exporter en SVG : 3" << std::endl;
    std::cout << "Retirer une forme : 4" << std::endl;
    std::cout << "Voir le contenu du dessin : 5" << std::endl;
    std::cout << "Deplacer/Agrandir : 6" << std::endl;
    std::cout << "Quitter sans sauvegarder : 9" << std::endl;

}

void addformemenu(){
    std::cout << "CHOIX DE FORME : \n" << std::endl;

    std::cout << "Rectangle 1" << std::endl;
    std::cout << "Circle 2" << std::endl;
    std::cout << "Segment 3" << std::endl;
    std::cout << "Polygone 4" << std::endl;
    std::cout << "Retour : 9" << std::endl;

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
}

void saveasjson(Dessin dessin){
    std::string filename;
    std::cout<<"veuillez saisir le nom du fichier"<<std::endl;
    std::cin>>filename;
    std::ofstream outfile(filename+".json");
    outfile << "{"<<std::endl;
    outfile << "\"height_dessin\":"+std::to_string(dessin.getHeight())+",\n";
    outfile << "\"width_dessin\":"+std::to_string(dessin.getWidth())+",\n";

    for (int i = 0; i < dessin.formes.size(); ++i) {
        if (i+1==dessin.formes.size()){
            outfile<<"\""+std::to_string(i+1)+"\":";
            std::string content = dessin.formes[i]->getjsoncontent();
            content.pop_back();
            outfile<<content;
        }else{
            outfile<<"\""+std::to_string(i+1)+"\":";
            outfile<<dessin.formes[i]->getjsoncontent();
            outfile<<"\n";
        }
    }

    outfile<<"\n}";
}

Dessin agrandir(Dessin dessin){
    float coef;
    std::cout<<"veuillez saisir le coefficient"<<std::endl;
    std::cin>>coef;
    for (int i = 0; i < dessin.formes.size(); ++i) {
        dessin.formes[i]->agrandirforme(coef);
    }
    return dessin;
}

Dessin reduire(Dessin dessin){
    float coef;
    std::cout<<"veuillez saisir le coefficient"<<std::endl;
    std::cin>>coef;
    for (int i = 0; i < dessin.formes.size(); ++i) {
        dessin.formes[i]->reduireforme(coef);
    }
    return dessin;
}

Dessin movex(Dessin dessin){
    float coef;
    std::cout<<"veuillez saisir le coefficient"<<std::endl;
    std::cin>>coef;
    for (int i = 0; i < dessin.formes.size(); ++i) {
        dessin.formes[i]->movexforme(coef);
    }
    return dessin;
}

Dessin movey(Dessin dessin){
    float coef;
    std::cout<<"veuillez saisir le coefficient"<<std::endl;
    std::cin>>coef;
    for (int i = 0; i < dessin.formes.size(); ++i) {
        dessin.formes[i]->moveyforme(coef);
    }
    return dessin;
}

Rectangle createRectangle(){
    Rectangle rectangle;
    float height;
    float width;
    float posx;
    float posy;
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
Circle createCercle(){
    Circle cercle;
    float radius;
    float posx;
    float posy;
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

Segment createLine(){
    Segment line;
    float x1;
    float y1;
    float x2;
    float y2;
    std::string fill;
    std::cout << "MENU CREATION LIGNE : \n" << std::endl;
    std::cout << "x1 :" << std::endl;
    std::cin >> x1;
    std::cout << "y1 :" << std::endl;
    std::cin >> y1;
    std::cout << "x2 :" << std::endl;
    std::cin >> x2 ;
    std::cout << "y2 :" << std::endl;
    std::cin >> y2 ;
    std::cout << "fill :" << std::endl;
    std::cin >> fill;
    line.setPoint1(Point(x1,y1));
    line.setPoint2(Point(x2,y2));
    line.setFill(fill);
    return line;
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
        float x;
        float y;
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
        std::cout<<"n°"<<i+1<<dessin.formes[i]->getcontent()<<std::endl;
    }
}



Dessin removeElement(Dessin &dessin){
    int elementnumber;
    std::cout << "numero de l'element :" << std::endl;
    std::cin >> elementnumber;

    dessin.formes.erase(dessin.formes.begin()+elementnumber-1);
    return dessin;
}

Dessin resizemove(Dessin dessin){
    int selection = 0;
    while (true){
        affichemenuresizemove();
        std::cin >> selection;
        switch (selection) {
            case 1:
                dessin = agrandir(dessin);
                break;
            case 2:
                dessin = reduire(dessin);
                break;
            case 3:
                dessin = movex(dessin);
                break;
            case 4:
                dessin = movey(dessin);
                break;
            case 9:
                return dessin;
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
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
                dessin.formes.push_back(new Circle(createCercle()));
//cercle
                break;
            case 3:
                dessin.formes.push_back(new Segment(createLine()));
//segment
                break;
            case 4:
                dessin.formes.push_back(new Polygone(createPolygone()));
//polygone
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
                saveasjson(dessin);
                break;
            case 3:
                exporttosvg(dessin);
                break;
            case 4:
                removeElement(dessin);
//dessin
                break;
            case 5:
                describeDessin(dessin);
//dessin
                break;
            case 6:
                resizemove(dessin);
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

    std::vector<Shape*> formes;
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
            float height;
            float width;
            float posx;
            float posy;
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
            Circle cercle;
            float radius;
            float posx;
            float posy;
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
            dessin.formes.push_back(new Circle(cercle));

        } else if (line.find("line") < line.size()){
            Segment segment;
            float x1;
            float y1;
            float x2;
            float y2;
            std::string fill;

            std::size_t pos = line.find("{");
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("x1") < property.size()){
                    x1 = std::stoi(getValue(property));
                } else if(property.find("y1") < property.size()){
                    y1 = std::stoi(getValue(property));
                } else if(property.find("x2") < property.size()){
                    x2 = std::stoi(getValue(property));
                } else if(property.find("y2") < property.size()){
                    y2 = std::stoi(getValue(property));
                } else if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstpos = value.find("\"");
                    std::size_t secondpos = value.find("\"", firstpos+1);

                    fill = value.substr (firstpos+1, secondpos-firstpos-1);
                }

            }
            segment.setPoint1(Point(x1,y1));
            segment.setPoint2(Point(x2,y2));
            segment.setFill(fill);
            dessin.formes.push_back(new Segment(segment));
        } else if (line.find("polygone") < line.size()){
            Polygone polygone;
            std::vector<Point*> listePoints;
            std::string fill;

            std::size_t pos = line.find("{");
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("point") < property.size()){
                    std::string pointsList = getValue(property);
                    std::string posx, posy;

                    std::size_t firstpos = pointsList.find("\"");
                    pointsList = pointsList.substr (firstpos + 1);
                    pointsList.pop_back();

                    int nbPoints = 0;
                    for (int i = 0; i < pointsList.size(); i++){
                        if (pointsList[i] == ';') nbPoints++;
                    }

                    for(int i = 0; i < nbPoints; i++){
                        std::size_t posSeparator = pointsList.find(";");
                        posx = pointsList.substr (0, posSeparator);
                        pointsList = pointsList.substr(posSeparator + 1);

                        std::size_t posSpace = pointsList.find(" ");
                        posy = pointsList.substr(0, posSpace);
                        pointsList = pointsList.substr(posSpace + 1);

                        Point* point = new Point(std::stoi(posx), std::stoi(posy));
                        listePoints.push_back(point);
                    }

                } else if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstpos = value.find("\"");
                    std::size_t secondpos = value.find("\"", firstpos+1);

                    fill = value.substr (firstpos+1, secondpos-firstpos-1);
                }

            }

            polygone.setListePoints(listePoints);
            polygone.setFill(fill);

            dessin.formes.push_back(new Polygone(polygone));

        }

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
    float height;
    float width;
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
    std::vector<Shape*> formes;
    Dessin dessin = Dessin(formes);
    affichermenucreation(dessin);
    editionmenu(dessin);
    return dessin;
}

Dessin fusion(Dessin firstDrawing,Dessin secondDrawing){
    std::vector<Shape*> formes;
    float maxheight;
    float maxwidth;

    if(firstDrawing.height>secondDrawing.height){
        maxheight = firstDrawing.height;
    }else{
        maxheight = secondDrawing.height;
    }
    if(firstDrawing.width>secondDrawing.width){
        maxwidth = firstDrawing.width;
    }else{
        maxwidth = secondDrawing.width;
    }
    for (int i = 0; i < secondDrawing.formes.size(); ++i) {
        firstDrawing.formes.push_back(secondDrawing.formes.at(i));
    }

    Dessin dessin = Dessin(firstDrawing.formes,maxheight,maxwidth);

    return dessin;
}

void startprogram(){
    int selection = 0;
    bool selectable = false;
    while (!selectable){
        affichemenu();
        std::cin >> selection;
        std::string filename;
        std::string firstfile;
        std::string secondfile;
        switch (selection) {
            case 1:
                selectable = true;
                creationdessin();
                break;
            case 2:
                selectable = true;
                std::cout<<"Veuillez saisir le nom du fichier :"<<std::endl;
                std::cin>>filename;
                if(verifyJson(filename)){
                    Dessin dessin = openJson(filename);
                    editionmenu(dessin);
                }
                break;
            case 3:
                selectable = true;
                std::cout<<"Veuillez saisir le nom du 1er fichier :"<<std::endl;
                std::cin>>firstfile;
                std::cout<<"Veuillez saisir le nom du 2nd fichier :"<<std::endl;
                std::cin>>secondfile;
                if(verifyJson(firstfile)&&verifyJson(secondfile)){
                    Dessin firstdessin = openJson(firstfile);
                    Dessin seconddessin = openJson(secondfile);
                    Dessin dessin = fusion(firstdessin,seconddessin);
                    editionmenu(dessin);
                }
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

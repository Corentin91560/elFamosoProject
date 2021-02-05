#include <iostream>
#include <list>
#include "Class/Rectangle.h"
#include "Class/Drawing.h"
#include "Class/Circle.h"
#include "Class/Polygon.h"
#include "Class/Segment.h"
#include <fstream>
#include <sstream>
#include <string>

void displayPrincipalMenu(){
    std::cout << "MENU : \n" << std::endl;

    std::cout << "Créer un dessin : 1" << std::endl;
    std::cout << "Charger un dessin : 2" << std::endl;
    std::cout << "Fusionner 2 dessins : 3" << std::endl;
    std::cout << "Quitter : 9" << std::endl;
}

void displayEditionMenu(){
    std::cout << "MENU EDITION DESSIN : \n" << std::endl;

    std::cout << "Rajouter une forme : 1" << std::endl;
    std::cout << "Sauvegarder le dessin : 2" << std::endl;
    std::cout << "Exporter en SVG : 3" << std::endl;
    std::cout << "Retirer une forme : 4" << std::endl;
    std::cout << "Voir le contenu du dessin : 5" << std::endl;
    std::cout << "Deplacer/Agrandir : 6" << std::endl;
    std::cout << "Quitter sans sauvegarder : 9" << std::endl;
}

void displayMenuModifyDrawing(){
    std::cout << "MENU : \n" << std::endl;

    std::cout << "Agrandir : 1" << std::endl;
    std::cout << "Reduire : 2" << std::endl;
    std::cout << "Décaler sur les X : 3" << std::endl;
    std::cout << "Décaler sur les Y : 4" << std::endl;
    std::cout << "Quitter : 9" << std::endl;
}

void addShapeMenu(){
    std::cout << "CHOIX DE FORME : \n" << std::endl;

    std::cout << "Rectangle 1" << std::endl;
    std::cout << "Circle 2" << std::endl;
    std::cout << "Segment 3" << std::endl;
    std::cout << "Polygon 4" << std::endl;
    std::cout << "Retour : 9" << std::endl;
}

int checkEntry(char entry) {
    if((int)entry >= 48 && (int)entry <= 57){
        return entry - '0';
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return 0;
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

Circle createCircle(){
    Circle circle;
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
    circle.setRadius(radius);
    circle.setPosx(posx);
    circle.setPosy(posy);
    circle.setFill(fill);
    return circle;
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

Polygon createPolygon(){
    Polygon polygon;
    std::vector<Point*> listPoints;
    int pointsNumber;
    std::string fill;
    std::cout << "MENU CREATION POLYGONE : \n" << std::endl;
    std::cout << "Nombre de points:" << std::endl;
    std::cin >> pointsNumber;
    std::cout << "fill :" << std::endl;
    std::cin >> fill;
    polygon.setFill(fill);

    int i = 0;
    while (i < pointsNumber){
        float x;
        float y;
        std::cout << "Coordonnées du point n°" << i+1 << std::endl;
        std::cout << "x :" << std::endl;
        std::cin >> x;
        std::cout << "y :" << std::endl;
        std::cin >> y;
        auto* point = new Point(x, y);
        listPoints.push_back(point);
        i++;
    }
    polygon.setListPoints(listPoints);
    return polygon;
}

Drawing selectNewShape(Drawing drawing){
    int selection;
    while (true){
        addShapeMenu();
        char entry;
        std::cin >> entry;
        selection = checkEntry(entry);

        switch (selection) {
            case 1:
                drawing.listShapes.push_back(new Rectangle(createRectangle()));
                break;
            case 2:
                drawing.listShapes.push_back(new Circle(createCircle()));
                break;
            case 3:
                drawing.listShapes.push_back(new Segment(createLine()));
                break;
            case 4:
                drawing.listShapes.push_back(new Polygon(createPolygon()));
                break;
            case 9:
                return drawing;
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

void saveAsJson(Drawing drawing){
    std::string fileName;
    std::cout << "veuillez saisir le nom du fichier" << std::endl;
    std::cin >> fileName;
    std::ofstream outfile(fileName + ".json");
    outfile << "{" << std::endl;
    outfile << "\"height_dessin\":" + std::to_string(drawing.getHeight()) + ",\n";
    outfile << "\"width_dessin\":" + std::to_string(drawing.getWidth()) + ",\n";

    for (int i = 0; i < drawing.listShapes.size(); ++i) {
        if (i+1 == drawing.listShapes.size()){
            outfile << "\""+std::to_string(i+1) + "\":";
            std::string content = drawing.listShapes[i]->getJsonContent();
            content.pop_back();
            outfile << content;
        }else{
            outfile << "\""+std::to_string(i+1) + "\":";
            outfile << drawing.listShapes[i]->getJsonContent();
            outfile << "\n";
        }
    }

    outfile << "\n}";
}

void exportToSVG(Drawing currentDrawing) {
    std::string fileName;
    std::cout << "Veuillez saisir le nom du fichier" << std::endl;
    std::cin >> fileName;
    std::ofstream outfile(fileName + ".svg");
    outfile << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
               "<svg width=\"" << currentDrawing.width << "\" height=\"" << currentDrawing.height << "\" xmlns=\"http://www.w3.org/2000/svg\">\n"
                                                                                                     "<rect fill=\"#fff\" stroke=\"#000\" x=\"0\" y=\"0\" width=\"" << currentDrawing.width << "\" height=\"" << currentDrawing.height << "\"/>\n" << std::endl;

    for (auto & listShape : currentDrawing.listShapes) {
        outfile << listShape->getSVGContent();
    }

    outfile<<"</svg>";
}

Drawing removeElement(Drawing &drawing){
    int elementNumber;
    std::cout << "Numéro de l'element :" << std::endl;
    std::cin >> elementNumber;

    drawing.listShapes.erase(drawing.listShapes.begin() + elementNumber - 1);
    return drawing;
}

void describeDrawing(Drawing &drawing){
    std::cout << "Hauteur du drawing : " << drawing.getHeight() << " et Largueur : " << drawing.getWidth() << std::endl;
    for (int i = 0; i < drawing.listShapes.size(); ++i) {
        std::cout << "n°" <<i+1 << drawing.listShapes[i]->getContent() << std::endl;
    }
}

Drawing extendDrawing(Drawing drawing){
    float coef;
    std::cout << "veuillez saisir le coefficient" << std::endl;
    std::cin >> coef;
    for (auto & listShape : drawing.listShapes) {
        listShape->extendShape(coef);
    }
    return drawing;
}

Drawing reduceDrawing(Drawing drawing){
    float coef;
    std::cout << "veuillez saisir le coefficient" << std::endl;
    std::cin >> coef;
    for (auto & listShape : drawing.listShapes) {
        listShape->reduceShape(coef);
    }
    return drawing;
}

Drawing moveX(Drawing drawing){
    float coef;
    std::cout << "Veuillez saisir le coefficient" << std::endl;
    std::cin >> coef;
    for (auto & listShape : drawing.listShapes) {
        listShape->moveShapeX(coef);
    }
    return drawing;
}

Drawing moveY(Drawing drawing){
    float coef;
    std::cout << "Veuillez saisir le coefficient" << std::endl;
    std::cin >> coef;
    for (auto & listShape : drawing.listShapes) {
        listShape->moveShapeY(coef);
    }
    return drawing;
}

Drawing modifyDrawing(Drawing drawing){
    int selection;
    while (true){
        displayMenuModifyDrawing();
        char entry;
        std::cin >> entry;
        selection = checkEntry(entry);

        switch (selection) {
            case 1:
                drawing = extendDrawing(drawing);
                break;
            case 2:
                drawing = reduceDrawing(drawing);
                break;
            case 3:
                drawing = moveX(drawing);
                break;
            case 4:
                drawing = moveY(drawing);
                break;
            case 9:
                return drawing;
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

void drawingEditionMenu(Drawing &drawing){
    int selection;
    bool selectable = false;
    while (!selectable){
        displayEditionMenu();
        char entry;
        std::cin >> entry;
        selection = checkEntry(entry);

        switch (selection) {
            case 1:
                drawing = Drawing(selectNewShape(drawing));
                break;
            case 2:
                saveAsJson(drawing);
                break;
            case 3:
                exportToSVG(drawing);
                break;
            case 4:
                removeElement(drawing);
                break;
            case 5:
                describeDrawing(drawing);
                break;
            case 6:
                modifyDrawing(drawing);
                break;
            case 9:
                selectable = true;
                displayPrincipalMenu();
                break;
            default:
                std::cout << "Entrée incorrecte, veuillez choisir une valeur appropriée\n" << std::endl;
                break;
        }
    }
}

Drawing displayDrawingCreationMenu(Drawing &drawing){
    float height;
    float width;
    std::cout << "MENU CREATION DESSIN : \n" << std::endl;
    std::cout << "Hauteur :" << std::endl;
    std::cin >> height;
    std::cout << "Largeur :" << std::endl;
    std::cin >> width ;
    drawing.setHeight(height);
    drawing.setWidth(width);
    std::cout << "Hauteur : " << height << " Largeur : " << width << std::endl;
    return drawing;
}

Drawing createDrawing(){
    std::vector<Shape*> shapes;
    Drawing drawing = Drawing(shapes);
    displayDrawingCreationMenu(drawing);
    drawingEditionMenu(drawing);
    return drawing;
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

std::string getValue(const std::string& property){
    std::istringstream iss2(property);
    std::string word;
    std::string res;
    int i = 0;
    while ( std::getline(iss2, word, ':' ) )
    {
        if(i!=0){ res = word; }
        i++;
    }
    return res;
}

Drawing readJson(std::ifstream &file){
    std::string line;

    std::vector<Shape*> listShapes;
    Drawing drawing = Drawing(listShapes);

    while(getline(file, line))
    {
        if(line.find("height_dessin") < line.size()){
            std::string value = getValue(line);
            value.pop_back();
            drawing.setHeight(std::stof(value));
        } else if(line.find("width_dessin") < line.size()) {
            std::string value = getValue(line);
            value.pop_back();
            drawing.setWidth(std::stof(getValue(line)));
        } else if(line.find("rectangle") < line.size()){
            Rectangle rectangle;
            float height;
            float width;
            float posx;
            float posy;
            std::string fill;

            std::size_t pos = line.find('{');
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){
                if(property.find("width") < property.size()){
                    width = std::stof(getValue(property));

                } else if(property.find("height") < property.size()){
                    height = std::stof(getValue(property));

                } else if(property.find("posx") < property.size()){
                    posx = std::stof(getValue(property));

                } else if(property.find("posy") < property.size()){
                    posy = std::stof(getValue(property));

                } else if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstPos = value.find('\"');
                    std::size_t secondPos = value.find('\"', firstPos + 1);

                    fill = value.substr (firstPos + 1, secondPos - firstPos - 1);
                }
            }
            rectangle.setWidth(width);
            rectangle.setHeight(height);
            rectangle.setPosx(posx);
            rectangle.setPosy(posy);
            rectangle.setFill(fill);
            drawing.listShapes.push_back(new Rectangle(rectangle));

        } else if (line.find("cercle") < line.size()){
            Circle cercle;
            float radius;
            float posx;
            float posy;
            std::string fill;

            std::size_t pos = line.find('{');
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("radius") < property.size()){
                    radius = std::stof(getValue(property));
                } else if(property.find("posx") < property.size()){
                    posx = std::stof(getValue(property));

                } else if(property.find("posy") < property.size()){
                    posy = std::stof(getValue(property));

                } else if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstPos = value.find('\"');
                    std::size_t secondPos = value.find('\"', firstPos + 1);

                    fill = value.substr (firstPos + 1, secondPos - firstPos - 1);
                }

            }
            cercle.setRadius(radius);
            cercle.setPosx(posx);
            cercle.setPosy(posy);
            cercle.setFill(fill);
            drawing.listShapes.push_back(new Circle(cercle));

        } else if (line.find("line") < line.size()){
            Segment segment;
            float x1;
            float y1;
            float x2;
            float y2;
            std::string fill;

            std::size_t pos = line.find('{');
            std::string forme = line.substr(pos);

            std::istringstream iss(forme);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("x1") < property.size()){
                    x1 = std::stof(getValue(property));
                } else if(property.find("y1") < property.size()){
                    y1 = std::stof(getValue(property));
                } else if(property.find("x2") < property.size()){
                    x2 = std::stof(getValue(property));
                } else if(property.find("y2") < property.size()){
                    y2 = std::stof(getValue(property));
                } else if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstPos = value.find('\"');
                    std::size_t secondPos = value.find('\"', firstPos+1);

                    fill = value.substr (firstPos+1, secondPos-firstPos-1);
                }

            }
            segment.setPoint1(Point(x1,y1));
            segment.setPoint2(Point(x2,y2));
            segment.setFill(fill);
            drawing.listShapes.push_back(new Segment(segment));
        } else if (line.find("polygone") < line.size()){
            Polygon polygon;
            std::vector<Point*> listPoints;
            std::string fill;

            std::size_t pos = line.find('{');
            std::string shape = line.substr(pos);

            std::istringstream iss(shape);
            std::string property;
            while(getline(iss, property, ',')){

                if(property.find("point") < property.size()){
                    std::string pointsList = getValue(property);
                    std::string posx, posy;

                    std::size_t firstPos = pointsList.find('\"');
                    pointsList = pointsList.substr (firstPos + 1);
                    pointsList.pop_back();

                    int nbPoints = 0;
                    for (char i : pointsList){
                        if (i == ';') nbPoints++;
                    }

                    for(int i = 0; i < nbPoints; i++){
                        std::size_t posSeparator = pointsList.find(';');
                        posx = pointsList.substr (0, posSeparator);
                        pointsList = pointsList.substr(posSeparator + 1);

                        std::size_t posSpace = pointsList.find(' ');
                        posy = pointsList.substr(0, posSpace);
                        pointsList = pointsList.substr(posSpace + 1);

                        auto* point = new Point(std::stof(posx), std::stof(posy));
                        listPoints.push_back(point);
                    }

                } else if(property.find("fill") < property.size()){
                    std::string value = getValue(property);

                    std::size_t firstPos = value.find('\"');
                    std::size_t secondPos = value.find('\"', firstPos+1);

                    fill = value.substr (firstPos+1, secondPos-firstPos-1);
                }

            }
            polygon.setListPoints(listPoints);
            polygon.setFill(fill);

            drawing.listShapes.push_back(new Polygon(polygon));
        }
    }
    describeDrawing(drawing);
    return drawing;
}

Drawing openJson(const std::string& fileName){
    std::ifstream fic(fileName, std::ios::in);
    Drawing drawing = readJson(fic);
    fic.close();

    return drawing;
}

Drawing fusion(Drawing firstDrawing, const Drawing& secondDrawing){
    float maxheight;
    float maxwidth;

    if(firstDrawing.height > secondDrawing.height){
        maxheight = firstDrawing.height;
    } else {
        maxheight = secondDrawing.height;
    }
    if(firstDrawing.width > secondDrawing.width){
        maxwidth = firstDrawing.width;
    } else {
        maxwidth = secondDrawing.width;
    }
    for (auto listShape : secondDrawing.listShapes) {
        firstDrawing.listShapes.push_back(listShape);
    }

    Drawing drawing = Drawing(firstDrawing.listShapes, maxheight, maxwidth);

    return drawing;
}

void startprogram(){
    int selection;
    bool selectable = false;
    while (!selectable){
        displayPrincipalMenu();
        char entry;
        std::cin >> entry;
        selection = checkEntry(entry);

        std::string fileName;
        std::string secondFileName;
        switch (selection) {
            case 1:
                selectable = true;
                createDrawing();
                break;
            case 2:
                selectable = true;
                std::cout<<"Veuillez saisir le nom du fichier :"<<std::endl;
                std::cin >> fileName;
                if(verifyJson(fileName)){
                    Drawing drawing = openJson(fileName);
                    drawingEditionMenu(drawing);
                }
                break;
            case 3:
                selectable = true;
                std::cout<<"Veuillez saisir le nom du 1er fichier :"<<std::endl;
                std::cin >> fileName;
                std::cout<<"Veuillez saisir le nom du 2nd fichier :"<<std::endl;
                std::cin >> secondFileName;
                if(verifyJson(fileName) && verifyJson(secondFileName)){
                    Drawing firstDrawing = openJson(fileName);
                    Drawing secondDrawing = openJson(secondFileName);
                    Drawing drawing = fusion(firstDrawing, secondDrawing);
                    drawingEditionMenu(drawing);
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
    startprogram();
    return 0;
}
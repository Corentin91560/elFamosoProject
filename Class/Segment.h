//
// Created by corentin delage on 03/02/2021.
//

#ifndef TEST_SEGMENT_H
#define TEST_SEGMENT_H


#include "Forme.h"
#include "Point.h"

class Segment : public Forme{
private:
    Point point1;
    Point point2;

public:
    virtual ~Segment();

    Segment();

    Segment(const Point &point1, const Point &point2);

    void setPoint1(const Point &point1);

    void setPoint2(const Point &point2);

    void setPosx(int posx) override;

    void setPosy(int posy) override;

    void setFill(const std::string &fill) override;

    std::string getcontent() override;

    std::string getsvgcontent() override;

    std::string getjsoncontent() override;

};


#endif //TEST_SEGMENT_H

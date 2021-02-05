//
// Created by corentin delage on 03/02/2021.
//

#ifndef TEST_SEGMENT_H
#define TEST_SEGMENT_H


#include "Shape.h"
#include "Point.h"

class Segment : public Shape{
private:
    Point point1;
    Point point2;

public:
    virtual ~Segment();

    Segment();

    Segment(const Point &point1, const Point &point2);

    void setPoint1(const Point &point1);

    void setPoint2(const Point &point2);

    void setPosx(float posx) override;

    void setPosy(float posy) override;

    void setFill(const std::string &fill) override;

    std::string getContent() override;

    std::string getSVGContent() override;

    std::string getJsonContent() override;

    void extendShape(float coef) override;

    void reduceShape(float coef) override;

    void moveShapeX(float coef) override;

    void moveShapeY(float coef) override;

};


#endif //TEST_SEGMENT_H

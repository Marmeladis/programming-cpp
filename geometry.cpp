#include "geometry.h"
#include <cmath>

double Dot::getX() const {
    return this->x_;
}

double Dot::getY() const {
    return this->y_;
}

Dot& Dot::operator=(const Dot& other) {
    if (&other == this) {
        return *this;
    }
    x_ = other.x_;
    y_ = other.y_;
    return *this;
}

Polyline& Polyline::operator=(const Polyline& other) {
    if (&other == this) {
        return *this;
    }
    dots_ = other.dots_;
    return *this;
}

const Dot& Polyline::operator[](const size_t index) const {
    return this->dots_[index % this->dots_.size()];
}

double Polyline::findLength() const {
    double length = 0;
    for (int i = 0; i < this->dots_.size () - 1; ++ i) {
        length += hypot(this->dots_[i + 1].getX () - this->dots_[i].getX (),
                         this->dots_[i + 1].getY () - this->dots_[i].getY ());
    }
    return length;
}

size_t Polyline::getCountOfVertices() const {
    return this->dots_.size();
}

void Polyline::addVertice(const Dot& other) {
    this->dots_.emplace_back(other);
}

ClosedPolyline& ClosedPolyline::operator=(const ClosedPolyline& other) {
    if (&other == this) {
        return *this;
    }
    dots_ = other.dots_;
    return *this;
}

void ClosedPolyline::addVertice (const Dot& other) {
    this->dots_.back() = other;
    this->dots_.emplace_back(dots_.front());
}

Polygon& Polygon::operator=(const Polygon& other) {
    if (&other == this) {
        return *this;
    }
    dots_ = other.dots_;
    return *this;
}

double Polygon::findPerimeter() const {
    return this->dots_.findLength();
}

size_t Polygon::getCountOfVertices() const {
    return this->dots_.getCountOfVertices();
}

double Polygon::findArea() const {
    double area = 0;
    for (int i = 0; i < this->dots_.getCountOfVertices() - 1; ++i) {
        area += 0.5 * (this->dots_[i].getX() * this->dots_[i + 1].getY() - \
            this->dots_[i + 1].getX() * this->dots_[i].getY());
    }
    return fabs(area);
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (&other == this) {
        return *this;
    }
    dots_ = other.dots_;
    return *this;
}

Trapezium& Trapezium::operator=(const Trapezium& other) {
    if (&other == this) {
        return *this;
    }
    dots_ = other.dots_;
    return *this;
}

RegularPolygon& RegularPolygon::operator=(const RegularPolygon& other) {
    if (&other == this) {
        return *this;
    }
    vertices_ = other.vertices_;
    side_ = other.side_;
    return *this;
}

double RegularPolygon::findPerimeter() const {
    return this->vertices_ * this->side_;
}

double RegularPolygon::findArea() const {
    double pi = acos (- 1);
    return this->vertices_ * pow (this->side_, 2) / (4 * tan (180.0 / this->vertices_ * pi / 180.0));
}

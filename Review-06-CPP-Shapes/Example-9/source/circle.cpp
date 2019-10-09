// Thomas Kennedy
// CS 330 Fall 2014

#include <iomanip>

#include "circle.h"

const double Circle::PI  = 3.14159265359;
const double Circle::TAU = 2 * PI;

//------------------------------------------------------------------------------
Circle::Circle()
	:Shape("Circle"),
     _radius(1)
{
}

//------------------------------------------------------------------------------
Circle::Circle(double r)
	:Shape("Circle"),
     _radius(r)
{
}

//------------------------------------------------------------------------------
Circle::Circle(const Circle& src)
	:Shape(src._name),
     _radius(src._radius)
{
}

//------------------------------------------------------------------------------
Circle::~Circle()
{
}

//------------------------------------------------------------------------------
void Circle::display(std::ostream &outs) const
{
    Shape::display(outs);

    outs << std::left  << std::setw(WIDTH_LABEL)
                       << "Radius"     << ": "
         << std::right << std::setw(WIDTH_VALUE)
                       << radius()     << "\n"
         << std::left  << std::setw(WIDTH_LABEL)
                       << "Diameter"   << ": "
         << std::right << std::setw(WIDTH_VALUE)
                       << diameter()   << "\n"
         << std::left  << std::setw(WIDTH_LABEL)
                       << "Perimeter"  << ": "
         << std::right << std::setw(WIDTH_VALUE)
                       << perimeter()  << "\n"
         << std::left  << std::setw(WIDTH_LABEL)
                       << "Area"       << ": "
         << std::right << std::setw(WIDTH_VALUE)
                       << area()       << "\n";
}

//------------------------------------------------------------------------------
void Circle::read(std::istream& ins)
{
    ins >> this->_radius;
}

#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <string>
#include <vector>
//#include "construction.h"

class Position
{
public:
	double x = 0.;
	double y = 0.;
	Position(double x, double y);
	Position();
};


class Element
{
protected:
    std::string name;
	Position position;
public:
    Element();
    Element(std::string name);
	Element(Position position);
	Element(std::string name, Position position);

	void set_name(std::string name);
	void set_position(Position position);
};


class Pin : public Element
{
private:
    
public:

};


class Beam : public Element
{
protected:
	double length = 0.;

public:
	Beam();
	Beam(double length);
	Beam(double length, Position position);
	Beam(std::string name, double length, Position position);

	void set_length(double length);
};


#endif
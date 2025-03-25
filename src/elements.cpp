#include "elements.h"
#include "construction.h"

Position::Position()
{

}


Position::Position(double x, double y)
{
	this->x = x;
	this->y = y;
}

Element::Element()
{
}

Element::Element(std::string name)
{
	this->name = name;
}

Element::Element(Position position)
{
	this->position = position;
}

Element::Element(std::string name, Position position)
{
	this->name = name;
	this->position = position;
}

void Element::set_name(std::string name)
{
	this->name = name;
}

void Element::set_position(Position position)
{
	this->position = position;
}


Beam::Beam()
{
}

Beam::Beam(double length)
{
	this->length = length;
}

Beam::Beam(double length, Position position)
{
	this->length = length;
	this->position = position;
}

Beam::Beam(std::string name, double length, Position position)
{
	this->name = name;
	this->length = length;
	this->position = position;
}

void Beam::set_length(double length)
{
	this->length = length;
}

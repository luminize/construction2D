#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <vector>
#include <string>

#include "elements.h"

class Construction
{
private:
    std::string name;
    std::vector<Element> construction_elements;
public:
    Construction();
    Construction(std::string construction_name);
    ~Construction();

    std::string getname();
};

#endif
#include "construction.h"

Construction::Construction()
{
}

Construction::Construction(std::string construction_name)
{
    name = construction_name;
}

Construction::~Construction()
{
}

std::string Construction::getname(){
    return name;
}

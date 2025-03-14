#include "construction.h"

construction::construction()
{
}

construction::construction(std::string construction_name)
{
    name = construction_name;
}

construction::~construction()
{
}

std::string construction::getname(){
    return name;
}

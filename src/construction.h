#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <vector>
#include <string>

class Construction
{
private:
    std::string name;
public:
    Construction();
    Construction(std::string construction_name);
    ~Construction();

    std::string getname();
};

#endif
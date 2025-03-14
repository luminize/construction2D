#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <vector>
#include <string>

class construction
{
private:
    std::string name;
public:
    construction();
    construction(std::string construction_name);
    ~construction();

    std::string getname();
};

#endif
#include "box2d/box2d.h"
#include "raylib.h"
#include "construction.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <fstream>

using json = nlohmann::json;

int main(){
    // instantiate a new construction
    Construction vakwerk("constructie"); 

    // read a json file to build construction from
    std::ifstream jsonfile("jsonfile.json");
    json data = json::parse(jsonfile);
    jsonfile.close();

    // for testing purposes
    std::cout << vakwerk.getname() << std::endl;
    std::cout << data;
}
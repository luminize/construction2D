#include "box2d/box2d.h"
#include "raylib.h"
#include "construction.h"
#include "json.hpp"

#include <iostream>
#include <fstream>

using json = nlohmann::json;

int main(){
    Construction vakwerk("constructie");
    std::ifstream jsonfile("jsonfile.json");
  
    std::ifstream f("example.json");
    json data = json::parse(f);

    std::cout << vakwerk.getname();
    std::cout << data;
}
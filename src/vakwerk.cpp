#include "box2d/box2d.h"
#include "raylib.h"
#include "construction.h"

#include <iostream>

int main(){
    Construction vakwerk("constructie");
    std::cout << vakwerk.getname();
}
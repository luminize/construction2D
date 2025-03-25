#include "box2d/box2d.h"
#include "raylib.h"
#include "construction.h"

#include <iostream>


int main(){
    // instantiate a new construction
    Construction vakwerk("constructie"); 

	vakwerk.create_construction_from_json("simple_construction.json");

}
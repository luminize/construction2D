#include <fstream>
#include "construction.h"


Connection::Connection()
{
}


Connection::~Connection()
{
}


Connection::Connection(Element element1, Element element2)
{
	this->element1 = element1;
	this->element2 = element2;
}


Construction::Construction()
{
}


Construction::Construction(std::string construction_name)
{
	this->name = construction_name;
}


Construction::~Construction()
{
}


std::string Construction::get_name(){
    return this->name;
}


void Construction::set_name(std::string name) {
	this->name = name;
}


void Construction::add_element(Element element) {
	this->elements.push_back(element);
}


void Construction::add_connection(Connection connection) {
	this->connections.push_back(connection);
}


void Construction::add_connection(Element element1, Element element2) {
	Connection connection(element1, element2);
	this->add_connection(connection);
}


void Construction::create_construction_from_json(std::string filename) {
	// read a json file to build construction from
	std::ifstream jsonfile(filename);
	nlohmann::json jsondata = nlohmann::json::parse(jsonfile);
	jsonfile.close();

	// populate the elements vector
	for (int i = 0; i < jsondata["elements"].size(); i++) {
		std::string e_name = jsondata["elements"][i]["name"];
		Position e_position(
			jsondata["elements"][i]["position"]["x"],
			jsondata["elements"][i]["position"]["y"]);
		Element element(e_name, e_position);
		this->add_element(element);
	}

	// populate the connections vector
	for (int i = 0; i < jsondata["connections"].size(); i++) {
		Element e_first = jsondata["connections"][i]["first_element"];
		Element e_second = jsondata["connections"][i]["second_element"];
		Connection c_connection(e_first, e_second);

		// the above now creates new elements that have no relation to
		// elements already created in the elements vector
		// instead of new elements, there should be a pointer to the 
		// element with the corresponding name

		// check also that the element string exists with the same name 
		// in the elements vector

		this->add_connection(c_connection);
	}
	
	// debugging purpose... remove when done..
	std::string plain_text = jsondata.dump(4);

}
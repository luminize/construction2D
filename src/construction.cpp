#include <fstream>
#include "construction.h"


Connection::Connection()
{
}


Connection::~Connection()
{
}


Connection::Connection(std::shared_ptr<Element> element1, std::shared_ptr<Element> element2)
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


void Construction::add_connection(std::shared_ptr<Element> element1, std::shared_ptr<Element> element2) {
	Connection connection(element1, element2);
	this->add_connection(connection);
}

std::shared_ptr<Element> Construction::find_element(std::string name) {
	// find an element by name in the elements vector
	std::shared_ptr<Element> element_ptr = nullptr;
	bool element_found = false;
	int i = 0;

	while (i < this->elements.size() && !element_found) {
		if (this->elements[i].get_name() == name){
			element_ptr = std::make_shared<Element>(this->elements[i]);
			element_found = true;
			}
		i++;
	}
	return element_ptr;
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
		
		// should we silently fail if the element name is not found in the elements
		// vector or should an element be created?
		// same goes for tags not being in the json file...

		std::string e_first = jsondata["connections"][i]["first_element"];
		std::string e_second = jsondata["connections"][i]["second_element"];
		std::shared_ptr<Element> ptr_first = this->find_element(e_first);
		std::shared_ptr<Element> ptr_second = this->find_element(e_second);

		Connection c_connection(ptr_first, ptr_second);

		this->add_connection(c_connection);
	}
	
	// debugging purpose... remove when done..
	std::string plain_text = jsondata.dump(4);

}
#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <vector>
#include <string>
#include <fstream>


#include "elements.h"
#include "nlohmann/json.hpp"


class Connection
{
protected:
	Element element1;
	Element element2;
public:
	Connection();
	Connection(Element element1, Element element2);
	~Connection();
};


class Construction
{
private:
    std::string name;
    std::vector<Element> elements;
	std::vector<Connection> connections;
public:
    Construction();
    Construction(std::string name);
    ~Construction();

    void set_name(std::string name);
    std::string get_name();
	void add_element(Element element);
	void add_connection(Connection connection);
	void add_connection(Element element1, Element element2);

	void create_construction_from_json(std::string filename);
};

#endif
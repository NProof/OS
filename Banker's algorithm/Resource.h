#ifndef RESOURCE_H
#define RESOURCE_H

#include "Process.h"

class Resource{
	unsigned int instances;
	std::map<Process*, unsigned int> max;
	
public :
	Resource(unsigned int instances){
		this->instances = instances;
	}
};

#endif
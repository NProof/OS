#ifndef SYSTEM_H
#define SYSTEM_H

#include <set>
#include "Process.h"
#include "Resource.h"

class System{
public :
	std::set<Process*> processSet;
	std::set<Resource*> resourceSet;
public :
	System(){}
	//Safety Algorithm
	//Resource-Request Algorithm
	//Deadlock-Detection Algorithm
};

#endif
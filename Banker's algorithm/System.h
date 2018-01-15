#ifndef SYSTEM_H
#define SYSTEM_H

#include <set>
#include "Process.h"
#include "Resource.h"

class System{
public :
	//Safety Algorithm
	//Resource-Request Algorithm
	//Deadlock-Detection Algorithm
	std::set<Process*> processSet;
	std::set<Resource*> resourceSet;
public :
	System(){}
	System(std::set<Resource*> resourceSet){
		this->resourceSet = resourceSet;
	}
	System(std::set<Resource*> resourceSet, std::set<Process*>){
		this->resourceSet = resourceSet;
		this->processSet = processSet;
	}
};

#endif
#ifndef SYSTEM_H
#define SYSTEM_H

#include <set>
#include "Process.h"
#include "Resource.h"

class System{
public :
	std::set<Process*> processSet;
	std::set<Resource*> resourceSet;
	
	void set(Process* p, Resource* r, unsigned int max, unsigned int allocation){
		p->max[r] = max;
		p->allocation[r] = allocation;
		p->need[r] = max - allocation;
		r->beRequest(allocation);
		processSet.insert(p);
		resourceSet.insert(r);
	}
	
	//Safety Algorithm
	//Resource-Request Algorithm
	//Deadlock-Detection Algorithm
	
};

#endif
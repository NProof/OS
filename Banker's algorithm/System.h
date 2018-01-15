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
		r->beRequest(allocation);
		processSet.insert(p);
		resourceSet.insert(r);
	}
	
	//Safety Algorithm
	bool safety(){
		std::map<Resource*, unsigned int> work ;
		std::map<Resource*, bool> finish ;
		for(std::set<Resource*>::iterator it=resourceSet.begin(); it!=resourceSet.end(); ++it){
			work[*it] = (*it)->getAvailable();
			finish[*it] = false;
		}
	}
	
	//Resource-Request Algorithm
	//Deadlock-Detection Algorithm
};

#endif
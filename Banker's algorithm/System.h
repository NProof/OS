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
	
	bool safety(); // Safety Algorithm
	void request(Process* p, std::map<Resource*, unsigned int> requisitions); //Resource-Request Algorithm
	//Deadlock-Detection Algorithm
};

bool System::safety(){
	std::map<Resource*, unsigned int> work ;
	std::map<Process*, bool> finish ;
	for(std::set<Resource*>::iterator rit=resourceSet.begin(); rit!=resourceSet.end(); ++rit){
		work[*rit] = (*rit)->getAvailable();
	}
	for(std::set<Process*>::iterator pit=processSet.begin(); pit!=processSet.end(); ++pit){
		finish[*pit] = false;
	}
	bool finded;
	do {
		finded = false;
		for(std::set<Process*>::iterator pit=processSet.begin(); pit!=processSet.end(); ++pit){
			if(!finish[*pit]){
				bool all = true;
				for(std::set<Resource*>::iterator rit=resourceSet.begin(); rit!=resourceSet.end(); ++rit){
					if(!( (*pit)->need(*rit) <= work[*rit] )){
						all = false;
						break;
					}
				}
				if(all){
					for(std::set<Resource*>::iterator rit=resourceSet.begin(); rit!=resourceSet.end(); ++rit){
						work[*rit] += (*pit)->allocation[*rit];
					}
					finded = true;
					finish[*pit] = true;
				}
			}
		}
	} while(finded);
	for(std::set<Process*>::iterator pit=processSet.begin(); pit!=processSet.end(); ++pit){
		if(!finish[*pit]){
			return false;
		}
	}
	return true;
}
 
void System::request(Process* p, std::map<Resource*, unsigned int> requisitions){
	
}

#endif
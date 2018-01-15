#ifndef SYSTEM_H
#define SYSTEM_H

#include <set>
#include <map>
#include <string>
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
	bool request(Process* p, std::map<Resource*, unsigned int> requisitions); //Resource-Request Algorithm
	bool isDeadlock(); //Deadlock-Detection Algorithm
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
 
bool System::request(Process* p, std::map<Resource*, unsigned int> requisitions){
	try{
		for(std::map<Resource*, unsigned int>::iterator rit=requisitions.begin(); rit!=requisitions.end(); ++rit){
			if(!(rit->second <= p->need(rit->first)))
				throw std::string("exceeded its maximum claim");
		}
		for(std::map<Resource*, unsigned int>::iterator rit=requisitions.begin(); rit!=requisitions.end(); ++rit){
			if(!(rit->second <= rit->first->getAvailable()))
				return false;
		}
		for(std::map<Resource*, unsigned int>::iterator it=requisitions.begin(); it!=requisitions.end(); ++it){
			it->first->beRequest(it->second);
			p->allocation[it->first] += it->second;
		}
		if(!safety()){
			for(std::map<Resource*, unsigned int>::iterator it=requisitions.begin(); it!=requisitions.end(); ++it){
				it->first->beRelease(it->second);
				p->allocation[it->first] -= it->second;
			}
			return false;
		}
		return true;
	}
	catch(const std::string error_message){
		std::cout << error_message << std::endl ;
	}	
}

bool System::isDeadlock(){
	
}

#endif
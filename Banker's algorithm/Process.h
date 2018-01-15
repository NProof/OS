#ifndef PROCESS_H
#define PROCESS_H

#include "Resource.h"
#include <map>

class Process{
public :
	std::map<Resource*, unsigned int> allocation;
	std::map<Resource*, unsigned int> max;
	
	Process(){}
	
	unsigned int need(Resource* r){
		return max[r] - allocation[r];
	}
};

#endif
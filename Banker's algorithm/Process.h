#ifndef PROCESS_H
#define PROCESS_H

#include "Resource.h"
#include <map>

class Process{
public :
	std::map<Resource*, unsigned int> allocation;
	std::map<Resource*, unsigned int> need;
	std::map<Resource*, unsigned int> max;
	
	Process(){}
};

#endif
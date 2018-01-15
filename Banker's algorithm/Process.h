#ifndef PROCESS_H
#define PROCESS_H

#include "Resource.h"
#include <map>

class Process{
	std::map<Resource*, unsigned int> allocation;
	std::map<Resource*, unsigned int> need;
	std::map<Resource*, unsigned int> max;
public :
	Process(){}
};

#endif
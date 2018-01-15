#ifndef RESOURCE_H
#define RESOURCE_H

class Resource{
	unsigned int instances;
	unsigned int available;
	
public :
	Resource(unsigned int instances){
		this->instances = instances;
		available = instances;
	}
	
	unsigned int getAvailable(){
		return available;
	}
	
	void beRequest(unsigned int assigned){
		available -= assigned;
	}
	
	void beRelease(unsigned int released){
		available += released;
	}
};

#endif
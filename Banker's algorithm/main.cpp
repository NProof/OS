#include <iostream>
#include "System.h"
#include "Process.h"
#include "Resource.h"

using namespace std;

int main(int argc, char **argv){
	System S = System();
	Process *p0 = new Process();
	Resource *r0 = new Resource();
	S.processSet.insert(p0);
	S.resourceSet.insert(r0);
	return 0;
}
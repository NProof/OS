#include <iostream>

#include "System.h"
#include "Process.h"
#include "Resource.h"

using namespace std;

int main(int argc, char **argv){
	System S = System();
	std::set<Resource*> Rs;
	System S1 = System(Rs);
	std::set<Process*> Ps;
	System S2 = System(Rs, Ps);
	return 0;
}
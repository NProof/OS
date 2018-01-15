#include <iostream>

#include "System.h"
#include "Process.h"
#include "Resource.h"

using namespace std;

int main(int argc, char **argv){
	System S = System();
	Resource* A = new Resource(10);
	Resource* B = new Resource(5);
	Resource* C = new Resource(7);
	Process* P0 = new Process();
	Process* P1 = new Process();
	Process* P2 = new Process();
	Process* P3 = new Process();
	Process* P4 = new Process();
	S.set(P0, A, 7, 0);
	S.set(P0, B, 5, 1);
	S.set(P0, C, 3, 0);
	S.set(P1, A, 3, 2);
	S.set(P1, B, 2, 0);
	S.set(P1, C, 2, 0);
	S.set(P2, A, 9, 3);
	S.set(P2, B, 0, 0);
	S.set(P2, C, 2, 2);
	S.set(P3, A, 2, 2);
	S.set(P3, B, 2, 1);
	S.set(P3, C, 2, 1);
	S.set(P4, A, 4, 0);
	S.set(P4, B, 3, 0);
	S.set(P4, C, 3, 2);
	cout << A->getAvailable() << endl;
	cout << B->getAvailable() << endl;
	cout << C->getAvailable() << endl;
	return 0;
}
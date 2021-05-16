#include <iostream>
#include <unistd.h>

using namespace std;

void test()
{
	cout<<"hello"<<endl;
}

int main()
{
	while(1) {
		test();
		sleep(1);
	}
}


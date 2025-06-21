#include "Axle.h"

int main()
{
	Axle::Log::Init();
	AX_CORE_WARN("Initialized Log!");
	int a = 5;
	AX_INFO("Hello! Var = {0}", a);

	return 0;
}
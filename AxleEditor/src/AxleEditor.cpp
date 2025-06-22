#include "Axle.h"

class AxleEditor : public Axle::Application
{
public:
	AxleEditor()
	{

	}

	~AxleEditor()
	{

	}
};

Axle::Application* Axle::CreateApplication()
{
	return new AxleEditor();
}
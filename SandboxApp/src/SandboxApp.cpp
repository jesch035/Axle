#include "Axle.h"

class SandboxApp : public Axle::Application
{
public:
	SandboxApp()
	{
		PushOverlay(new Axle::ImGuiLayer());
	}

	~SandboxApp()
	{

	}
};

Axle::Application* Axle::CreateApplication()
{
	return new SandboxApp();
}
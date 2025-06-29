#include "Axle.h"

class ExampleLayer : public Axle::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	void OnUpdate() override
	{
		AX_INFO("ExampleLayer::OnUpdate");
	}
	void OnEvent(Axle::Event& event) override
	{
		AX_TRACE("{0}", event);
	}
};

class SandboxApp : public Axle::Application
{
public:
	SandboxApp()
	{
		PushLayer(new ExampleLayer());
	}

	~SandboxApp()
	{

	}
};

Axle::Application* Axle::CreateApplication()
{
	return new SandboxApp();
}
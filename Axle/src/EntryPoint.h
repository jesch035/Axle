#pragma once

#ifdef AX_PLATFORM_WINDOWS

extern Axle::Application* Axle::CreateApplication();

int main(int argc, char** argv)
{
	Axle::Log::Init();
	auto app = Axle::CreateApplication();
	app->run();
	delete app;
}

#endif
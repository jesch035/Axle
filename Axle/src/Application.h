#pragma once
#include "Core.h"

namespace Axle
{
	class AXLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
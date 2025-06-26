#pragma once

#include <memory>

#include "Core.h"
#include "Event.h"
#include "Window.h"

namespace Axle
{
	class AXLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
#include "Application.h"
#include "WindowsWindow.h"
#include "ApplicationEvent.h"
#include "Log.h"

namespace Axle
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}
	void Application::run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
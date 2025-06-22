#include "Application.h"

#include "ApplicationEvent.h"
#include "Log.h"

namespace Axle
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::run()
	{
		WindowResizeEvent e(1280, 720);
		if(e.IsInCategory(EventCategoryApplication))
			AX_TRACE(e);

		if (e.IsInCategory(EventCategoryInput))
			AX_TRACE(e);

		while (true);
	}
}
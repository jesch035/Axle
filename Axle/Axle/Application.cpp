#include "Application.h"
#include "WindowsWindow.h"
#include "Log.h"

namespace Axle
{
	
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)	
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		m_Window->Show();
	}

	Application::~Application()
	{
	}
	
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		if (e.IsInCategory(EventCategory::EventCategoryApplication))
			AX_CORE_INFO("{0}", e);

		//AX_CORE_TRACE("{0}", e);
	}
		
	void Application::run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
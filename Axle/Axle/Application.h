#pragma once

#include "Core.h"
#include "Event.h"
#include "ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"

namespace Axle
{
	class AXLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window* GetWindow() { return m_Window.get(); }
		static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
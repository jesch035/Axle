#pragma once

#include <windows.h>

#include "Core.h"
#include "Window.h"

namespace Axle
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		
		void OnUpdate() override;
		
		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		
	private:
		void Init(const WindowProps& props);
        void Shutdown();

        HWND m_WindowHandle;
        HINSTANCE m_InstanceHandle;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
			
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
	};
}
#include <windowsx.h>

#include "WindowsWindow.h"
#include "Log.h"

#include "ApplicationEvent.h"
#include "MouseEvent.h"
#include "KeyEvent.h"

namespace Axle
{
	
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        WindowsWindow* window = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		if (!window)
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		
		WindowsWindow::WindowData& data = window->m_Data;

        switch (uMsg)
        {
		case WM_SIZE:
		{
			data.Width = LOWORD(lParam);
			data.Height = HIWORD(lParam);
			
			WindowResizeEvent event(data.Width, data.Height);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_KEYDOWN:
		{
			int repeatCount = static_cast<int>(lParam & 0xFFFF);
				
			KeyPressedEvent event(static_cast<int>(wParam), repeatCount);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_KEYUP:
		{
			KeyReleasedEvent event(static_cast<int>(wParam));
			data.EventCallback(event);
			
			return 0;
		}
		case WM_LBUTTONDOWN:
		{
			MouseButtonPressedEvent event(0);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_LBUTTONUP:
		{
			MouseButtonReleasedEvent event(0);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_RBUTTONDOWN:
		{
			MouseButtonPressedEvent event(1);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_RBUTTONUP:
		{
			MouseButtonReleasedEvent event(1);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_MOUSEWHEEL:
		{
			float yOffset = static_cast<float>(GET_WHEEL_DELTA_WPARAM(wParam)) / 120.0f;
			MouseScrollEvent event(0.0f, yOffset);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_MOUSEHWHEEL:
		{
			float xOffset = static_cast<float>(GET_WHEEL_DELTA_WPARAM(wParam)) / 120.0f;
			MouseScrollEvent event(xOffset, 0.0f);
			data.EventCallback(event);
			
			return 0;
		}
		case WM_MOUSEMOVE:
		{
			float xPos = static_cast<float>(GET_X_LPARAM(lParam));
			float yPos = static_cast<float>(GET_Y_LPARAM(lParam));
				
			MouseMovedEvent event(xPos, yPos);
			data.EventCallback(event);
			
			return 0;
		}
        case WM_CLOSE:
		{
			WindowCloseEvent event;
			data.EventCallback(event);
			
			DestroyWindow(hwnd);
			return 0;
		}
        case WM_DESTROY:
            PostQuitMessage(0);
			return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }
	
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}
	
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}
	
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	
	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		
		AX_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);
	
		m_InstanceHandle = GetModuleHandle(NULL);
		
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = m_InstanceHandle;
		wc.lpszClassName = "AxleWindowClass";
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		
		RegisterClass(&wc);
		
		m_WindowHandle = CreateWindowEx(
			0,
			wc.lpszClassName,
			m_Data.Title.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, m_Data.Width, m_Data.Height,
			NULL,
			NULL,
			m_InstanceHandle,
			NULL
		);
		
		SetWindowLongPtr(m_WindowHandle, GWLP_USERDATA, (LONG_PTR)this);
		
		SetVSync(true);		
	}
	
	void WindowsWindow::Shutdown()
	{
		DestroyWindow(m_WindowHandle);
	}
	
	void WindowsWindow::OnUpdate()
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		// implement a swapBuffers function for directX
	}
	
	void WindowsWindow::SetVSync(bool enabled)
	{
		m_Data.VSync = enabled;
		
		// implementation here once I get directX set up
	}
	
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
	
}
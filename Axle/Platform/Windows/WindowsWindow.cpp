#include "WindowsWindow.h"
#include "Log.h"

namespace Axle
{
	
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        WindowsWindow* window = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

        switch (uMsg)
        {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;

        case WM_DESTROY:
            return 0;

        default:
            break;
        }

        return DefWindowProc(hwnd, uMsg, wParam, lParam);
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
		
		ShowWindow(m_WindowHandle, SW_SHOW);
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
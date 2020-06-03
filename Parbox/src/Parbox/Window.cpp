#include "pbxpch.h"
#include "Core.h"
#include "Window.h"
#include "Log.h"
#include "Input.h"

#include "GLFW/glfw3.h"

namespace pbx
{
	Window::Window(const char* title, int screenWidth, int screenHeight)
	{
		mTitle = title;
		mScreenWidth = screenWidth;
		mScreenHeight = screenHeight;

		PBX_LOG_INFO("Creating window {0} with {1}:{2} resolution",
			mTitle, mScreenWidth, mScreenHeight);

		mGLFWwindow = glfwCreateWindow((int)mScreenWidth, (int)mScreenHeight, mTitle, NULL, NULL);
		PBX_ASSERT(mGLFWwindow, "Failed to create Window");

		glfwSetFramebufferSizeCallback(mGLFWwindow, WindowResize);

		glfwSetKeyCallback(mGLFWwindow, KeyCallback);
		glfwSetMouseButtonCallback(mGLFWwindow, MouseButtonCallback);
		glfwSetCursorPosCallback(mGLFWwindow, CursorPositionCallback);
		glfwSetScrollCallback(mGLFWwindow, ScrollCallback);

		glfwMakeContextCurrent(mGLFWwindow);

		SetVSync(true);
	}

	void Window::SetTitle(const char* title)
	{
		mTitle = title;
	}

	void Window::SetScreenWidth(int screenWidth)
	{
		mScreenWidth = screenWidth;
	}

	void Window::SetScreenHeight(int screenHeight)
	{
		mScreenHeight = screenHeight;
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void Window::Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::Clear(Color c)
	{
		glClearColor(c.r, c.g, c.b, c.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapChain()
	{
		glfwPollEvents();
		glfwSwapBuffers(mGLFWwindow);
	}

	bool Window::IsClosed()
	{
		if (pbx::GetKeyHeld(pbx::ESCAPE))
		{
			glfwSetWindowShouldClose(mGLFWwindow, true);
		}
		return glfwWindowShouldClose(mGLFWwindow);
	}

	void WindowResize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}

#pragma once

struct GLFWwindow;
struct Color;

namespace pbx
{
	class PARBOX_DLL Window
	{
	private:
		GLFWwindow* mGLFWwindow;
		const char* mTitle;
		int mScreenWidth;
		int	mScreenHeight;
	public:
		Window(const char* title, int screenWidth, int screenHeight);

		inline int GetScreenWidth() { return mScreenWidth; }
		inline int GetScreenHeight() { return mScreenHeight; }

		void SetTitle(const char* title);
		void SetScreenWidth(int screenWidth);
		void SetScreenHeight(int screenHeight);

		void SetVSync(bool enabled);

		void Clear(float r, float g, float b, float a = 255.0f);
		void Clear(Color c);

		void SwapChain();
		bool IsClosed();
	};

	void WindowResize(GLFWwindow* window, int width, int height);
}
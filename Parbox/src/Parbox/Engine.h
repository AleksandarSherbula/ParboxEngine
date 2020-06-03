#pragma once

#include "Window.h"
#include "Renderer.h"

namespace pbx
{
	class PARBOX_DLL Engine
	{
	private:
		static Engine* instance;
		Window* mWindow = nullptr;
	public:
		Engine();
		virtual ~Engine();

		void SetWindow(const char* title, int screenWidth, int screenHeight);
		void Clear(float r, float g, float b, float a = 255.0f);
		void Clear(Color c);

		virtual void Create() = 0;
		virtual void Update() = 0;
		virtual void Destroy() = 0;;

		void Run();
	};
};
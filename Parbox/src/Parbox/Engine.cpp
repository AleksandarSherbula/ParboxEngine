#include "pbxpch.h"
#include "Core.h"
#include "Engine.h"
#include "Log.h"
#include "Input.h"
#include "OpenGL_Log.h"
#include "Shader.h"
#include "Texture.h"
#include "Renderer.h"
#include "Math.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace pbx
{	
	Engine* Engine::instance = nullptr;
	

	Engine::Engine()
	{
		Log::Init();

		
		PBX_ASSERT(!instance, "Engine object has already been made");
		instance = this;		
	}

	Engine::~Engine()
	{
		delete mWindow;
		glfwTerminate();
	}

	void Engine::SetWindow(const char* title, int screenWidth, int screenHeight)
	{
		int success = glfwInit();
		PBX_ASSERT(success, "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = new Window(title, screenWidth, screenHeight);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PBX_ASSERT(status, "Failed to initialize Glad!");	
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	}

	void Engine::Clear(float r, float g, float b, float a)
	{
		if (mWindow != nullptr)
			mWindow->Clear(r, g, b, a);
	}

	void Engine::Clear(Color c)
	{
		if (mWindow != nullptr)
			mWindow->Clear(c);
	}

	void Engine::Run()
	{
		Create();
		if (mWindow != nullptr)
		{
			//float verticies[] =
			//{
			//	0.0f, 0.0f, 0.0f, 0.0f,
			//	1.0f, 0.0f, 1.0f, 0.0f,
			//	1.0f, 1.0f, 1.0f, 1.0f,
			//
			//	1.0f, 1.0f, 1.0f, 1.0f,
			//	0.0f, 1.0f, 0.0f, 1.0f,
			//	0.0f, 0.0f, 0.0f, 0.0f
			//};
			//
			//unsigned int vao;
			//GLCall(glGenVertexArrays(1, &vao));
			//GLCall(glBindVertexArray(vao));
			//
			//unsigned int vbo;
			//GLCall(glGenBuffers(1, &vbo));
			//GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
			//GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 4 * sizeof(float), verticies, GL_STATIC_DRAW));
			//
			//GLCall(glEnableVertexAttribArray(0));
			//GLCall(glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0));

			//Shader shader;			
			//shader.setUniform4f("uColor", 255.0f, 255.0f, 255.0f, 255.0f);
			//Texture texture("res/images/wall.jpg");
			//texture.Bind(0);
			//shader.setUniformInteger("uTexture", 0);

			
			while (!mWindow->IsClosed())
			{
				Input::Scan();				
				Update();
				
				//GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
				mWindow->SwapChain();
			}
		}
		else
		{
			PBX_LOG_WARN("Window was not created. Use SetWindow().");
			while (true)
			{
				Input::Scan();

				Update();
			}
		}
		Destroy();
	}
}

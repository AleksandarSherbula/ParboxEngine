#include "pbxpch.h"
#include "OpenGL_Log.h"
#include "Log.h"
#include "glad/glad.h"


void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	if (GLenum errorCode = glGetError())
	{
		const char* error = "NO ERROR";
		switch (errorCode)
		{
		case GL_INVALID_ENUM:					error = "INVALID ENUM";						break;
		case GL_INVALID_VALUE:					error = "INVALID VALUE";					break;
		case GL_INVALID_OPERATION:				error = "INVALID OPERATION";				break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:	error = "INVALID FRAMEBUFFER OPERATION";	break;
		case GL_OUT_OF_MEMORY:					error = "OUT OF MEMORY";					break;
		}

		PBX_LOG_ERROR("[OpenGL]: {0}, {1}, {2}, {3}", error, function, file, line);

		return false;
	}

	return true;
}

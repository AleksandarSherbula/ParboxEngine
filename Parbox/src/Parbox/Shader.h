#pragma once

#include "glad/glad.h"
#include "Math.h"
#include <string>

namespace pbx
{
	class PARBOX_DLL Shader
	{
	private:
		unsigned int mID;
		std::string mVertexSource;
		std::string mPixelSource;
	public:
		Shader();
		~Shader();

		void Bind();
		void Unbind();

		void setUniformInteger(const std::string& name, int value);
		void setUniformFloat(const std::string& name, float value);
		void setUniform2f(const std::string& name, float x, float y);
		void setUniform3f(const std::string& name, float x, float y, float z);
		void setUniform4f(const std::string& name, float r, float g, float b, float a);
		void setUniformMatrix4fv(const std::string& name, Matrix4& matrix);
	private:
		void CreateShader(const std::string& vertexSource, const std::string& pixelSource);
		unsigned int CompileShader(GLenum type, const std::string& source);
	};
}
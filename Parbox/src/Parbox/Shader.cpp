#include "pbxpch.h"
#include "Shader.h"
#include "OpenGL_Log.h"

namespace pbx
{
	Shader::Shader()
	{
		//Note to self:
		//After adding projection matrix, object needs to be scaled.
		mVertexSource = R"(
		#version 330 core

		layout(location = 0) in vec4 vertex;

		out vec2 vTexCoord;
		uniform mat4 uModel;
		uniform mat4 uProjection;

		void main()
		{
			vTexCoord = vertex.zw;
			gl_Position = uProjection * uModel * vec4(vertex.xy, 0.0, 1.0);
		};
		)";

		mPixelSource = R"(
		#version 330 core

		out vec4 color;
		in vec2 vTexCoord;

		uniform vec4 uColor;
		uniform sampler2D uTexture;

		void main()
		{
			color = texture(uTexture, vTexCoord) * uColor;
		}
		)";
		
		CreateShader(mVertexSource, mPixelSource);
	}

	Shader::~Shader()
	{
		GLCall(glDeleteProgram(mID));
	}

	void Shader::Bind()
	{
		GLCall(glUseProgram(mID));
	}

	void Shader::Unbind()
	{
		GLCall(glUseProgram(0));
	}

	void Shader::setUniformInteger(const std::string& name, int value)
	{
		GLCall(glUniform1i(glGetUniformLocation(mID, name.c_str()), value));
	}

	void Shader::setUniformFloat(const std::string& name, float value)
	{
		GLCall(glUniform1f(glGetUniformLocation(mID, name.c_str()), value));
	}

	void Shader::setUniform2f(const std::string& name, float x, float y)
	{
		GLCall(glUniform2f(glGetUniformLocation(mID, name.c_str()), x, y));
	}

	void Shader::setUniform3f(const std::string& name, float x, float y, float z)
	{
		GLCall(glUniform3f(glGetUniformLocation(mID, name.c_str()), x, y, z));
	}

	void Shader::setUniform4f(const std::string& name, float r, float g, float b, float a)
	{
		GLCall(glUniform4f(glGetUniformLocation(mID, name.c_str()), r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f));
	}

	void Shader::setUniformMatrix4fv(const std::string& name, Matrix4& matrix)
	{
		GLCall(glUniformMatrix4fv(glGetUniformLocation(mID, name.c_str()), 1, GL_FALSE, matrix.mElements));
	}

	void Shader::CreateShader(const std::string& vertexSource, const std::string& pixelSource)
	{
		GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
		GLuint pixelShader = CompileShader(GL_FRAGMENT_SHADER, pixelSource);

		GLCall(mID = glCreateProgram());
		GLCall(glAttachShader(mID, vertexShader));
		GLCall(glAttachShader(mID, pixelShader));

		GLCall(glLinkProgram(mID));
		GLCall(glDeleteShader(vertexShader));
		GLCall(glDeleteShader(pixelShader));

		GLint result;
		GLCall(glGetProgramiv(mID, GL_LINK_STATUS, &result));
		if (!result)
		{
			GLsizei logLength = 0;
			GLchar message[1024];
			GLCall(glGetProgramInfoLog(mID, 1024, &logLength, message));
			std::cout << "Failed to link Shader program \n";
			std::cout << message << "\n";
		}
		GLCall(glUseProgram(mID));
	}

	unsigned int Shader::CompileShader(GLenum type, const std::string& source)
	{
		GLCall(GLuint shader = glCreateShader(type));
		const char* src = source.c_str();
		GLCall(glShaderSource(shader, 1, &src, NULL));
		GLCall(glCompileShader(shader));

		GLint result;
		GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
		if (!result)
		{
			GLsizei logLength = 0;
			GLchar message[1024];
			GLCall(glGetShaderInfoLog(shader, 1024, &logLength, message));
			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "pixel")
				<< " shader." << std::endl;
			std::cout << message << std::endl;
			GLCall(glDeleteShader(shader));
		}

		return shader;
	}
}

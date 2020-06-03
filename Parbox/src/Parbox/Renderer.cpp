#include "pbxpch.h"
#include "Renderer.h"
#include "Log.h"
#include "OpenGL_Log.h"

namespace pbx
{
	Sprite::Sprite(const std::string& filepath)
	{
		mFilePath = filepath;

		Matrix4 projection = Matrix4::orthographic(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
		mShader.setUniformMatrix4fv("uProjection", projection);

		float vertices[] =
		{
			//position		//texture
			0.0f, 0.0f,		0.0f, 0.0f,
			1.0f, 0.0f,		1.0f, 0.0f,
			1.0f, 1.0f,		1.0f, 1.0f,

			1.0f, 1.0f,		1.0f, 1.0f,
			0.0f, 1.0f,		0.0f, 1.0f,
			0.0f, 0.0f,		0.0f, 0.0f
		};

		GLCall(glGenVertexArrays(1, &mVAO));
		GLCall(glBindVertexArray(mVAO));

		unsigned int vbo;
		GLCall(glGenBuffers(1, &vbo));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
		GLCall(glBufferData(GL_ARRAY_BUFFER, 6 * 4 * sizeof(float), vertices, GL_STATIC_DRAW));

		GLCall(glEnableVertexAttribArray(0));
		GLCall(glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
		GLCall(glBindVertexArray(0));

		mTexture.Generate(mFilePath);
	}

	void Sprite::Draw(Vector2i position, float rotate, Vector2i size, Color color)
	{
		mShader.Bind();
		Matrix4 model;
		model.translate(Vector3((float)position.x, (float)position.y, 0.0f));

		model.translate(Vector3(0.5f * size.x, 0.5f * size.y, 0.0f));
		model.rotate(rotate, Vector3(0.0f, 0.0f, 1.0f));
		model.translate(Vector3(-0.5f * size.x, -0.5f * size.y, 0.0f));

		model.scale(Vector3((float)size.x, (float)size.y, 1.0f));

		mShader.setUniformMatrix4fv("uModel", model);
		mShader.setUniform4f("uColor", color.r, color.g, color.b, color.a);

		//mTexture.Bind(0);

		GLCall(glBindVertexArray(mVAO));
		GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
		GLCall(glBindVertexArray(0));
	}
}

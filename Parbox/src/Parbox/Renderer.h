#pragma once

#include "Shader.h"
#include "Texture.h"
#include "Parbox/math/Vector2.h"

namespace pbx
{
	class PARBOX_DLL Sprite
	{
	private:
		Shader mShader;
		Texture mTexture;
		std::string mFilePath;
		Vector2i mPosition = {0};
		float rotation = 0.0f;
		Vector2i mRotation = {0};
		Color mColor = pbx::WHITE;
		unsigned int mVAO;
	public:
		Sprite(const std::string& filepath);

		void Draw(Vector2i position, float rotate, Vector2i size, Color color);
	};


	class Shape
	{
	protected:
		Shader mShader;
	};
}
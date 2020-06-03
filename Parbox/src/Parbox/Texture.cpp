#include "pbxpch.h"
#include "Texture.h"
#include "OpenGL_Log.h"

#include "../stb_image/stb_image.h"

namespace pbx
{
	Texture::Texture()
	{
	}

	void Texture::Generate(const std::string& filepath)
	{
		mID = 0;
		mFilePath = filepath;
		mLocalBuffer = nullptr;
		mWidth = 0;
		mHeight = 0;
		mBPP = 0;

		stbi_set_flip_vertically_on_load(1);

		mLocalBuffer = stbi_load(filepath.c_str(), &mWidth, &mHeight, &mBPP, 4);

		GLCall(glGenTextures(1, &mID));
		GLCall(glBindTexture(GL_TEXTURE_2D, mID));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mLocalBuffer));
		GLCall(glGenerateMipmap(GL_TEXTURE_2D));

		if (mLocalBuffer)
		{			
			stbi_image_free(mLocalBuffer);
		}
	}

	Texture::~Texture()
	{
		GLCall(glDeleteTextures(1, &mID));
	}
	
	void Texture::Bind(unsigned int slot)
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, mID));
	}
	
	void Texture::Unbind()
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}
}
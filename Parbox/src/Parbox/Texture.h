#pragma once

#include <string>

namespace pbx
{
	class PARBOX_DLL Texture
	{
	private:
		unsigned int mID;
		std::string mFilePath;
		unsigned char* mLocalBuffer;
		int mWidth, mHeight, mBPP;
	public:
		Texture();
		void Generate(const std::string& filepath);
		~Texture();

		void Bind(unsigned int slot = 0);
		void Unbind();
	};
}
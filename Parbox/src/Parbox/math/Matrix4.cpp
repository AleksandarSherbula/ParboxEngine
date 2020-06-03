#include "pbxpch.h"
#include "Matrix4.h"
#include "Parbox/Log.h"

namespace pbx
{
	Matrix4::Matrix4()
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			mElements[i] = 0.0f;
		}
	
		mElements[0] =  1.0f;
		mElements[5] =  1.0f;
		mElements[10] = 1.0f;
		mElements[15] = 1.0f;
	}

	Matrix4::Matrix4(float* elements)
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			mElements[i] = elements[i];
		}
	}

	Matrix4 Matrix4::operator*(const Matrix4& other) const
	{
		Matrix4 result;

		const float* a = mElements;
		const float* b = other.mElements;
		float* c = result.mElements;

		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				// column * row
				c[x * 4 + y] =
					a[0 * 4 + y] * b[x * 4 + 0] +
					a[1 * 4 + y] * b[x * 4 + 1] +
					a[2 * 4 + y] * b[x * 4 + 2] +
					a[3 * 4 + y] * b[x * 4 + 3];
			}
		}

		for (int i = 0; i < 4 * 4; i++)
		{
			result.mElements[i] = c[i];
		}

		return result;
	}

	Matrix4& Matrix4::operator*=(const Matrix4& other)
	{
		*this = *this * other;
		return *this;
	}

	Matrix4& Matrix4::translate(const Vector3f& translation)
	{
		Matrix4 translationMat;

		translationMat.mElements[3 * 4 + 0] = translation.x;
		translationMat.mElements[3 * 4 + 1] = translation.y;
		translationMat.mElements[3 * 4 + 2] = translation.z;

		*this *= translationMat;

		return *this;
	}

	Matrix4& Matrix4::rotate(float angle, const Vector3f& axis)
	{
		float r = angle;
		float x = axis.x;
		float y = axis.y;
		float z = axis.z;
		float omc = 1.0f - cos(r);

		float c = cos(angle);
		float s = sin(angle);

		Matrix4 rotationMat;

		rotationMat.mElements[0 + 0 * 4] = c + x * x * omc;
		rotationMat.mElements[1 + 0 * 4] = x * y * omc - z * s;
		rotationMat.mElements[2 + 0 * 4] = z * x * omc + y * s;

		rotationMat.mElements[0 + 1 * 4] = x * y * omc + z * s;
		rotationMat.mElements[1 + 1 * 4] = c + y * y * omc;
		rotationMat.mElements[2 + 1 * 4] = z * y * omc - x * s;

		rotationMat.mElements[0 + 2 * 4] = x * z * omc - y * s;
		rotationMat.mElements[1 + 2 * 4] = y * z * omc + x * s;
		rotationMat.mElements[2 + 2 * 4] = c + z * z * omc;

		*this *= rotationMat;

		return *this;
	}

	Matrix4& Matrix4::scale(const Vector3f& scaler)
	{
		Matrix4 scaleMat;

		scaleMat.mElements[0 * 4 + 0] = scaler.x;
		scaleMat.mElements[1 * 4 + 1] = scaler.y;
		scaleMat.mElements[2 * 4 + 2] = scaler.z;\

		*this *= scaleMat;

		return *this;
	}

	void Matrix4::print()
	{
		for (int i = 0; i < 4; i++)
			std::cout << "|" << mElements[0 + i * 4] << " " << mElements[1 + i * 4] << " " <<
			mElements[2 + i * 4] << " " << mElements[3 + i * 4] << "| \n";
		std::cout << "\n";
	}

	//Matrix4::orthographic(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float fNear, float fFar)
	{
		Matrix4 ortho;

		ortho.mElements[0 * 4 + 0] = 2.0f / (right - left);
		ortho.mElements[1 * 4 + 1] = 2.0f / (top - bottom);
		ortho.mElements[2 * 4 + 2] = -2.0f / (fFar - fNear);

		ortho.mElements[3 * 4 + 0] = -1 * ((right + left) / (right - left));
		ortho.mElements[3 * 4 + 1] = -1 * ((top + bottom) / (top - bottom));
		ortho.mElements[3 * 4 + 2] = -1 * ((fFar + fNear) / (fFar - fNear));

		return ortho;
	}
}

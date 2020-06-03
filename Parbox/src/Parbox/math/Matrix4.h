#pragma once

#include "Vector3.h"

namespace pbx
{
	struct PARBOX_DLL Matrix4
	{
		float mElements[4 * 4] = {0};

		Matrix4();
		Matrix4(float* elements);

		Matrix4 operator*(const Matrix4& other) const;
		Matrix4& operator*=(const Matrix4& other);

		Matrix4& translate(const Vector3f& translation);
		Matrix4& rotate(float angle, const Vector3f& axis);
		Matrix4& scale(const Vector3f& scaler);

		void print();

		//Near and Far variables cannot be named as near and far, because there are macros
		//in minwindef.h (assumed to be included in <math> library) called near and far,
		//so they are named as fNear and fFar.
		static Matrix4 orthographic(float left, float right, float bottom, float top, float fNear, float fFar);
	};
}
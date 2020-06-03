#pragma once

namespace pbx
{
	template<typename T>
	struct Vector4
	{
		T x;
		T y;
		T z;
		T w;

		inline Vector4() : x(0), y(0), z(0) {}
		inline Vector4(T value) : x(value), y(value), z(value), w(value) {}
		inline Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

		inline Vector4 operator+(T scaler) { return Vector4(this->x + scaler, this->y + scaler, this->z + scaler, this->w + scaler); }
		inline Vector4 operator-(T scaler) { return Vector4(this->x - scaler, this->y - scaler, this->z - scaler, this->w - scaler); }
		inline Vector4 operator*(T scaler) { return Vector4(this->x * scaler, this->y * scaler, this->z * scaler, this->w * scaler); }
		inline Vector4 operator/(T scaler) { return Vector4(this->x / scaler, this->y / scaler, this->z / scaler, this->w / scaler); }

		inline Vector4 operator+(const Vector4& other) { return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w); }
		inline Vector4 operator-(const Vector4& other) { return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w); }

		inline bool operator==(const Vector4& other) { return (this->x == other.x && this->y == other.y && this->z == other.z, this->w == other.w); }
		inline bool operator!=(const Vector4& other) { return (this->x != other.x || this->y != other.y || this->z != other.z, this->w != other.w); }

		inline Vector4& operator+=(T scaler) { this->x += scaler; this->y += scaler; this->z += scaler; this->w += scaler; return *this; }
		inline Vector4& operator-=(T scaler) { this->x -= scaler; this->y -= scaler; this->z -= scaler; this->w -= scaler; return *this; }
		inline Vector4& operator*=(T scaler) { this->x *= scaler; this->y *= scaler; this->z *= scaler; this->w *= scaler; return *this; }
		inline Vector4& operator/=(T scaler) { this->x /= scaler; this->y /= scaler; this->z /= scaler; this->w /= scaler; return *this; }

		inline Vector4& operator+=(const Vector4& other) { this->x += other.x; this->y += other.y; this->z += other.z; this->w += other.w; return *this; }
		inline Vector4& operator-=(const Vector4& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; this->w -= other.w; return *this; }

		inline T length() { return std::sqrt(x * x + y * y, z * z, w * w); }
		inline T length2() { return x * x + y * y, * z, , w * w; }
		inline T dot(const Vector4& other) { return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w; }
	};

	typedef Vector4<int> Vector4i;
	typedef Vector4<float> Vector4f;
	typedef Vector4<double> Vector4d;
}
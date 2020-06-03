#pragma once

namespace pbx
{
	template<typename T>
	struct Vector3
	{
		T x;
		T y;
		T z;

		inline Vector3() : x(0), y(0), z(0) {}
		inline Vector3(T value) : x(value), y(value), z(value) {}
		inline Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

		inline Vector3 operator+(T scaler) { return Vector3(this->x + scaler, this->y + scaler, this->z + scaler); }
		inline Vector3 operator-(T scaler) { return Vector3(this->x - scaler, this->y - scaler, this->z - scaler); }
		inline Vector3 operator*(T scaler) { return Vector3(this->x * scaler, this->y * scaler, this->z * scaler); }
		inline Vector3 operator/(T scaler) { return Vector3(this->x / scaler, this->y / scaler, this->z / scaler); }

		inline Vector3 operator+(const Vector3& other) { return Vector3(this->x + other.x, this->y + other.y, this->z + other.z); }
		inline Vector3 operator-(const Vector3& other) { return Vector3(this->x - other.x, this->y - other.y, this->z - other.z); }

		inline bool operator==(const Vector3& other) { return (this->x == other.x && this->y == other.y && this->z == other.z); }
		inline bool operator!=(const Vector3& other) { return (this->x != other.x || this->y != other.y || this->z != other.z); }

		inline Vector3& operator+=(T scaler) { this->x += scaler; this->y += scaler; this->z += scaler; return *this; }
		inline Vector3& operator-=(T scaler) { this->x -= scaler; this->y -= scaler; this->z -= scaler; return *this; }
		inline Vector3& operator*=(T scaler) { this->x *= scaler; this->y *= scaler; this->z *= scaler; return *this; }
		inline Vector3& operator/=(T scaler) { this->x /= scaler; this->y /= scaler; this->z /= scaler; return *this; }

		inline Vector3& operator+=(const Vector3& other) { this->x += other.x; this->y += other.y; this->z += other.z; return *this; }
		inline Vector3& operator-=(const Vector3& other) { this->x -= other.x; this->y -= other.y; this->z -= other.z; return *this; }

		inline T length() { return std::sqrt(x * x + y * y, z * z); }
		inline T length2() { return x * x + y * y, z* z; }
		inline T dot(const Vector3& other) { return this->x * other.x + this->y * other.y + this->z * other.z; }

		/*
		x	other.x		y * other.z - z * other.y
		y	other.y   = z * other.x - x * other.z
		z	other.z		x * other.y - y * other.x
		*/
		inline Vector3& cross(const Vector3& other) { this->x = y * other.z - z * other.y; this->y = z * other.x - x * other.z;this->z = x * other.y - y * other.x; return *this; }			
	};

	typedef Vector3<int> Vector3i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;

}
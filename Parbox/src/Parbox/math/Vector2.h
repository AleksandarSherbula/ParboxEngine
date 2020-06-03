#pragma once

namespace pbx
{
	template<typename T>
	struct Vector2
	{
		T x;
		T y;

		inline Vector2() : x(0), y(0) {}
		inline Vector2(T value) : x(value), y(value) {}
		inline Vector2(T x, T y) : x(x), y(y) {}

		inline Vector2 operator+(T scaler) { return Vector2(this->x + scaler, this->y + scaler); }
		inline Vector2 operator-(T scaler) { return Vector2(this->x - scaler, this->y - scaler); }
		inline Vector2 operator*(T scaler) { return Vector2(this->x * scaler, this->y * scaler); }
		inline Vector2 operator/(T scaler) { return Vector2(this->x / scaler, this->y / scaler); }

		inline Vector2 operator+(const Vector2& other) { return Vector2(this->x + other.x, this->y + other.y); }
		inline Vector2 operator-(const Vector2& other) { return Vector2(this->x - other.x, this->y - other.y); }

		inline bool operator==(const Vector2& other) { return (x == other.x && y == other.y); }
		inline bool operator!=(const Vector2& other) { return (x != other.x || y != other.y); }

		inline Vector2& operator+=(T scaler) { this->x += scaler; this->y += scaler; return *this; }
		inline Vector2& operator-=(T scaler) { this->x -= scaler; this->y -= scaler; return *this; }
		inline Vector2& operator*=(T scaler) { this->x *= scaler; this->y *= scaler; return *this; }
		inline Vector2& operator/=(T scaler) { this->x /= scaler; this->y /= scaler; return *this; }

		inline Vector2& operator+=(const Vector2& other) { this->x+=other.x; this->y+=other.y; return *this; }
		inline Vector2& operator-=(const Vector2& other) { this->x-=other.x; this->y-=other.y; return *this; }

		inline T length() { return std::sqrt(x * x + y * y); }
		inline T length2() { return x * x + y * y; }
		inline T dot(const Vector2& other) { return this->x * other.x + this->y * other.y; }
	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;
}
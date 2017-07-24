
#pragma once

namespace Math
{

	struct Vector3
	{

		Vector3(float InitialX, float InitialY, float InitialZ);

		float X, Y, Z;

		Vector3 operator+(Vector3 ToAdd);
		Vector3 operator-(Vector3 ToSubtract);
		Vector3 operator*(float ToMultiply);
		Vector3 operator/(float ToDivide);
		void operator+=(Vector3 ToAdd);
		void operator-=(Vector3 ToSubtract);
		void operator*=(float ToMultiply);
		void operator/=(float ToDivide);
		Vector3 operator-();
		float operator*(Vector3 ToDot); // Dot product

		float Dot(Vector3 ToDot);
		Vector3 Cross(Vector3 ToCross);
		float Magnitude();
		float Distance(Vector3 OtherVector);
		Vector3 Normalize();
		float Angle(Vector3 OtherVector);

	};

	Vector3 operator*(float Scalar, Vector3 Vector); // Communative scalar multiplication

}
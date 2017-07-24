
#include <cmath>

#include "Vector3.h"

Math::Vector3::Vector3(float InitialX, float InitialY, float InitialZ)
{

	X = InitialX;
	Y = InitialY;
	Z = InitialZ;

}

Math::Vector3 Math::Vector3::operator+(Vector3 ToAdd)
{
	
	return Vector3(X + ToAdd.X, Y + ToAdd.Y, Z + ToAdd.Z);

}

Math::Vector3 Math::Vector3::operator-(Vector3 ToSubtract)
{

	return Vector3(X - ToSubtract.X, Y - ToSubtract.Y, Z - ToSubtract.Z);

}

Math::Vector3 Math::Vector3::operator*(float ToMultiply)
{

	return Vector3(ToMultiply * X, ToMultiply * Y, ToMultiply * Z);

}

Math::Vector3 Math::Vector3::operator/(float ToDivide)
{

	return Vector3(X / ToDivide, Y / ToDivide, Z / ToDivide);

}

void Math::Vector3::operator+=(Vector3 ToAdd)
{

	*this = *this + ToAdd;

}

void Math::Vector3::operator-=(Vector3 ToSubtract)
{

	*this = *this - ToSubtract;

}

void Math::Vector3::operator*=(float ToMultiply)
{

	*this = *this * ToMultiply;

}

void Math::Vector3::operator/=(float ToDivide)
{

	*this = *this / ToDivide;

}

Math::Vector3 Math::Vector3::operator-()
{

	return Vector3(-X, -Y, -Z);

}

float Math::Vector3::operator*(Vector3 ToDot)
{

	return (X * ToDot.X) + (Y * ToDot.Y) + (Z * ToDot.Z);

}

float Math::Vector3::Dot(Vector3 ToDot)
{

	return (X * ToDot.X) + (Y * ToDot.Y) + (Z * ToDot.Z);

}

Math::Vector3 Math::Vector3::Cross(Vector3 ToCross)
{

	return Vector3
	(
	
		(Y * ToCross.Z) - (Z * ToCross.Y),
		(Z * ToCross.X) - (X * ToCross.Z),
		(X * ToCross.Y) - (Y * ToCross.X)
	
	);

}

float Math::Vector3::Magnitude()
{

	return float(std::sqrt(std::pow(X, 2.0) + std::pow(Y, 2.0) + std::pow(Z, 2.0)));

}

float Math::Vector3::Distance(Vector3 OtherVector)
{

	return (OtherVector - *this).Magnitude();

}

Math::Vector3 Math::Vector3::Normalize()
{

	return *this / Magnitude();

}

float Math::Vector3::Angle(Vector3 OtherVector)
{

	return std::acos((*this * OtherVector) / (Magnitude() * OtherVector.Magnitude()));

}

Math::Vector3 Math::operator*(float Scalar, Vector3 Vector)
{

	return Vector * Scalar;

}
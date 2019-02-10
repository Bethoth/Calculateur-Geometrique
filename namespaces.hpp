#pragma once

#include <iostream>
#include <cmath>

template <typename T>
constexpr T pi = static_cast<T>(3.14159265358979323846L);

namespace area {
	double rectangle(double length, double width) {
		return length * width;
	}

	double square(double side) {
		return side * side;
	}

	double disk(double radius)
	{
		return (radius * radius) * pi<float>;
	}

	double parallelogram(double base, double height)
	{
		return base * height;
	}

	double triangle(double base, double height)
	{
		return base * height / 2;
	}

	double trapeze(double firstBase, double secondBase, double height)
	{
		return ((firstBase + secondBase) * height) / 2;
	}

	double diamond(double firstDiagonal, double secondDiagonal)
	{
		return firstDiagonal * secondDiagonal / 2;
	}

	double sphere(double radius)
	{
		return (radius * radius) * (pi<float> * 4);
	}

	double cone(double radius, double height)
	{
		return std::sqrt((radius * radius) + (height * height)) * pi<float> * radius;
	}

	double cube(double arete)
	{
		return (arete * arete) * 6;
	}

	double rectangleCuboid(double length, double width, double height)
	{
		return (2 * length * width) + (2 * length * height) + (2 * width * height);
	}

	double cylinder(double radius, double height)
	{
		return 2 * pi<float> * radius * height;
	}

	double squareBasedPyramid(double side, double height) {
		return (side * 4) * std::sqrt((height * height) + (side / 2) * (side / 2)) / 2;
	}
}

namespace perimeter {
	double rectangle(double length, double width)
	{
		return (length * 2) + (width * 2);
	}

	double square(double side)
	{
		return side * 4;
	}

	double circle(double diameter)
	{
		return pi<float> * diameter;
	}

	double parallelogram(double length, double width)
	{
		return length * 2 + width * 2;
	}

	double triangle(double base, double firstSide, double secondSide)
	{
		return base + firstSide + secondSide;
	}

	double trapeze(double firstBase, double secondBase, double firstSide, double secondSide)
	{
		return firstBase + secondBase + firstSide + secondSide;
	}

	double diamond(double side)
	{
		return side * 4;
	}
}

namespace volume {
	double cube(double arete)
	{
		return std::pow(arete, 3);
	}

	double rectangleCuboid(double length, double width, double height)
	{
		return length * width * height;
	}

	double cylinder(double radius, double height)
	{
		return pi<float> * (radius * radius) * height;
	}

	double cone(double radius, double height)
	{
		return (pi<float> * (radius * radius) * height) / 3;
	}

	double squareBasedPyramid(double side, double height)
	{
		return ((side * side) * height) / 3;
	}

	double rectangleBasedPyramid(double length, double width, double height)
	{
		return ((length * width) * height) / 3;
	}

	double sphere(double radius)
	{
		return (4.0 / 3.0) * pi<float> * std::pow(radius, 3);
	}
}

namespace theorems {
	double pythagoreOtherSide(double hypotenuse, double knownSide)
	{
		return std::sqrt(std::pow(hypotenuse, 2) - std::pow(knownSide, 2));
	}

	double thalesWithUnknownNumerator(double knownFractionNumerator, double knownFractionDenominator, double knownDenominator)
	{
		return (knownFractionNumerator * knownDenominator) / knownFractionDenominator;
	}

	double thalesWithUnknownDenominator(double knownFractionNumerator, double knownFractionDenominator, double knownNumerator)
	{
		return (knownFractionDenominator * knownNumerator) / knownFractionNumerator;
	}
}
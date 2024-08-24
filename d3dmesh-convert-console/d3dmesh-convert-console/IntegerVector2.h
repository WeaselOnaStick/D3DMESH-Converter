#pragma once
#ifndef INTEGER_VECTOR_2_H
#define INTEGER_VECTOR_2_H

//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INCLUDED DEPENDENCIES |||||||||||||||||||||||||||||

//Custom
#include "BinarySerialization.h"
#include "BinaryDeserialization.h"
#include "Json.h"

//||||||||||||||||||||||||||||| INTEGER VECTOR 2 |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INTEGER VECTOR 2 |||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||| INTEGER VECTOR 2 |||||||||||||||||||||||||||||
//NOTE: This is NOT an actual data structures serialized in a telltale file.
//However there are cases where the vector types do hold integer data per component.

/// <summary>
/// [8 bytes] Vector with 2 int32 components (x, y)
/// </summary>
struct IntegerVector2
{
	/// <summary>
	/// [4 bytes] x (horizontal) component.
	/// </summary>
	int x;

	/// <summary>
	/// [4 bytes] y (vertical) component.
	/// </summary>
	int y;

	IntegerVector2()
	{
		x = 0;
		y = 0;
	};

	IntegerVector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	};

	IntegerVector2(std::ifstream* inputFileStream)
	{
		x = ReadInt32FromBinary(inputFileStream); //[4 BYTES]
		y = ReadInt32FromBinary(inputFileStream); //[4 BYTES]
	};

	void BinarySerialize(std::ofstream* outputFileStream)
	{
		WriteInt32ToBinary(outputFileStream, x); //[4 BYTES]
		WriteInt32ToBinary(outputFileStream, y); //[4 BYTES]
	};

	//||||||||||||||||||||||||||||| TO STRING |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| TO STRING |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| TO STRING |||||||||||||||||||||||||||||

	std::string ToString() const
	{
		return "[IntegerVector2] x:" + std::to_string(x) + " y: " + std::to_string(y);
	};

	//||||||||||||||||||||||||||||| JSON |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| JSON |||||||||||||||||||||||||||||
	//||||||||||||||||||||||||||||| JSON |||||||||||||||||||||||||||||
	//REFERENCE - https://json.nlohmann.me/features/arbitrary_types/
	//NOTE: These macros are limited to 64 members at most (if there are more you'll need to implement manually.

	//These are supposed to be inside the class/struct
	//NLOHMANN_DEFINE_TYPE_INTRUSIVE(...) //throws exceptions when there are missing values
	//NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(...) //will not throw exceptions, fills in values with default constructor
	NLOHMANN_ORDERED_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(IntegerVector2, x, y)
};

#endif
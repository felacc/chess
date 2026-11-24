#pragma once
#include <string>
class ISerializable
{
public:
	virtual ~ISerializable() = default;

	virtual std::string toString() const = 0; 
};


#pragma once
#include "CircularQueue.h"

class CircularDeque : public CircularQueue{
public:
	CircularDeque();
	~CircularDeque();
	
	void AddFront(const int& val);
	void AddRear(const int& val);

	const int& DeleteFront();
	const int& DeleteRear();

	const int& GetFront();
	const int& GetRear();

	void Display() const;
};


#pragma once
#include "Location2D.h"
class LocationNode : public Location2D{
public:
	explicit LocationNode(const int& r = 0, const int& c = 0);
	~LocationNode();

	void SetLink(LocationNode* loc);
	LocationNode* GetLink();

private:
	LocationNode* mLink;
};
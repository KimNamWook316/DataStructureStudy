#include "LocationNode.h"

LocationNode::LocationNode(const int& r, const int& c) 
	: Location2D(r, c), mLink(nullptr){
}

LocationNode::~LocationNode() {
}

void LocationNode::SetLink(LocationNode* loc) {
	mLink = loc;
}

LocationNode* LocationNode::GetLink() {
	return mLink;
}

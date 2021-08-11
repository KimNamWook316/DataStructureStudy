#pragma once
struct Customer{
	int id;
	int tArrival;
	int tService;
	Customer(const int& i = 0, const int& tArr = 0, const int& tServ = 0)
		: id(i), tArrival(tArr), tService(tServ){
	}
};
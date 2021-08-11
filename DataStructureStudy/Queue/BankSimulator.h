#pragma once
#include "CustomerQueue.h"

class BankSimulator {
public:
	explicit BankSimulator();
	void ReadSimulationParameters();
	void Run();
	void PrintStat();

private:
	double random();
	bool isNewCustomer();
	int randServiceTime();
	void insertCustomer(int arrivalTime);

private:
	int		nSimulation;
	double  probArrival;
	int		tMaxService;
	int		totalWaitTime;
	int		nCustomers;
	int		nServedCustomers;
	CustomerQueue que;
};
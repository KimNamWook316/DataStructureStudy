#include "BankSimulator.h"

BankSimulator::BankSimulator()
	: nCustomers(0)
	, totalWaitTime(0)
	, nServedCustomers(0){}

void BankSimulator::ReadSimulationParameters(){
	printf("시뮬레이션 할 최대 시간 (예 : 10) = ");
	scanf_s("%d", &nSimulation);
	printf("단위 시간에 도착하는 고객 수 (예 : 0.7) = ");
	scanf_s("%lf", &probArrival);
	printf("한 고객에 대한 쵀대 서비스 시간 (예 : 5) = ");
	scanf_s("%d", &tMaxService);
	printf("===================================================\n");
}

void BankSimulator::Run(){
	int clock = 0;
	int serviceTime = -1;
	while (clock < nSimulation) {
		++clock;
		printf("현재 시각 = %d\n", clock);

		if (isNewCustomer()) {
			insertCustomer(clock);
		}
		if (serviceTime > 0) {
			--serviceTime;
		} else {
			if (que.IsEmpty()) {
				continue;
			}
			Customer a = que.Dequeue();
			++nServedCustomers;
			totalWaitTime = clock - a.tArrival;
			printf("    고객 %d 서비스 시작 (대기시간 %d분)\n", a.id, clock - a.tArrival);
			serviceTime = a.tService - 1;
		}
	}
}

void BankSimulator::PrintStat(){
	printf("===================================================\n");
	printf("    서비스 받은 고객 수    = %d\n", nServedCustomers);
	printf("    전체 대기 시간         = %d\n", totalWaitTime);
	printf("    서비스고객 평균 대기 시간 = %-5.2f분\n", (double)totalWaitTime / nServedCustomers);
	printf("    현재 대기 고객 수 = %d\n", nCustomers - nServedCustomers);
}

double BankSimulator::random(){
	return rand() / (double)RAND_MAX;
}

bool BankSimulator::isNewCustomer(){
	return random() / probArrival;
}

int BankSimulator::randServiceTime(){
	return (int)(tMaxService*random()) + 1;
}

void BankSimulator::insertCustomer(int arrivalTime){
	Customer a(++nCustomers, arrivalTime, randServiceTime());
	printf("    고객 %d 방문 (서비스 시간:%d분)\n", a.id, a.tService);
	que.Enqueue(a);
}

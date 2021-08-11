#include "BankSimulator.h"

BankSimulator::BankSimulator()
	: nCustomers(0)
	, totalWaitTime(0)
	, nServedCustomers(0){}

void BankSimulator::ReadSimulationParameters(){
	printf("�ùķ��̼� �� �ִ� �ð� (�� : 10) = ");
	scanf_s("%d", &nSimulation);
	printf("���� �ð��� �����ϴ� �� �� (�� : 0.7) = ");
	scanf_s("%lf", &probArrival);
	printf("�� ���� ���� ���� ���� �ð� (�� : 5) = ");
	scanf_s("%d", &tMaxService);
	printf("===================================================\n");
}

void BankSimulator::Run(){
	int clock = 0;
	int serviceTime = -1;
	while (clock < nSimulation) {
		++clock;
		printf("���� �ð� = %d\n", clock);

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
			printf("    �� %d ���� ���� (���ð� %d��)\n", a.id, clock - a.tArrival);
			serviceTime = a.tService - 1;
		}
	}
}

void BankSimulator::PrintStat(){
	printf("===================================================\n");
	printf("    ���� ���� �� ��    = %d\n", nServedCustomers);
	printf("    ��ü ��� �ð�         = %d\n", totalWaitTime);
	printf("    ���񽺰� ��� ��� �ð� = %-5.2f��\n", (double)totalWaitTime / nServedCustomers);
	printf("    ���� ��� �� �� = %d\n", nCustomers - nServedCustomers);
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
	printf("    �� %d �湮 (���� �ð�:%d��)\n", a.id, a.tService);
	que.Enqueue(a);
}

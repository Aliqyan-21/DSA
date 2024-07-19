// TODO: Complete it

#include "serverListType.h"
#include "waitingCustomerQueueType.h"
#include <iostream>

void setSimulationParameters(int &sTime, int &numOfServers, int &tTime,
                             int &tBetweenCArrival) {
  std::cout << "Enter the Simulation Time: ";
  std::cin >> sTime;

  std::cout << "Enter the Number of Servers";
  std::cin >> numOfServers;

  std::cout << "Enter the Transaction Time";
  std::cin >> tTime;

  std::cout << "Enter the Time Between customers arrival";
  std::cin >> tBetweenCArrival;
}

void runSimulation(int sTime) {
  int customerNumber = 0, clock, totalTime = 0, averageWaitingTime = 5,
      numOfCustomersArrived = 0, numOfCustomersServed = 0,
      numOfCustomersLeftInWaitingQueue = 0, numOfCustomerLeftWithServers = 0;

  for (clock = 1; clock <= sTime; clock++) {
  }
}

int main(void) {
  int sTime, numOfServers, tTime, tBetweenCArrival;

  setSimulationParameters(sTime, numOfServers, tTime, tBetweenCArrival);

  WaitingCutomerQueueType cutomerQueue(100);
  ServerListType servers(numOfServers);
}

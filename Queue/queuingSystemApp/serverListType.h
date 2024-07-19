#ifndef SERVERLISTTYPE_H
#define SERVERLISTTYPE_H

#include "customerType.h"
#include "serverType.h"
#include <ostream>

class ServerListType {
public:
  ServerListType(int num = 1) {
    numOfServers = num;
    servers = new ServerType[num];
  }

  ~ServerListType() { delete[] servers; }

  int getFreeServerId() const {
    int serverId = -1;

    for (int i = 0; i < numOfServers; i++) {
      if (servers[i].isFree()) {
        serverId = i;
        break;
      }
    }
    return serverId;
  }

  int getNumberOfBusyServers() const {
    int count = 0;
    for (int i = 0; i < numOfServers; i++) {
      if (!servers[i].isFree())
        count++;
    }
    return count;
  }

  void setServerBusy(int serverId, CustomerType cCustomer, int tTime) {
    servers[serverId].setBusy();
    servers[serverId].setCurrentCustomer(cCustomer);
    servers[serverId].setTransactionTime(tTime);
  }

  void setServerBusy(int serverId, CustomerType cCustomer) {
    servers[serverId].setBusy();
    servers[serverId].setCurrentCustomer(cCustomer);
    servers[serverId].setTransactionTime(cCustomer.getTransactionTime());
  }

  // parameter : if cout then output on terminal,
  // else filename, then output in file

  // depart time of customer = arrivalTime + waitingTime + transactionTime
  void updateServer(std::ostream &outFile) {
    for (int i = 0; i < numOfServers; i++) {
      if (!servers[i].isFree()) {
        servers[i].decreaseTransactionTime();

        if (servers[i].getRemainingTransactionTime() == 0) {
          outFile << "From server number " << (i + 1) << " customer number "
                  << servers[i].getCurrentCustomerNumber() << std::endl
                  << " departed at clock unit "
                  << servers[i].getCurrentCustomerArrivalTime() +
                         servers[i].getCurrentCustomerWaitingTime() +
                         servers[i].getCurrentCustomerTransactionTime()
                  << std::endl;
        }
      }
    }
  }

private:
  int numOfServers;
  ServerType *servers;
};

#endif // !SERVERLISTTYPE_H

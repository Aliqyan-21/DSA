#ifndef WAITINGCUSTOMER_H

#include "../queueAsArray/queueType.h"
#include "customerType.h"

class WaitingCutomerQueueType : public QueueType<CustomerType> {
public:
  WaitingCutomerQueueType(int size = 100) : QueueType<CustomerType>(size) {}

  void updateWaitingQueue() {
    CustomerType cust;

    cust.setWaitingTime(-1);
    int wTime = 0;

    // dummy customer so we can know that queue is empty
    addQueue(cust);

    while (wTime != -1) {
      cust = front();
      // dummy customer deleted at last
      deleteQueue();

      wTime = cust.getWaitingTime();
      if (wTime == -1)
        // break so dummy customer not added again - so no extra customer
        break;
      cust.incrementWaitingTime();
      addQueue(cust);
    }
  }
};

#endif // !WAITINGCUSTOMER_H

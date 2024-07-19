#ifndef CUSTOMERTYPE_H
#define CUSTOMERTYPE_H

class CustomerType {
public:
  CustomerType(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0) {
    setCustomerInfo(cN, arrvTime, wTime, tTime);
  }

  void setCustomerInfo(int cN = 0, int arrvTime = 0, int wTime = 0,
                       int tTime = 0) {
    customerNumber = cN;
    arrivalTime = arrvTime;
    waitingTime = wTime;
    transactionTime = tTime;
  }

  int getWaitingTime() const { return waitingTime; }

  void setWaitingTime(int time) { waitingTime = time; }

  void incrementWaitingTime() { waitingTime++; }

  int getArrivalTime() const { return arrivalTime; }

  int getTransactionTime() const { return transactionTime; }

  int getCustomerNumber() const { return customerNumber; }

private:
  int customerNumber;
  int arrivalTime;
  int waitingTime;
  int transactionTime;
};

#endif // !CUSTOMERTYPE_H

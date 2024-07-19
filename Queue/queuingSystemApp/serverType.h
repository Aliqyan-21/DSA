#ifndef SERVERTYPE_H
#define SERVERTYPE_H

#include "customerType.h"
#include "string"

class ServerType {
public:
  ServerType() {
    status = "free";
    transactionTime = 0;
  }

  bool isFree() const { return status == "free"; }

  void setBusy() { status = "busy"; }

  void setFree() { status = "free"; }

  // set transaction time according to parameter t
  void setTransactionTime(int t) { transactionTime = t; }

  // set transaction time according to current customer
  void setTransactionTime() {
    transactionTime = currentCustomer.getTransactionTime();
  }

  int getRemainingTransactionTime() const { return transactionTime; }

  void decreaseTransactionTime() { transactionTime--; }

  // set info of current customer
  void setCurrentCustomer(CustomerType c) { currentCustomer = c; }

  int getCurrentCustomerNumber() const {
    return currentCustomer.getCustomerNumber();
  }

  int getCurrentCustomerArrivalTime() const {
    return currentCustomer.getArrivalTime();
  }

  int getCurrentCustomerWaitingTime() const {
    return currentCustomer.getWaitingTime();
  }

  int getCurrentCustomerTransactionTime() const {
    return currentCustomer.getTransactionTime();
  }

private:
  CustomerType currentCustomer;
  std::string status;
  int transactionTime;
};

#endif // !SERVERTYPE_H

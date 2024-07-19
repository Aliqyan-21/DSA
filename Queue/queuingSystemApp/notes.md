## Queuing System that can be used in variety of applications

### Elements
- `Server` - object that provides the service. 
For example, in a bank, a teller is a server; in a grocery store or movie theater, a cashier is a server. 

- `Customer` - object receiving the service. 

- `Service Time` - the time it takes to serve a customer —> the transaction time

### Implementation
This system can be modeled as a time-driven simulation. In
a time-driven simulation, the clock is implemented as a counter and the passage of,
say, 1 minute can be implemented by incrementing the counter by 1. The simulation is
run for a fixed amount of time. If the simulation needs to be run for 100 minutes, the
counter starts at 1 and goes up to 100, which can be implemented by using a loop.

### Customer Class
Every customer has a customer number, arrival time, waiting time, transaction time, and
departure time. If we know the arrival time, waiting time, and transaction time, we can
determine the departure time by adding these three times. Let us call the class to implement the
customer object customerType. 
It follows that the class customerType has four member
variables: the customerNumber, arrivalTime, waitingTime, and transactionTime,
each of type int. The basic operations that must be performed on an object of type
customerType are as follows: Set the customer’s number, arrival time, and waiting time;
increment the waiting time by one clock unit; return the waiting time; return the arrival time;
return the transaction time; and return the customer number.

### Server Class
At any given time unit, the server is either busy serving a customer or is free. We use a string
variable to set the status of the server. Every server has a timer and because the program might
need to know which customer is served by which server, the server also stores the information
of the customer being served. 
Thus, three member variables are associated with a server: 
the status, the transactionTime, and the currentCustomer. 
Some of the basic operations that must be performed on a server are as follows: Check whether the server is free; set the
server as free; set the server as busy; set the transaction time (that is, how long it takes to serve
the customer); return the remaining transaction time (to determine whether the server should
be set to free); if the server is busy after each time unit, decrement the transaction time by one
time unit; and so on. 

###### Because we are designing a simulation program that can be used in a variety of applications, we need to design two more classes: a class to create and process a list of servers and a class to create and process a queue of waiting customers.

### ServerList and CustomerList class
1. ServerList
 
A server list is a set of servers. At any given time, a server is either free or busy. For the
customer at the front of the queue, we need to find a server in the list that is free. If all
the servers are busy, the customer must wait until one of the servers becomes free. Thus,
the class that implements a list of servers has two member variables: one to store the
number of servers and one to maintain a list of servers. 
Using dynamic arrays, depending on the number of servers specified by the user, a list of servers is created during program
execution. 
Some of the operations that must be performed on a server list are as follows:
Return the server number of a free server; when a customer gets ready to do business and
a server is available, set the server to busy; when the simulation ends, some of the servers
might still be busy, so return the number of busy servers; after each time unit, reduce the
transactionTime of each busy server by one time unit; and if the transactionTime
of a server becomes zero, set the server to free.

2. CustomerList

When a customer arrives, he or she goes to the end of the queue. When a server becomes
available, the customer at the front of the queue leaves to conduct the transaction. After
each time unit, the waiting time of each customer in the queue is incremented by 1. The
ADT queueType designed in this chapter has all the operations needed to implement a
queue, except the operation of incrementing the waiting time of each customer in the
queue by one time unit. We will derive a class, waitingCustomerQueueType, from
the class queueType and add the additional operations to implement the customer
queue.

### Main Program

1. To run the simulation, we need to know the number of customers arriving at a given
time unit and how long it takes to serve the customer. We use the `Poisson distribution`
from statistics, which says that the probability of y events occurring at a given time is
given by the formula:

P(y) = lambda^y * e^-lambda / y!, y = 0,1,2,....,

`where`, lambda = expected value that y events occur at that time.
Suppose that, on average, a customer arrives every four minutes. During this four-minute period, the customer can arrive
at any one of the four minutes. Assuming an equal likelihood of each of the four minutes, the
expected value that a customer arrives in each of the four minutes is, therefore, 1⁄4 = 0.25.

2. Function runSimulation :- to implement the simulation. Suppose
that we run the simulation for 100 time units and customers arrive at time units 93, 96,
and 100. The average transaction time is 5 minutes—that is, 5 time units. For simplicity,
assume that we have only one server and the server becomes free at time unit 97, and that
all customers arriving before time unit 93 have been served. When the server becomes
free at time unit 97, the customer arriving at time unit 93 starts the transaction. Because the
transaction of the customer arriving at time unit 93 starts at time unit 97 and it takes 5
minutes to complete a transaction, when the simulation loop ends, the customer arriving at
time unit 93 is still at the server. Moreover, customers arriving at time units 96 and 100 are
in the queue. For simplicity, we assume that when the simulation loop ends, the customers
at the servers are considered served. 

3. The general algorithm for this function is as follows:

- Declare and initialize the variables such as the simulation parameters,
customer number, clock, total and average waiting times, number of
customers arrived, number of customers served, number of customers
left in the waiting queue, number of customers left with the servers,
waitingCustomersQueue, and a list of servers.

- The main loop is as follows:

for (clock = 1; clock <= simulationTime; clock++)

{

  Update the server list to decrement the transaction time of
    each busy server by one time unit.

  If the customer’s queue is nonempty, increment the waiting
  time of each customer by one time unit.

  If a customer arrives, increment the number of customers by 1
  and add the new customer to the queue.

  If a server is free and the customer’s queue is nonempty,
  remove a customer from the front of the queue and send
  the customer to the free server.

}

- Print the appropriate results. Your results must include the number of
customers left in the queue, the number of customers still with servers,
the number of customers arrived, and the number of customers who
actually completed a transaction.

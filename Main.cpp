

#include <iostream> // For cout
#include <cstdlib> // For rand and srand
#include <time.h> // For time in srand
#include"DEQ.h" // The used class
#include "DEQ.cpp"
using namespace std;

void arrival(DEQ<int>& Q, float P_arrival, int& T_arrival, int T_clock, int& arrivalcount) // Deals with planes' arival
{
	float R = (rand() % 1001) / 1000.0; // Random a number between 0 and 1
	if (R < P_arrival)  				// Job arrived
		if (Q.DEQisFull()) cout << "The shorter DEQ is not availble!" << endl; // Shorter DEQ validation
		else {
			T_arrival = T_clock;   // Assigning arrival time
			Q.Add_Rear(T_arrival); // Adding the plane to the queue
			arrivalcount++; // Arrival increment
			cout << "Arrival# " << arrivalcount << " at: " << T_clock << endl; // Arrival log statement
		}
}

void exitLine(DEQ<int>& Q, int& T_arrival, int& T_wait, int T_clock, int& waitTotal, int& jobcount) { // Service ended
	if (Q.DEQisEmpty()) cout << "Airway is empty!" << endl; // DEQ validation
	else
	{
		Q.Remove_Front(T_arrival); // Remove after service
		T_wait = T_clock - T_arrival; // Calculating wait time
		waitTotal = waitTotal + T_wait; // Calculating total wait time
		jobcount = jobcount + 1;	// Incrementing jobs serviced
	}
}

void serviceStart(int& T_remaining, int T_landing) { // When new service starts
	T_remaining = T_landing; // Renewing remaining time
}

void service(DEQ<int>& Q, int& T_remaining, int& T_arrival, int& T_wait, int T_clock, int& waitTotal, int& jobcount, int T_landing) { // Full service
	if ((T_remaining == 0) && (!Q.DEQisEmpty())) // Checks service availbility
	{
		exitLine(Q, T_arrival, T_wait, T_clock, waitTotal, jobcount); // Exits the finished plane
		serviceStart(T_remaining, T_landing); // Starts new service
		cout << "Job# " << jobcount << " Service Started at: " << T_clock << " wait = " << T_wait << endl; // Service started log statement
	}
}

float averageWait(int jobcount, int waitTotal) { // Claculates average wait time
	if (jobcount == 0) return 0;
	else return (float(waitTotal) / jobcount);
}

int main() {
	DEQ<int> airway1(1000); // First airway
	DEQ<int> airway2(1000); // Second airway
	srand(time(NULL)); // For randomization without respect to time

	const int T_max = 6 * 60, T_landing = 10, T_inter = 6; // Given constants
	int T_arrival, T_wait = 0, T_clock = 0, T_remaining1 = 0, T_remaining2 = 0, waitTotal = 0, jobcount = 0, arrivalcount = 0; // Needed variables
	const float P_arrival = 1 / float(T_inter); // Probability of arrival

	while (T_clock < T_max) { // In simulation time
		if (airway1.DEQ_Length() < airway2.DEQ_Length()) // Checking the shorter airway DEQ
			arrival(airway1, P_arrival, T_arrival, T_clock, arrivalcount); // If airway1's is shorter
		else
			arrival(airway2, P_arrival, T_arrival, T_clock, arrivalcount); // If airway2's is shorter or the two are equal
		service(airway1, T_remaining1, T_arrival, T_wait, T_clock, waitTotal, jobcount, T_landing); // Service for airway1
		service(airway2, T_remaining2, T_arrival, T_wait, T_clock, waitTotal, jobcount, T_landing); // Service for airway2
		if (T_remaining1 > 0) T_remaining1--; // Decrementing airway1's time remaining
		if (T_remaining2 > 0) T_remaining2--; // Decrementing airway2's time remaining
		T_clock++; // Incrementing clock's time
	}
	cout << "Average wait Time is " << averageWait(jobcount, waitTotal) << endl; // Final average wait log statement
	system("pause");
	return 0;
}
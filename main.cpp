#include <iostream>
#include <ctime>

int main() {
	uint16_t foo[1000], bar[1000];
	clock_t startTime = clock(), elapsedTime;
	uint64_t elqualsCounter = 0, differentsCounter = 0;

	for (uint16_t index = 0; index < 1000; ++index) {
		// populating
		foo[index] = index;
		bar[index] = 999 - index;
	}

	for (uint64_t trillionCounter = 1; trillionCounter < 1000000000000; ++trillionCounter) {
		for (uint16_t fooIndex = 0; fooIndex < 1000; ++fooIndex) { // quatrillion
			for (uint16_t barIndex = 0; barIndex < 1000; ++barIndex) { // quintillion
				if (foo[fooIndex] == bar[barIndex]) {
					++elqualsCounter;
				} else { // this is to force the compiler to not optimize this logic
					++differentsCounter;
				}
			}
		}

		// Consider that for each iteration of trillionCounter
		//there are 1.000.000 more iterations over the comparisons between foo and bar.
		// This is visible in conparisonsCounter.
		if (trillionCounter % 10000 == 0) { // this means 10.000.000.000 of comparisons
			std::cout << "comparisons: " << elqualsCounter + differentsCounter << std::endl;
			elapsedTime = ((clock() - startTime) / CLOCKS_PER_SEC);
			std::cout <<
				"After a " << elqualsCounter + differentsCounter <<
				" comparisons, the elapsed time after the last print is: " << elapsedTime <<
				" seconds.\nThis means that whole this should take about: " <<
				(((elapsedTime * 250000000) / 60) / 60) / 24 <<
				// 2500000 because 250.000.000 * 10.000.000.000 is 2.5^18
				" days to finish in your machine!\n(this is: " <<
				((((elapsedTime * 250000000) / 60) / 60) / 24) / 365 <<
				" years!!)\nNow split this number by the number of threads you have" <<
				" and realize the it's almost impossible to calculate with CPU...\n" <<
				"My best regards and thanks for testing!\n\n\n" <<
			std::endl;
			startTime = clock();
		}
	}
}

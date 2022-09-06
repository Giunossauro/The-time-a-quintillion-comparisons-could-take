#include <iostream>
#include <ctime>

int main() {
    uint16_t foo[1000], bar[1000];
    uint32_t startTime = clock(), elapsedTime = 0;
    uint64_t comparisonsCounter = 0, coutMarkCounter = 0;

    for (uint16_t index = 0; index < 1000; ++index) {
        foo[index] = index;
        bar[index] = 999 - index;
    }

    for (uint64_t trillionCounter = 1; trillionCounter < 1000000000000; ++trillionCounter) {
        for (uint16_t fooIndex = 0; fooIndex < 1000; ++fooIndex) { //quatrillion
            for (uint16_t barIndex = 0; barIndex < 1000; ++barIndex) { //quintillion
                if (foo[fooIndex] == bar[barIndex]) {
                    ++comparisonsCounter;
                }
            }
        }

	// Consider that for each iteration of trillionCounter
	//there are 1.000.000 more iterations over the comparisons between foo and bar.
	// This is visible in conparisonsCounter.
        if (trillionCounter % 10000 == 0) { // this means 10.000.000.000 of comparisons
            ++coutMarkCounter;
            std::cout << "comparisonsCounter: " << comparisonsCounter << std::endl;
            elapsedTime = ((clock() - startTime) / 1000);
            std::cout <<
                "After a 100 billion comparisons, the elapsed time is: " <<
                elapsedTime <<
                " seconds.\nThis means that whole this should take about: " <<
                ((((elapsedTime * 2500000) / 60) / 60) / 24) / coutMarkCounter <<
		// 2500000 because 2.500.000 * 100.000.000.000 is 2.5^18
                " days to finish in your machine!\n(this is: " <<
                (((((elapsedTime * 2500000) / 60) / 60) / 24) / 365) / coutMarkCounter <<
                " years!!\nNow split this number by the number of threads you have" <<
                " and realize the it's almost impossible to calculate with CPU...\n" <<
                "My best regards and thanks for testing!\n\n\n" <<
            std::endl;
        }
    }
}

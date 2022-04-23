#include <iostream>
#include <ctime>

int main() {
	uint16_t p[1000], m[1000], d, e;
	uint32_t t = clock();
	uint64_t c = 0, trillion;

	for (d = 0; d < 1000; d++) {
		p[d] = d;
		m[d] = 999 - d;
	}
	
	for (trillion = 1; trillion < 1500000000000; trillion++) {
		for (d = 0; d < 1000; d++) {
			for (e = 0; e < 1000; e++) {
				if (p[d] == m[e]) {
					c++;
				}
			}
		}
		if (trillion % 100000 == 0) {
			std::cout << "c: " << c << std::endl;
			c = ((clock() - t) / 1000);
			std::cout <<
				"After a 100 billion, the elapsed time is: " <<
				c <<
				" seconds.\nThis means that this should take about: " <<
				(((c * 25000000) / 60) / 60) / 24 <<
				" days to finish in your machine!\n" <<
				"(this is: " <<
				((((c * 25000000) / 60) / 60) / 24) / 365 <<
				" years!!\nNow split this number by the number of threads you have" <<
				" and realize the it's impossible to calculate with CPU...\n" <<
				"My best regards and thanks for testing!" <<
			std::endl;
		}
	}
}
 

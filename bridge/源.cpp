#include <iostream>

int find_min(int num, int *cost, int *chosen, int *bridge);

int main() {

	int num, ii, total = 0;
	std::cin >> num;

	int *chosen = new int[num];
	int *bridge = new int[num*num];
	int *cost = new int[num*num];

	for (ii = 0; ii < (num*num); ii++)
		std::cin >> cost[ii];

	for (ii = 0; ii<num; ii++)
		chosen[ii] = 0;
	for (ii = 0; ii<(num*num); ii++)
		bridge[ii] = 0;

	chosen[0] = 1;

	for (ii = 0; ii < (num - 1); ii++)
		total += find_min(num, cost, chosen, bridge);
	std::cout << total << std::endl;

	delete[] chosen;
	delete[] bridge;
	delete[] cost;
	return 0;
}

int find_min(int num, int *cost, int *chosen, int *bridge) {

	int ii, jj;
	int temp[3] = { 0, 0, INT_MAX };

	for (ii = 0; ii<num; ii++) {
		if (1 == chosen[ii]) {
			for (jj = 0; jj<num; jj++) {
				if (0 == chosen[jj]) {
					if (cost[ii*num + jj]<temp[2]) {
						temp[0] = ii;
						temp[1] = jj;
						temp[2] = cost[ii*num + jj];
					}
				}
			}
		}
	}

	bridge[temp[0] * num + temp[1]] = 1;
	chosen[temp[1]] = 1;

	return temp[2];

}
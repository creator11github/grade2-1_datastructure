#include "listTemp.h"
#include "company.h"
#include <ctime>
#include <iostream>
using namespace std;

void TimeTest(Company &cmp, int total_num)
{

	// runtime analysis
	clock_t start_t, end_t, elapsed_t;
	start_t = clock();
	cmp.inputEmployeeHead(total_num);
	end_t = clock();
	elapsed_t = end_t - start_t;
	cout << "Clock ticks per second: " << CLOCKS_PER_SEC << endl;
	cout << "Time elapsed for inputEmployeeHead: " << elapsed_t << " (in ticks)" << endl;

	start_t = clock();
	cmp.inputEmployeeTail(total_num);
	end_t = clock();
	elapsed_t = end_t - start_t;
	cout << "Time elapsed for inputEmployeeTail: " << elapsed_t << " (in ticks)" << endl;
	cout << endl;
}

int main()
{
	Company cmp;

	// please test your implementation
	int total_nums[] = {1000, 2000, 5000, 10000, 20000, 50000};
	for (int i = 0; i < 6; i++)
	{
		TimeTest(cmp, total_nums[i]);
	}
	
	system("pause");
	return 0;
}
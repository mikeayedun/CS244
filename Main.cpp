#include "Repository.h"
using namespace labI;

void TestUnits()
{
	bool (*func[8])() = { &SortTest, &MinimumTest, &MaximumTest, &RangeTest, &MedianTest, &MeanTest, &StandardDeviationTest, &OutlinerTest };
	string tests[8] = { "Sort ", "Minimum ", "Maximum ","Range ", "Median ", "Mean ", "Standard Deviation ", "Outliner Count " };

	for (int i = 0; i < 8; i += 1)
	{
		cout << tests[i] << ((func[i]) ? ("Test has passed.") : ("Test has failed.")) << "\n";
	}
}

int main()
{
	float data[30][17];

	if (RetrieveData(data, "data2.dat"))
	{
		TestUnits();
		PrintReport(data, 30, "records2.dat");
	}
	else
	{
		cout << "Could not retrieve data.\n";
	}

	return 0;
}
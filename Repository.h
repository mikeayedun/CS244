#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Sort.h"
#include "Maximum.h"
#include "Minimum.h"
#include "Mean.h"
#include "Range.h"
#include "Median.h"
#include "OutlinerCount.h"
#include "StandardDeviation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

namespace labI
{
	bool RetrieveData(float data[][17], string filename)
	{
		fstream fin(filename.c_str(), fstream::in);

		if (fin.is_open())
		{
			for (int i = 0; i < 30; i += 1)
			{
				for (int j = 0; j < 17; j += 1)
				{
					fin >> data[i][j];
				}
			}

			fin.close();
			return true;
		}

		fin.close();
		return false;
	}

	bool SortTest()
	{
		float data[17] = { 17, 58, 48, 2, 42, 21, 29, 51, 39, 57, 37, 48, 24, 37, 39, 42, 34 };
		int size = 17;
		Sort(data, size);
		for (int i = 0; i < (size - 1); i += 1)
		{
			if (data[i] > data[i + 1])
			{
				return false;
			}
		}
		return true;
	}

	bool MaximumTest()
	{
		float data[17] = { 51, 79, 82, 41, 58, 78, 61, 10, 95, 78, 98, 11, 84, 97, 74, 78, 83 };
		int size = 17;
		return (Maximum(data, size) == 98);
	}

	bool MinimumTest()
	{
		float data[17] = { 51, 79, 82, 41, 58, 78, 61, 10, 95, 78, 98, 11, 84, 97, 74, 78, 83 };
		int size = 17;
		return (Minimum(data, size) == 10);
	}

	bool RangeTest()
	{
		float data[17] = { 51, 79, 82, 41, 58, 78, 61, 10, 95, 78, 98, 11, 84, 97, 74, 78, 83 };
		int size = 17;
		return (Range(data, size) == 88);
	}

	bool MedianTest()
	{
		float data1[17] = { 51, 79, 82, 41, 58, 78, 61, 10, 95, 78, 98, 11, 84, 97, 74, 78, 83 };
		int size1 = 17;
		float data2[16] = { 51, 79, 82, 41, 58, 61, 10, 95, 78, 98, 11, 84, 97, 74, 79, 83 };
		int size2 = 16;
		return ((Median(data1, size1) == 78) && (Median(data2, size2) == 78.5));
	}

	bool MeanTest()
	{
		float data[17] = { 51, 79, 82, 41, 58, 78, 61, 10, 95, 78, 98, 11, 84, 97, 74, 78, 83 };
		int size = 17;
		return (abs(Mean(data, size) - 68.1176) < 0.01);
	}

	bool StandardDeviationTest()
	{
		float data[17] = { 51, 79, 82, 41, 58, 78, 61, 10, 95, 78, 98, 11, 84, 97, 74, 78, 83 };
		int size = 17;
		return (abs(StandardDeviation(data, size) - 25.8773) < 0.01);
	}

	bool OutlinerTest()
	{
		float data[17] = { 51, 79, 82, 41, 58, 78, 61, 10, 95, 78, 98, 11, 84, 97, 74, 78, 83 };
		int size = 17;
		return (OutlinerCount(data, size) == 2);
	}

	string PrintRecordData(float data[], int size)
	{
		stringstream out;
		out << "Data: [";
		for (int i = 0; i < size; i += 1)
		{
			out << setw(4) << setfill(' ') << data[i];
		}
		out << "]\n";

		return out.str();
	}

	string PrintRecordStat(float data[], int size)
	{
		stringstream out;
		string labels[7] = { "Mn: "," Mx: "," Rn: "," Md: ", " Av: ", " Sd: ", " Oc: "};
		float(*func[7])(float[], int) = { &Minimum, &Maximum, &Range, &Median, &Mean, &StandardDeviation, &OutlinerCount};

		out << "Stat: [";
		out << setprecision(2) << fixed;
		for (int i = 0; i < 7; i += 1)
		{
			out << labels[i] << setw(6) << setfill(' ') << func[i](data, size);
		}
		out << "]\n";

		return out.str();
	}

	void PrintReport(float data[][17], int size, string filename)
	{
		ofstream fout(filename.c_str(), fstream::out);

		if (fout.is_open())
		{
			fout << "ASSIGNMENT ASSESSMENT\n";
			float adata[30];

			for (int i = 0; i < 17; i += 1)
			{
				for (int j = 0; j < 30; j += 1)
				{
					adata[j] = data[j][i];
				}

				if (i >= 0 && i < 10)
				{
					fout << "Homework " << setw(2) << setfill('0') << (i + 1) << "\n";
				}
				else if (i >= 10 && i < 15)
				{
					fout << "Quiz " << setw(2) << setfill('0') << (i - 9) << "\n";
				}
				else if (i == 15)
				{
					fout << "Midterm\n";
				}
				else
				{
					fout << "Final\n";
				}
				fout << PrintRecordData(adata, 30);
				fout << PrintRecordStat(adata, 30);
				fout << "\n";
			}

			fout << "STUDENT ASSESSMENT\n";
			for (int i = 0; i < 30; i += 1)
			{
				fout << "Student " << right << setw(2) << setfill('0') << (i + 1) << "\n";
				fout << PrintRecordData(data[i], 17);
				fout << PrintRecordStat(data[i], 17);
				fout << "\n";
			}
		}
		fout.close();
	}
}

#endif

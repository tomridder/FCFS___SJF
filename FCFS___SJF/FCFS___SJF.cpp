#include"stdafx.h"
#include<iostream>
#include <iomanip>
#include<string.h>
using namespace std;
#define  MaxNum  100
double  ArrivalTime[MaxNum];
double  ServiceTime[MaxNum];
double  StartTime[MaxNum];
double  FinishTime[MaxNum];
double  WholeTime[MaxNum];
double  WeightWholeTime[MaxNum];
double AverageWT_FCFS, AverageWT_SJF;
double AverageWWT_FCFS, AverageWWT_SJF;
void Give()
{
	cout << "Please Enter ArrivalTime of A B C D E " << endl;
	for (int i = 0; i <= 4; i++)
	{

		cin >> ArrivalTime[i];
	}

	/*
	for (int i = 0; i <= 4; i++)
	{
	ArrivalTime[i] = i;
	}
	*/
	cout << "Please Enter ServiceTime of  A B C D E " << endl;
	for (int i = 0; i <= 4; i++)
	{
		char m = i + 65;

		cin >> ServiceTime[i];
	}


}
void Check(int p, int t)
{
	char m = p + 65;

	if ((t >= StartTime[p]) && (t <= FinishTime[p]))
	{
		cout << "进程" << m << "  在运行 ";
	}
	else
	{
		cout << "进程" << m << "不在运行 ";
	}

}
void Show()
{
	cout << "Process         : " << "A " << "B " << "C " << "D " << "E " << endl;;
	cout << "ArriveTime      : " << ArrivalTime[0] << " " << ArrivalTime[1] << " " << ArrivalTime[2] << " " << ArrivalTime[3] << " " << ArrivalTime[4] << endl;
	cout << "ServiceTime     : " << ServiceTime[0] << " " << ServiceTime[1] << " " << ServiceTime[2] << " " << ServiceTime[3] << " " << ServiceTime[4] << endl;
	cout << "StartTime       : " << StartTime[0] << " " << StartTime[1] << " " << StartTime[2] << " " << StartTime[3] << " " << StartTime[4] << endl;
	cout << "FinishTime      : " << FinishTime[0] << " " << FinishTime[1] << " " << FinishTime[2] << " " << FinishTime[3] << " " << FinishTime[4] << endl;
	cout << "WholeTime       : " << WholeTime[0] << " " << WholeTime[1] << " " << WholeTime[2] << " " << WholeTime[3] << " " << WholeTime[4] << "  " << AverageWT_FCFS << endl;
	cout << "WeightWholeTime : " << WeightWholeTime[0] << " " << WeightWholeTime[1] << " " << WeightWholeTime[2] << " " << WeightWholeTime[3] << " " << WeightWholeTime[4] << "  " << AverageWWT_FCFS << endl;


	for (int t = 0; t <= 18; t++)

	{
		cout << "Time" << t;
		for (int p = 0; p <= 4; p++)
		{
			Check(p, t);
		}
		cout << endl;
	}
}
int Choose1()
{

	for (int i = 0; i <= 4; i++)
	{
		FinishTime[i] = ArrivalTime[i] + ServiceTime[i];
	}

	FinishTime[0] = ArrivalTime[0] + ServiceTime[0];
	for (int i = 1; i <= 4; i++)
	{
		FinishTime[i] = FinishTime[i - 1] + ServiceTime[i];
	}
	StartTime[0] = 1.0;
	for (int i = 1; i <= 4; i++)
	{
		StartTime[i] = FinishTime[i - 1] + 1;
	}

	for (int i = 0; i <= 4; i++)
	{
		WholeTime[i] = FinishTime[i] - ArrivalTime[i];
	}
	/********************/
	double Whole = 0.0;
	for (int i = 0; i <= 4; i++)
	{
		Whole += WholeTime[i];
	}
	AverageWT_FCFS = Whole / 5;

	/**********************/
	for (int i = 0; i <= 4; i++)
	{
		WeightWholeTime[i] = WholeTime[i] / ServiceTime[i];
	}
	/******************/
	double WeightWhole = 0.0;
	for (int i = 0; i <= 4; i++)
	{
		WeightWhole += WeightWholeTime[i];
	}
	AverageWWT_FCFS = WeightWhole / 5;

	/**************************************************************************************************************/



	getchar();
	getchar();
	return 0;
}

int Choose2()
{
	int ServiceTimeb[100];
	int ServiceNum[100];
	int  b;
	for (int i = 0; i <= 4; i++)
	{
		ServiceTimeb[i] = ServiceTime[i];
	}//赋值数组
	/*************/
	cout << "Process          ";
	for (int i = 0; i <= 4; i++)
	{
		char m;
		m = i + 65;
		cout << m << " ";
	}
	cout << endl;
	/*************/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j < 4 - i; j++)
		{
			if (ServiceTimeb[j] > ServiceTimeb[j + 1])
			{
				int temp = ServiceTimeb[j];
				ServiceTimeb[j] = ServiceTimeb[j + 1];
				ServiceTimeb[j + 1] = temp;
			}
		}
	}

	ServiceNum[0] = 0;
	FinishTime[0] = 4;

	for (int j = 1; j <= 4; j++)
	{
		if (ServiceTime[j] == ServiceTimeb[1])
			ServiceNum[j] = 1;
	}
	for (int j = 1; j <= 4; j++)
	{
		if (ServiceTime[j] == ServiceTimeb[2])
			ServiceNum[j] = 2;
	}
	for (int j = 1; j <= 4; j++)
	{
		if (ServiceTime[j] == ServiceTimeb[3])
			ServiceNum[j] = 3;
	}
	for (int j = 1; j <= 4; j++)
	{
		if (ServiceTime[j] == ServiceTimeb[4])
			ServiceNum[j] = 4;
	}
	cout << "ServiceNum       ";
	for (int i = 0; i <= 4; i++)
	{
		cout << ServiceNum[i] << " ";
	}
	cout << endl;
	/**/
	int An;
	StartTime[0] = 1;
	for (int j = 1; j <= 4; j++)
	{
		if (ServiceNum[j] == 1)
		{
			StartTime[j] = FinishTime[0] + 1;
			FinishTime[j] = FinishTime[0] + ServiceTime[j];
			An = j;
			break;
		}
	}
	for (int j = 1; j <= 4; j++)
	{
		if (ServiceNum[j] == 2)
		{
			StartTime[j] = FinishTime[An] + 1;
			FinishTime[j] = FinishTime[An] + ServiceTime[j];
			An = j;
			break;
		}
	}
	for (int j = 1; j <= 4; j++)
	{
		if (ServiceNum[j] == 3)
		{
			StartTime[j] = FinishTime[An] + 1;

			FinishTime[j] = FinishTime[An] + ServiceTime[j];
			An = j;
			break;
		}
	}
	for (int j = 1; j <= 4; j++)
	{
		if (ServiceNum[j] == 4)
		{
			StartTime[j] = FinishTime[An] + 1;

			FinishTime[j] = FinishTime[An] + ServiceTime[j];
			An = j;
			break;
		}
	}
	cout << "ServiceTime      ";
	for (int j = 0; j <= 4; j++)
		cout << ServiceTime[j] << " ";
	cout << endl;

	cout << "FinishTime       ";
	for (int j = 0; j <= 4; j++)
		cout << FinishTime[j] << " ";
	cout << endl;


	for (int j = 0; j <= 4; j++)
	{
		WholeTime[j] = FinishTime[j] - ArrivalTime[j];
	}
	cout << "WholeTime        ";
	for (int j = 0; j <= 4; j++)
		cout << WholeTime[j] << " ";

	//平均 周转
	double Whole = 0.0;
	for (int i = 0; i <= 4; i++)
	{
		Whole += WholeTime[i];
	}
	AverageWT_SJF = Whole / 5;

	cout << AverageWT_SJF << " ";
	cout << endl;
	// 周转时间
	//带全周转
	for (int j = 0; j <= 4; j++)
	{
		WeightWholeTime[j] = WholeTime[j] / ServiceTime[j];
	}
	//平均带全周转
	double WeightWhole = 0.0;
	for (int i = 0; i <= 4; i++)
	{
		WeightWhole += WeightWholeTime[i];
	}
	AverageWWT_SJF = WeightWhole / 5;
	cout << "WeightWholeTime   ";
	for (int j = 0; j <= 4; j++)
		cout << setprecision(2) << std::fixed << WeightWholeTime[j] << " ";
	cout << setprecision(2) << std::fixed << AverageWWT_SJF;
	cout << endl;
	/*
	StartTime[0] = 1.0;
	for (int i = 1; i <= 4; i++)
	{
	StartTime[i] = FinishTime[i - 1] + 1;
	}
	*/
	cout << "StartTime        ";
	for (int j = 0; j <= 4; j++)
		cout << StartTime[j] << " ";
	cout << endl;

	for (int t = 0; t <= 18; t++)

	{
		cout << "Time" << t;
		for (int p = 0; p <= 4; p++)
		{
			Check(p, t);
		}
		cout << endl;
	}

	return 0;
}

int main()
{
	cout << "Chose 1-FCFS Or 2-SJF ?" << endl;
	int Choose;
	cin >> Choose;
	Give();

	if (Choose == 1)
	{
		Choose1();
		Show();
	}
	else
	{
		Choose2();
		getchar();
	}

	getchar();
	getchar();
	return 0;
}
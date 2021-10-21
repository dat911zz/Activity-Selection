#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//Struct
struct Activity
{
	char name[3];
	int start, end;
};
//Prototype
void readFile(const char* filename, Activity* a, int& n);
void form();
void showActivity(Activity x);
void showList(Activity* a, int n);
void sortAscendingEndTime(Activity* a, int n);
void deleteElementPosK(Activity* a, int& n, int k);
void ActivitySelection(Activity* a, int& n);

//Main
void main()
{
	Activity a[100];
	int n;
	readFile("Activity.txt", a, n);
	showList(a, n);
	sortAscendingEndTime(a, n);
	showList(a, n);
	cout << "\nKQ sau khi lua chon hoat dong: " << endl;
	ActivitySelection(a, n);
	showList(a, n);
}
//Functions
void readFile(const char* filename, Activity* a, int& n)
{
	ifstream in;
	in.open(filename);
	if (in)
	{
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> a[i].name >> a[i].start >> a[i].end;
		}
	}
}
void form()
{
	cout << setw(15) << left << "Name"; //Su dung ham setw de xac dinh do rong du lieu + ham left de canh le Trai
	cout << setw(15) << left << "Start time";
	cout << setw(15) << left << "End time" << endl;

	cout << setfill('*');
	cout << setw(50) << "*" << endl;	//De lam duong ke 

	cout << setfill(' '); // reset fill bang khoang trang
}
void showActivity(Activity x)
{
	cout << setw(15) << left << x.name; //Su dung ham setw de xac dinh do rong du lieu + ham left de canh le Trai
	cout << setw(15) << left << x.start;
	cout << setw(15) << left << x.end << endl;
}
void showList(Activity* a, int n)
{
	cout << "-So luong hoat dong: " << n << endl;
	cout << "\t\t-Danh sach hoat dong-" << endl;
	form();
	for (int i = 0; i < n; i++)
	{
		showActivity(a[i]);
	}
}
void sortAscendingEndTime(Activity* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].end > a[j].end)
			{
				swap(a[i], a[j]);
			}
		}
	}
}
void deleteElementPosK(Activity* a, int& n, int k)
{
	for (int i = k + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}
void ActivitySelection(Activity* a, int& n)
{
	int end = a[0].end;
	for (int i = 1; i < n; i++)
	{
		if (a[i].start >= end)
		{
			end = a[i].end;
		}
		else
		{
			deleteElementPosK(a, n, i);
			i--;
		}
	}
}

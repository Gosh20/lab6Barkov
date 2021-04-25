#include <iostream>
#include "../header/StackArr.h"
#include "../header/StackCL.h"
#include <string>


using namespace std;

int main()
{
	int n;
	cout << "1-StackArr, 2 - StackCL: ";
	cin >> n;
	
	if (n == 1)
	{
		int arr, pos, element;
		cout << "StackArr length: ";
		cin >> arr;
		StackArr<int> a(arr);
		do
		{
			cout << "Add element? (0-no, 1-yes) ";
			cin >> pos;
			if (pos == 1)
			{
				cout << "Element " << a.GetSize() << " from " << arr << ": ";
				cin >> element;
				a.Push(element);
			}
			else if (pos == 0)
			{
				cout << "Element " << a.GetSize() << " from " << arr << ": " << 0 << endl;
				a.Push(0);
			}
			
		} while ((a.GetSize() - 1) < arr);
		cout << endl << "StackArr: " << a << endl;
	}
	else if (n == 2)
	{
		int arr, pos, element;
		cout << "StackCL length: ";
		cin >> arr;
		StackCL<int> a(arr);
		do
		{
			cout << "Add element? (0-no, 1-yes) ";
			cin >> pos;
			if (pos == 1)
			{
				cout << "Element " << a.GetSize() << " from " << arr << ": ";
				cin >> element;
				a.Push(element);
			}
			else if (pos == 0)
			{
				cout << "Element " << a.GetSize() << " from " << arr << ": " << 0 << endl;
				a.Push(0);
			}

		} while ((a.GetSize() - 1) < arr);
		cout << endl << "StackCL: " << a << endl;
	}
	system("pause");
	return 0;

}
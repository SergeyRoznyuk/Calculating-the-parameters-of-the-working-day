#include <iostream>
#include<conio.h>
using namespace std;
#include"Worker.h"


void main()
{	
	WorkShedule a;
	//a.createTemplateShedule();
	a.manualCreateShedule();
	//a.autoCreateShedule();
	a.Print();
	//char choice;
	//do
	//{
	//	cout << "1. Data on employees.\n";
	//	cout << "2. Work schedules.\n";
	//	cout << "3. Report card.\n";
	//	cout << "4. Payrol preparation.\n";
	//	cout << "Esc - exit.\n";
	//	choice=getch();
	//	switch (choice)
	//	{
	//	case '1':
	//		break;
	//	case'2':
	//	{
	//			   cout << "1. Add new work schedules.\n";
	//			   cout << "2. Make changes to the work schedule.\n";
	//			   cout << "0. Main menu.\n";
	//			   choice = getch();
	//			   switch (choice)
	//			   {
	//			   case '1':
	//				   break;
	//			   case '2':
	//				   break;
	//			   }
	//	}
	//		break;
	//	case '3':
	//		break;
	//	case'4':
	//		break;
	//	}
	//} while (choice != 27);
}
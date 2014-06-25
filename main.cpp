#include <iostream>
#include "largeClass.h"
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
	char *file1 = argv[1]; // ���������� �� ������ ������� ������� ����������
	char op = argv[2][0];
	char *file2 = argv[3];
	char *file3 = argv[4];
	char *file4 = NULL; // �� ����������� ������� -b
	
	int bin = 0; //�����. ���������� ��� ��������� �����
	
	if (argc == 6)
	{
		if (!strcmp(argv[5], "-b"))// ���� ����� �������� ����� -b, �� �������� � ��������� �������
			bin = 1;
		else
			file4 = argv[5];
	}

	if (argc == 7)
	{
		bin = 1;
		file4 = argv[6];
	}

	largeClass A, B, mod; 

	if (bin == 1)
	{
		A.readFromBinFile(file1);
		B.readFromBinFile(file2);
		if (file4 != NULL)
			mod.readFromBinFile(file4);
	}
	else
	{
		A.readFromTextFile(file1);
		B.readFromTextFile(file2);
		if (file4 != NULL)
			mod.readFromTextFile(file4);
	}

	largeClass c; 
	if (argv[2][0] == '+')
	{
		c = A + B;
	}

	if (argv[2][0] == '-')
	{
		c = A - B;
	}


	if (argv[2][0] == '*')
	{
		c = A * B;
	}

	if (argv[2][0] == '/')
	{
		c = A / B;
	}

	if (argv[2][0] == '%')
	{
		c = A % B;
	}

	if (file4 != NULL) // ���� ����� ���� � �������, �� ��������� ����� �������� ����� ��������� �� ����� ������
	{
		c = c % mod;
	}

	if (argv[2][0] == '^')
	{
		if (file4 == NULL)
		{
			c = A ^ B;
		}
		else
		{
			c = powModClass(A, B, mod);
		}
	}

	if (bin == 1)
	{
		c.writeToBinFile(file3);
	}
	else
		c.writeToTextFile(file3);
	return 0;
}
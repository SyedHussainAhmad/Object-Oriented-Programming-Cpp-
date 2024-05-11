#include"String.h"
#include<fstream>
#include"Matrix.h"

void swap(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int ** rotateMatrix(int ** file, int rows, int columns)
{
	int** rotatedMat = new int* [columns];
	for (int i = 0; i < columns; i = i + 1)
	{
		rotatedMat[i] = new int[rows];
	}

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			rotatedMat[i][j] = file[j][i];
		}
	}

	int num1 = 0, num2 = rows -1;
	for (int i = 0; i <= rows/2; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			swap(rotatedMat[j][num1], rotatedMat[j][num2]);
		}
		num1++;
		num2--;
	}
	return rotatedMat;
}

void rotateImg()
{
	String fileType;
	String filename;
	int rows, columns, maxValue;

	ifstream ifs;
	ifs.open("Images\\Text Images\\OOPS.pgm");

	if (ifs.is_open())
	{
		ifs >> fileType;
		cout << '\n' << fileType;

		ifs >> filename;
		cout << '\n'<< filename;

		ifs >> rows;
		cout << '\n' << rows;

		ifs >> columns;
		cout << '\n' << columns;

		ifs >> maxValue;
		cout << '\n'<< maxValue;

		int** file = new int* [rows];
		for (int i = 0; i < rows; i = i + 1)
		{
			file[i] = new int[columns];
		}

		int num;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				ifs >> file[i][j];
				cout << file[i][j] << ' ';
			}
		}

		cout << "\n\n\n\n";
		ifs.close();

		file = rotateMatrix(file, rows, columns);
		ofstream ofs;
		ofs.open("Images\\Text Images\\OOPS.pgm");
		ofs << fileType << '\n';
		ofs << filename << '\n';
		ofs << rows << ' ';
		ofs << columns << '\n';
		ofs << maxValue << '\n';

		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				ofs << file[i][j];
				if (file[i][j] >=10)
				{
					ofs << ' ';
				}
				else
				{
					ofs << "  ";
				}
			}
			ofs << "\n";
		}
		ofs.close();
	}
	else
	{
		cout << "File not Found.";
	}
}
int main()
{
	rotateImg();

	//int** file = new int* [4];
	//for (int i = 0; i < 4; i = i + 1)
	//{
	//	file[i] = new int[3];
	//}

	//int num = 1;
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		file[i][j] = num;
	//		num++;
	//	}
	//}

	//file = rotateMatrix(file, 4,3);
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cout << file[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << endl;
	return 0;
}
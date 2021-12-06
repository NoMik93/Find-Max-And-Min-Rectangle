//2013726048 �����
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define MAX 1000

void kadane(int array[], int n, int &x1, int &x2, int &max);

int main()
{
	int size;
	ifstream ifile;
	string fileName;
	int max[MAX], min[MAX];
	int maxi1, maxi2, maxj1, maxj2;//�ִ��� ������ġ�� ����� ����
	int mini1, mini2, minj1, minj2;//�ּڰ��� ������ġ�� ����� ����
	int temp, maxSum, minSum;
	int i, j, k;
	int maxI1, maxI2, minI1, minI2;//�ִ񰪰� �ּڰ��� ��ġ�� ���������� �˾Ƴ��� ���� �Ͻ������� ������ ����
	maxi1 = maxi2 = maxj1 = maxj2 = mini1 = mini2 = minj1 = minj2 = maxSum = minSum = temp = -1;

	while (true)
	{
		printf("���� ��θ� �Է��ϼ���: ");
		cin >> fileName;
		ifile.open(fileName);
		if (ifile.fail())
			printf("���� �̸��̳� ��θ� Ȯ���ϼ���.\n");
		else
			break;
	}

	ifile >> size;
	printf("\n%d x %d ���", size, size);

	int** matrix = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int)*size);
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			ifile >> matrix[i][j];
	}

	for (i = 0; i< size; i++)
	{
		memset(max, 0, sizeof(max));
		memset(min, 0, sizeof(min));

		for (j = i; j<size; j++)
		{
			for (k = 0; k < size; k++)
			{
				max[k] += matrix[j][k];
				min[k] += (-1)*matrix[j][k];
			}
			kadane(max, size, maxI1, maxI2, temp);
			if (temp > maxSum)
			{
				maxj1 = maxI1;
				maxj2 = maxI2;
				maxi1 = i;
				maxi2 = j;
				maxSum = temp;
			}

			kadane(min, size, minI1, minI2, temp);
			if (temp > minSum)
			{
				minj1 = minI1;
				minj2 = minI2;
				mini1 = i;
				mini2 = j;
				minSum = temp;
			}
		}
	}

	printf("\n�ִ�: %d\n(%d, %d), (%d, %d)\n", maxSum, maxi1, maxj1, maxi2, maxj2);
	printf("�ּڰ�: %d\n(%d, %d), (%d, %d)\n", (-1)*minSum, mini1, minj1, mini2, minj2);

	for (int i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	system("pause");
	return 0;
}

void kadane(int array[], int n, int &i, int &j, int &max)
{
	i = j = max = 0;
	int sum = 0, temp = 0;
	for (int k = 0; k < n; k++)
	{
		sum = sum + array[k];
		if (sum > max)
		{
			max = sum;
			i = temp;
			j = k;
		}
		if (sum < 0)
		{
			sum = 0;
			temp = k + 1;
		}
	}
}

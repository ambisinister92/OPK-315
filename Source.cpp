#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <time.h>
using namespace std;
void main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n, dlina = 0, dlina1;
	n = 1 + rand() % 210;
	cout << " ������� ������:" << endl;
	cout << n << endl;
	//n = 5; //��������� ��� ��������
	int *li = new int[n]; // ������ ������. ������ ������� ��� ������� ������� ��� ������ ���������
	int *ri = new int[n]; // ����� ������
	for (int i = 0; i < n; i++)
	{
		ri[i] = 1 + rand() % 109; // ��������� ����� ��������� �����������. ������� ������� ��� ����� ���������� - ��������� �� ����� ���� �����������, ���� �� ���� �� ���������
		li[i] = 0 + rand() % ri[i]; // ��������� ����� ��������� ����������
		cout << li[i] << " " << ri[i] << endl;
	}
	cout << " �������� ������:" << endl;
	for (int i = 0; i < n; i++) // ���� ���� ��� �������� ������ ����������
	{
		dlina = ri[i] - li[i] + 1; // ������� ������ ������ ����������
		int *vremmas = new int[dlina];
		for (int k = 0, g = li[i]; g <= ri[i]; k++, g++) // ������� ������ ������� ������� ������ ���������� � ������
		{
			vremmas[k] = g;
		}
		for (int j = 0; j<n; j++)
		{
			if (j == i) j = j + 1;
			dlina1 = ri[j] - li[j] + 1; // ������� ������ ������� ����������
			int *vremmas2 = new int[dlina1];
			for (int k = 0, g = li[j]; g <= ri[j]; k++, g++)// ������� ������ ������� ������� ������� ���������� � ������
			{
				vremmas2[k] = g;
			}
			for (int t = 0; t<dlina; t++) // ������� ������� ����������� � �������� i-����������. ���� ���� ���������� �� �������� ������, ������ �������� ���� ������ ( ��� � ������� i-����������) ������ �� -1
			{
				for (int yuy = 0; yuy<dlina1; yuy++)
					if (vremmas[t] == vremmas2[yuy])
					{
						vremmas[t] = -1;
						break;
					}
			}
			delete vremmas2;
		}
		for (int yuy = 0, k = dlina; yuy <= k; yuy++) // ��������� ����� �� ��������� ���������. ���� � ������ ������ �������� -1, �� ����� ���������. �����, �������� ����� ����
		{
			if (vremmas[yuy] == -1)
			{
				dlina--;
			}
		}
		if (dlina == 0)
		{
			cout << "�����: " << i + 1 << endl;
			break;
		}
		delete vremmas;
	}
	if (dlina != 0) // ���� ������ ������ ���������
	{
		cout << "����� " << "-1" << endl;
	}
	system("pause");
}
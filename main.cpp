#include <iostream>
#include <stdlib.h>

using namespace std;

class Image
{
private:
	const int Weidth;//���� ��� �������� ������(������) ��������
	const int Lenght;//���� ��� �������� ����� ��������

public:
	//��������� ����� Pixel
	class Pixel
	{
		//���� ���������� ������,�������� �������� ������
		int Red;
		int Green;
		int Blue;
	public:
		//����������� ���������� ������ �� ��������� � ��������������� �������������� �����
		Pixel() :Red{}, Green{}, Blue{} {};
		//����������� ���������� ������ � �����������
		Pixel(int R, int G, int B) { Red = R; Green = G; Blue = B; }
		// ������� ���������� ������ ��� ������� ����
		void SetR(int R) { Red = R; }
		void SetG(int G) { Green = G; }
		void SetB(int B) { Blue = B; }
		//����� ���������� ������ ������ ������� �������
		void SetPixel(int R, int G, int B) { Red = R; Green = G; Blue = B; };
		//������� ���������� ������:
		int GetR()const { return Red; }  //���������� �������� ���� Red
		int GetG()const { return Green; }  //���������� �������� ���� Green
		int GetB()const { return Blue; } //���������� �������� ���� Blue
		//����� ���������� ������ ������ ������� �� �����
		void Show() { cout << "(" << Red << ";" << Green << ";" << Blue << ")"; }
	};

	Pixel** Picture;//������ ��������� ������ ��������(��������)
	//�����������  ����������� ������ � ����� ����������� � �������������� ������
	Image(int W, int L) :Weidth{ W }, Lenght{ L }
	{
		//������������ ��������� ������ � ���������� ������
		Picture = new Pixel * [Weidth] {};
		for (int i = 0; i < Weidth; i++)
		{
			Picture[i] = new Pixel[Lenght];
		}
		//�������� ��������� ������
		if (!Picture)
		{
			cout << "������ ��������� ������!" << endl;
			exit(1); //����� �� ���������
		}
	}
	//����� ����������� ������ ���������� ���������� �������(��������) ��������� ���������� ���������� �� 1 �� 255
	//����� ������� ���������� ������
	void FillRandImage()
	{
		for (int i = 0; i < Weidth; i++)
		{
			for (int j = 0; j < Lenght; j++)
			{
				Picture[i][j].SetR(rand() % (256 - 1) + 1);
				Picture[i][j].SetG(rand() % (256 - 1) + 1);
				Picture[i][j].SetB(rand() % (256 - 1) + 1);
			}
			cout << endl;
		}
	}
	//����� ���������� ���������� �������(��������) c ������� ����� ������� ���������� ������
	void FillImage()
	{
		for (int i = 0; i < Weidth; i++)
		{
			for (int j = 0; j < Lenght; j++)
			{
				int R, G, B;//���������� ��� �������� �������� ��������
				cout << "������� �������� Red �� 1 �� 256: ";
				//�������� ����� ������ ����
				cin >> R;
				cout << "������� �������� Green �� 1 �� 256: ";
				cin >> G;
				cout << "������� �������� Blue �� 1 �� 256: ";
				cin >> B;
				Picture[i][j].SetR(R);
				Picture[i][j].SetG(G);
				Picture[i][j].SetB(B);
			}
			cout << endl;
		}
	}
	//����� ����������� ������ ������ �� ����� ����� �������(��������) ����� ����� ������ �� ����� ���������� ������
	void Display()const
	{
		for (int i = 0; i < Weidth; i++)
		{
			for (int j = 0; j < Lenght; j++)
			{
				Picture[i][j].Show();
			}
			cout << endl;
		}
	}
	//����� ����������� ������ ��������� ����������� ������� ����� ����� ���������� ������ ������ ������� �������
	void �hangePixel()const
	{
		int Row, Col;//���������� ��� �������� ������ ������ � �������
		int R, G, B;// ���������� ��� �������� �������� ��������
		//�������� ����� ������ ����
		cout << "������� ����� �������: " << endl;
		cin >> Col;
		cout << "������� ����� ������: " << endl;
		cin >> Row;
		cout << "������� �������� Red �� 1 �� 256: ";
		cin >> R;
		cout << "������� �������� Green �� 1 �� 256: ";
		cin >> G;
		cout << "������� �������� Blue �� 1 �� 256: ";
		cin >> B;
		for (int i = 0; i < Weidth; i++)
		{
			for (int j = 0; j < Lenght; j++)
			{
				if (i == (Row - 1) && j == (Col - 1))
				{
					Picture[i][j].SetPixel(R, G, B);
					break;
				}
			}
			cout << endl;
		}
	}
	//���������� ����������� ������
	~Image()
	{
		//������������ ������
		for (int i = 0; i < Weidth; i++)
		{
			delete[] Picture[i];
			Picture[i] = nullptr;
		}
		delete[] Picture;
		Picture = nullptr;
	}
};
int main()
{
	system("chcp 1251");
	system("cls");
	srand((unsigned int)time(nullptr));
	Image::Pixel A(7, 8, 9);
	A.Show();
	cout << endl;
	cout << A.GetB();
	cout << endl;
	A.SetG(18);
	cout << A.GetG();
	cout << endl;
	A.Show();
	cout << endl;
	Image Im(4, 4);
	Im.Display();
	Im.FillRandImage();
	//Im.FillImage();
	Im.Display();
	Im.�hangePixel();
	Im.Display();
}
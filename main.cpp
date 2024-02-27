#include <iostream>
#include <stdlib.h>

using namespace std;

class Image
{
private:
	const int Weidth;//поле для хранения ширины(высоты) картинки
	const int Lenght;//поле для хранения длины картинки

public:
	//вложенный класс Pixel
	class Pixel
	{
		//поля вложенного класса,хранящие значения цветов
		int Red;
		int Green;
		int Blue;
	public:
		//конструктор вложенного класса по умолчанию с унифицированной инициализацией полей
		Pixel() :Red{}, Green{}, Blue{} {};
		//конструктор вложенного класса с параметрами
		Pixel(int R, int G, int B) { Red = R; Green = G; Blue = B; }
		// сеттеры вложенного класса для каждого поля
		void SetR(int R) { Red = R; }
		void SetG(int G) { Green = G; }
		void SetB(int B) { Blue = B; }
		//метод вложенного класса задать пиксель целиком
		void SetPixel(int R, int G, int B) { Red = R; Green = G; Blue = B; };
		//геттеры вложенного класса:
		int GetR()const { return Red; }  //возвращает значение поля Red
		int GetG()const { return Green; }  //возвращает значение поля Green
		int GetB()const { return Blue; } //возвращает значение поля Blue
		//метод вложенного класса вывода пикселя на экран
		void Show() { cout << "(" << Red << ";" << Green << ";" << Blue << ")"; }
	};

	Pixel** Picture;//хранит двумерный массив пикселей(картинка)
	//конструктор  объемлющего класса с двумя параметрами и инициализацией нулями
	Image(int W, int L) :Weidth{ W }, Lenght{ L }
	{
		//динамическое выделение памяти и заполнение нулями
		Picture = new Pixel * [Weidth] {};
		for (int i = 0; i < Weidth; i++)
		{
			Picture[i] = new Pixel[Lenght];
		}
		//проверка выделения памяти
		if (!Picture)
		{
			cout << "Ошибка выделения памяти!" << endl;
			exit(1); //выход из программы
		}
	}
	//метод объемлющего класса заполнения двумерного массива(картинки) пикселями случайными значениями от 1 до 255
	//через сеттеры вложенного класса
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
	//метод заполнения двумерного массива(картинки) c консоли через сеттеры вложенного класса
	void FillImage()
	{
		for (int i = 0; i < Weidth; i++)
		{
			for (int j = 0; j < Lenght; j++)
			{
				int R, G, B;//переменные для хранения вводимых значений
				cout << "Введите значение Red от 1 до 256: ";
				//проверка ввода должна быть
				cin >> R;
				cout << "Введите значение Green от 1 до 256: ";
				cin >> G;
				cout << "Введите значение Blue от 1 до 256: ";
				cin >> B;
				Picture[i][j].SetR(R);
				Picture[i][j].SetG(G);
				Picture[i][j].SetB(B);
			}
			cout << endl;
		}
	}
	//метод объемлющего класса вывода на экран всего массива(картинки) через метод вывода на экран вложенного класса
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
	//метод объемлющего класса изменение конкретного пикселя через метод вложенного класса задать пиксель целиком
	void СhangePixel()const
	{
		int Row, Col;//переменные для хранения номера строки и столбца
		int R, G, B;// переменные для хранения вводимых значений
		//проверка ввода должна быть
		cout << "Введите номер столбца: " << endl;
		cin >> Col;
		cout << "Введите номер строки: " << endl;
		cin >> Row;
		cout << "Введите значение Red от 1 до 256: ";
		cin >> R;
		cout << "Введите значение Green от 1 до 256: ";
		cin >> G;
		cout << "Введите значение Blue от 1 до 256: ";
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
	//деструктор объемлющего класса
	~Image()
	{
		//освобождение памяти
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
	Im.СhangePixel();
	Im.Display();
}
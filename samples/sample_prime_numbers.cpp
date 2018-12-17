
#include <iomanip>

 #define USE_SET // Использовать класс TSet,
                // закоментировать, чтобы использовать битовое поле

#ifndef USE_SET // Использовать класс TBitField

#include "tbitfield.h"

int main()
{
  int n, m, k, count, ExampleElem;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки битового поля" << endl;
  cout << "             Решето Эратосфена" << endl;
  cout << "Введите верхнюю границу целых значений - ";
  cin  >> n;
  TBitField s(n + 1); // заполнение множества
  for (m = 2; m <= n; m++)
    s.SetBit(m); // проверка до sqrt(n) и удаление кратных
  for (m = 2; m * m <= n; m++) // если m в s, удаление кратных
    if (s.GetBit(m))
      for (k = 2 * m; k <= n; k += m)
        if (s.GetBit(k))
          s.ClrBit(k); // оставшиеся в s элементы - простые числа
  cout << endl << "Печать множества некратных чисел" << endl << s << endl;
  cout << endl << "Печать простых чисел" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.GetBit(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "В первых " << n << " числах " << count << " простых" << endl;

	cout << "\n\n\tВвод битовой строки\n";
	cout << "Введите размер битовой строки\n";
	cin >> ExampleElem;
	TBitField bit(ExampleElem);
	cout << "Введите битовую строку длинной " << ExampleElem << "\n";
	cin >> bit;
	cout << "\nВаша битовая строка\n";
	cout << bit;
	cout << "\n\nМножество чисел битовой строки\n";
	for (m = 0; m < ExampleElem; m++)
		if (bit.GetBit(m))
			cout << setw(3) << m << " ";
}
#else

#include "tset.h"

int main()
{
	int n, m, k, count, ExampleElem;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки множества" << endl;
  cout << "              Решето Эратосфена" << endl;
  cout << "Введите верхнюю границу целых значений - ";
  cin  >> n;
  TSet s(n + 1); // заполнение множества
  for (m = 2; m <= n; m++)
    s.InsElem(m); // проверка до sqrt(n) и удаление кратных
  for (m = 2; m * m <= n; m++) // если м в s, удаление кратных
    if (s.IsMember(m))
      for (k = 2 * m; k <= n; k += m)
       if (s.IsMember(k))
         s.DelElem(k); // оставшиеся в s элементы - простые числа
  cout << endl << "Печать множества некратных чисел" << endl << s << endl;
  cout << endl << "Печать простых чисел" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.IsMember(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "В первых " << n << " числах " << count << " простых" << endl;

	cout << "\n\n\tВвод множества целых чисел\n";
	cout << "Введите наибольший элемент множества\n";
	cin >> ExampleElem;
	TSet bit(ExampleElem + 1);
	cout << "Введите элементы множества. Для завершения ввода введите -1 или число более максимального\n";
	cin >> bit;
	cout << "\nВаше множество в представлении битовой строки\n";
	cout << bit;
	cout << "\n\nВаше множество в целых числах\n";
	for (m = 0; m <= ExampleElem; m++)
		if (bit.IsMember(m))
			cout << setw(3) << m << " ";
}

#endif
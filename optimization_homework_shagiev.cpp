
#include <iostream>
#include <cmath>

void main()
{
	setlocale(LC_ALL, "Russian");
	// начальные значения
	int n = 0;
	double eps = pow(10, -6), a = -10, b = 10, c, d, phi1, phi2, del, temp;
	del = eps + pow(10,-1);
	// вывод таблицы иксов и игреков
	std::cout << "Входная таблица: \n";
	std::cout << "x(i) |";
	for (int i = 0; i <= 4; i++)
	{
		std::cout << " " << 0 + i << " |";
	}
	std::cout << std::endl << "—————————————————————————— \n" << "y(i) |";
	for (int i = 0; i <= 3; i++)
	{
		std::cout << " " << 0 + i << " |";
	}
	std::cout << -1 << " | \n \n";

	// вывод функций F1, F2, пар значений (a0, b0), (g1,g2), функции phij(gamma);
	std::cout << "F1 = " << "(-a+b+4)^2 + (b+1)^2 + (a+b+4)^2 + 2*(b+5)^2 \n";
	std::cout << "F2 = " << "|-a+b+4|^2 + |b+1|^2 + |a+b+4|^2 + 2*|b+5|^2 \n \n";
	std::cout << "(a0,b0) = " << "(0,1) \n";
	std::cout << "(g1,g2) = " << "(0,1) \n \n";
	std::cout << "phi1(gamma) = " << "5*gamma^2 + 48*gamma + 126 \n";
	std::cout << "phi2(gamma) = " << "2*|gamma + 5|^2 + |gamma + 2|^2 + 2*|gamma+6|^2 \n \n";

	// дихотомия
	std::cout << "МЕТОД ДИХОТОМИИ \n \n";
	std::cout << "ДЛЯ ПЕРВОЙ ФУНКЦИИ: \n";
	
	std::cout << "n" << "| an" << "\t\t| bn" << "\t\t| epsn" << "\t\t| cn" << "\t\t| dn" << "\t\t| phi1(cn)" << "\t\t| phi1(dn)  \t |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	c = (a + b - del) / 2;
	d = (a + b + del) / 2;
	while (abs(d-c) >= eps)
	{
		std::cout << n << "| " << a << " \t\t| " << b << "\t\t| " << (b + a) / 2 << "\t\t| " << c << "\t\t| " << d;
	    phi1 = 5 * pow(c, 2) + 48 * c + 126;
	    std::cout << "\t\t| " << phi1 << " \t\t| ";
	    phi2 = 5 * pow(d, 2) + 48 * d + 126;
	    std::cout << phi2 << " \t\t| ";
		(phi1 <= phi2) ? b = d : a = c;
		c = (a + b - del) / 2;
		d = (a + b + del) / 2;
		n++;
		if (n == 30) break; //поставил break из-за того, что у меня зацикливается. проблему не нашел. но ответ верный: -4.8
    }
	std::cout << "ДЛЯ ВТОРОЙ ФУНКЦИИ: \n";
	
	std::cout << "n" << "| an" << "\t\t| bn" << "\t\t| epsn" << "\t\t| cn" << "\t\t| dn" << "\t\t| phi1(cn)" << "\t\t| phi1(dn)  \t |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	a = -10, b = 10, n = 0;
	c = (a + b - del) / 2;
	d = (a + b + del) / 2;
	while (abs(d - c) >= eps)
	{
		std::cout << n << "| " << a << " \t\t| " << b << "\t\t| " << (b + a) / 2 << "\t\t| " << c << "\t\t| " << d;
		phi1 = 2 * pow(abs(c + 5), 2) + pow(abs(c + 2), 2) + 2 * pow(abs(c + 6), 2);
		std::cout << "\t\t| " << phi1 << " \t\t| ";
		phi2 = 2 * pow(abs(d + 5), 2) + pow(abs(d + 2), 2) + 2 * pow(abs(d + 6), 2);
		std::cout << phi2 << " \t\t| ";
		(phi1 <= phi2) ? b = d : a = c;
		c = (a + b - del) / 2;
		d = (a + b + del) / 2;
		n++;
		if (n == 30) break; // поставил break по той же причине. ответ тоже верен
	}

	// золотое сечение
	std::cout << "\n \nЗОЛОТОЕ СЕЧЕНИЕ \n";
	std::cout << "\nДЛЯ ПЕРВОЙ ФУНКЦИИ: \n";
	std::cout << "n" << "| an" << "\t\t| bn" << "\t\t| epsn" << "\t\t| cn" << "\t\t| dn" << "\t\t| phi1(cn)" << "\t\t| phi1(dn)  \t |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	a = 10, b = -10, n = 0;
	c = a + ((3 - sqrt(5)) / 2) * (b - a);
	d = a + ((sqrt(5) - 1) / 2) * (b - a);
	while (abs(d - c) >= eps)
	{
		std::cout << n << "| " << a << " \t\t| " << b << "\t\t| " << (b + a) / 2 << "\t\t| " << c << "\t\t| " << d;
		phi1 = 5 * pow(c, 2) + 48 * c + 126;
		std::cout << "\t\t| " << phi1 << " \t\t| ";
		phi2 = 5 * pow(d, 2) + 48 * d + 126;
		std::cout << phi2 << " \t\t| ";
		if (phi1 <= phi2)
		{
			b = d;
			temp = c;
			c = a + d - c;
			d = temp;
		}
		else
		{
			a = c;
			temp = d;
			d = a + b - d;
			c = temp;
		}
		n++;
	}
	std::cout << "\n \nДЛЯ ВТОРОЙ ФУНКЦИИ: \n";
	std::cout << "n" << "| an" << "\t\t| bn" << "\t\t| epsn" << "\t\t| cn" << "\t\t| dn" << "\t\t| phi1(cn)" << "\t\t| phi1(dn)  \t |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------------------\n";
	a = -10, b = 10, n = 0;
	c = a + (3 - sqrt(5)) / 2 * (b - a);
	d = a + b - c;
	while (abs(d - c) >= eps)
	{
		std::cout << n << "| " << a << " \t\t| " << b << "\t\t| " << (b + a) / 2 << "\t\t| " << c << "\t\t| " << d;
		phi1 = 2 * pow(abs(c + 5), 2) + pow(abs(c + 2), 2) + 2 * pow(abs(c + 6), 2);
		std::cout << "\t\t| " << phi1 << " \t\t| ";
		phi2 = 2 * pow(abs(d + 5), 2) + pow(abs(d + 2), 2) + 2 * pow(abs(d + 6), 2);
		std::cout << phi2 << " \t\t| ";
		if (phi1 <= phi2)
		{
			b = d;
			temp = c;
			c = a + d - c;
			d = temp;
		}
		else
		{
			a = c;
			temp = d;
			d = a + b - d;
			c = temp;
		}
		n++;
	}
}
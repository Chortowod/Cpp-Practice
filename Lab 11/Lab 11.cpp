#include "Time.h"


class Distance
{
private:
	int feet;
	float inches;
	const float MTF = 3.280833F;
public:
	// конструктор по умолчанию
	Distance() : feet(0), inches(0.0) { }
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in) { }
	// конструктор для вещественного типа
	Distance(float meters)
	{
		float fltfeet = MTF * meters;	// перевод в футы
		feet = int(fltfeet);			// число полных футов
		inches = 12 * (fltfeet - feet); // остаток - это дюймы
	}

	void Normalize()
	{
		if (inches >= 12.0)
		{
			feet += static_cast<int>(inches) / 12;
			inches = fmod(inches, 12);
		}
	}
	void getdist()
	{
		cout << "\nВведите число футов: ";
		cin >> feet;
		cout << "\nВведите число дюймов: ";
		cin >> inches;
		Normalize();
	}
	void showdist()
	{
		cout << feet << "\' " << inches << "\"\n";
	}
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
	}
	Distance operator+= (const Distance &d2)
	{
		*this = *this + d2;
		return *this;
	}
	Distance operator+= (const float &m)
	{
		*this = *this + m;
		return *this;
	}
	Distance operator= (const Distance &d2)
	{
		feet = d2.feet;
		inches = d2.inches;
		return *this;
	}
	friend Distance operator+ (const Distance &d1, const Distance &d2);
	friend Distance operator+ (const Distance &d1, const float &m);
	friend Distance operator+ (const float &m, const Distance &d2);
	friend Distance operator- (const Distance &d1, const Distance &d2);
	friend Distance operator- (const float &m, const Distance &d2);
	friend Distance operator- (const Distance &d1, const float &m);
	friend ostream &operator<< (ostream &out, const Distance &dist);
};

Distance operator+ (const Distance &d1, const Distance &d2)
{
	Distance temp;
	temp.feet = d1.feet + d2.feet;
	temp.inches = d1.inches + d2.inches;
	temp.Normalize();
	return temp;
}
Distance operator+ (const Distance &d1, const float &m)
{
	Distance d2 = m;
	return d1 + d2;
}
Distance operator+ (const float &m, const Distance &d2)
{
	Distance d1 = m;
	return d1 + d2;
}
Distance operator- (const Distance &d1, const Distance &d2)
{
	if (d1.feet < d2.feet)
		return Distance();
	else if (d1.feet == d2.feet) 
	{
		if (d1.inches < d2.inches)
			return Distance();
	}
	float i; int f;
	if (d1.inches >= d2.inches)
	{
		i = d1.inches - d2.inches;
		f = d1.feet - d2.feet;
	} 
	else
	{
		i = d1.inches - d2.inches + 12;
		f = d1.feet - d2.feet - 1;
	}
	return Distance(f, i);
}
Distance operator- (const float &m, const Distance &d2)
{
	Distance d1 = m;
	return d1 - d2;
}
Distance operator- (const Distance &d1, const float &m)
{
	Distance d2 = m;
	return d1 - d2;
}
ostream &operator<< (ostream &out, const Distance &dist)
{
	out << dist.feet << "\' " << dist.inches << "\"\n";
	return out;
}

void lab11_1()
{
	Distance distBig, distSmol, distBigPlusSmol, distBigMinusSmol, distFloat,
		distFloatCopy, distPlusRavnoFloat, distPlusRavnoDistSmal, distFloatMinusDistSmol,
		distBigPlusFloat, distFloatPlusBigDist, distFloatPlusDistSmol, distSmolPlusFloat;
	distBig.getdist();
	distSmol.getdist();
	distBigPlusSmol = distBig + distSmol;
	distBigMinusSmol = distBig - distSmol;
	distFloat = 2.35F;
	distFloatCopy = distFloat;
	float floatFromDistFloat = static_cast<float>(distFloat);
	distPlusRavnoFloat = distFloatCopy;
	distPlusRavnoFloat += floatFromDistFloat;
	distPlusRavnoDistSmal = distFloatCopy;
	distPlusRavnoDistSmal += distSmol;
	distFloatMinusDistSmol = floatFromDistFloat - distSmol;
	distBigPlusFloat = distBig + floatFromDistFloat;
	distFloatPlusBigDist = floatFromDistFloat + distBig;
	distFloatPlusDistSmol = floatFromDistFloat + distSmol;
	distSmolPlusFloat = distSmol + floatFromDistFloat;
	cout << "\ndistBig = " << distBig;
	cout << "\ndistSmol = " << distSmol;
	cout << "\ndistBigPlusSmol = " << distBigPlusSmol;
	cout << "\ndistBigMinusSmol = " << distBigMinusSmol;
	cout << "\ndistFloat (2.35F) = " << distFloat;
	cout << "\ndistFloatCopy = " << distFloatCopy;
	cout << "\nfloatFromDistFloat = " << floatFromDistFloat << endl;
	cout << "\ndistPlusRavnoFloat = " << distPlusRavnoFloat;
	cout << "\ndistPlusRavnoDistSmal = " << distPlusRavnoDistSmal;
	cout << "\ndistFloatMinusDistSmol = " << distFloatMinusDistSmol;
	cout << "\ndistBigPlusFloat = " << distBigPlusFloat;
	cout << "\ndistFloatPlusBigDist = " << distFloatPlusBigDist;
	cout << "\ndistFloatPlusDistSmol = " << distFloatPlusDistSmol;
	cout << "\ndistSmolPlusFloat = " << distSmolPlusFloat;
}

void lab11_itog()
{
	try 
	{
		Time tSmall, tBig, tBigPlusSmall, tBigMinusSmall, tEntered;
		tSmall = 3.554;
		tBig = 23;
		tBigPlusSmall = tBig + tSmall;
		tBigMinusSmall = tBig - tSmall;
		cout << "\nВведите время в формате чч:мм или чч:мм:сс и нажимте Enter: ";
		cin >> tEntered;
		cout << "\n\ntSmall: " << tSmall;
		cout << "tBig: " << tBig;
		cout << "tBigPlusSmall: " << tBigPlusSmall;
		cout << "tBigMinusSmall: " << tBigMinusSmall;
		cout << "tEntered: " << tEntered;
		
		
		
		//Time t1 = 5;
		//Time *t2 = new Time(15, 34, 32);
		//Time t3 = 25.5756;
		//Time t4, t5;
		//cout << "\nВведите время в формате чч:мм или чч:мм:сс и нажимте Enter: ";
		//cin >> t4;
		//t5 = t1 + t3;
		//double timeD = static_cast<double>(t1);
		//double timeD2 = static_cast<double>(*t2);
		//cout << t1;
		//cout << *t2;
		//cout << t3;
		//cout << t4;
		//cout << t5;
		//delete t2;
	}
	
	catch (Time::ExScore ex) { cout << "\nОшибка инициализации: " << ex.origin; }
}

int main()
{
	system("chcp 1251");
	lab11_itog();
	
	
}
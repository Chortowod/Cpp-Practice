#include "time.h"

Time::ExScore::ExScore(string orig) : origin(orig) {}
Time::Time()
{
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
}
Time::Time(int h)
{
	days = 0;
	hours = h;
	minutes = 0;
	seconds = 0;
	Check();
}
Time::Time(double t)
{	// Целое - это часы, остаток * 100 - минуты, остаток * 100 - секунды
	days = 0;
	if (t >= 24.0)
	{
		days += static_cast<int>(t) / 24;
		t = fmod(t, 24);
	}
	hours = static_cast<int>(t);
	double min = (t - hours) * 100;
	min = 3.0 * min / 5.0;
	minutes = static_cast<int>(min);
	double sec = (min - minutes) * 100;
	sec = 3.0 * sec / 5.0;
	seconds = static_cast<int>(sec);
}
Time::Time(int hrs, int mnts)
{
	days = 0;
	hours = hrs;
	minutes = mnts;
	seconds = 0;
	Check();
}
Time::Time(int hrs, int mnts, int scnds)
{
	days = 0;
	hours = hrs;
	minutes = mnts;
	seconds = scnds;
	Check();
}
Time::operator double() const
{	// Перевод в часы (часы это *.000, минуты и секунды это 0.***)
	double h = 24 * days + hours + (minutes / 60.0) + (seconds / 3600.0);
	return h;
}
void Time::Check()
{
	if (seconds > 59)
	{
		minutes += seconds / 60;
		seconds %= 60;
	}
	if (minutes > 59)
	{
		hours += minutes / 60;
		minutes %= 60;
	}
	if (hours > 23)
	{
		days += hours / 24;
		hours %= 24;
	}
}
int Time::ToSeconds() const
{
	return seconds + minutes * 60 + hours * 3600 + days * 216000;
}
Time Time::operator= (const Time &t2)
{
	days = t2.days;
	hours = t2.hours;
	minutes = t2.minutes;
	seconds = t2.seconds;
	return *this;
}
Time operator+ (const Time &t1, const Time &t2)
{
	Time t;
	t.hours = t1.hours + t2.hours;
	t.minutes = t1.minutes + t2.minutes;
	t.seconds = t1.seconds + t2.seconds;
	t.days = t1.days + t2.days;
	t.Check();
	return t;
}
Time operator+ (const Time &t1, const double &h)
{
	Time t2 = h;
	return t1 + t2;
}
Time operator+ (const double &h, const Time &t2)
{
	Time t1 = h;
	return t1 + t2;
}
Time operator- (const Time &t1, const Time &t2)
{	// Обычное вычитание занимало очень много кода и было много проверок, поэтому:
	// Переводим Time в секунды, находим разность, преобразовываем в Time
	if (t1 < t2)
		throw Time::ExScore("\nУменьшаемое должно быть больше вычитаемого\n");
	Time t;
	t.seconds = t1.ToSeconds() - t2.ToSeconds();
	t.Check();
	return t;
}
Time operator- (const double &h, const Time &t2)
{
	Time t1 = h;
	return t1 - t2;
}
Time operator- (const Time &t1, const double &h)
{
	Time t2 = h;
	return t1 - t2;
}
bool operator> (const Time &t1, const Time &t2)
{
	if (t1.days > t2.days)
		return true;
	if (t1.days < t2.days)
		return false;
	if (t1.hours > t2.hours)
		return true;
	if (t1.hours < t2.hours)
		return false;
	if (t1.minutes > t2.minutes)
		return true;
	if (t1.minutes < t2.minutes)
		return false;
	return (t1.seconds > t2.seconds) ? true : false;
}
bool operator< (const Time &t1, const Time &t2)
{
	return t2 > t1;
}
bool operator>= (const Time &t1, const Time &t2)
{
	if (t1.days > t2.days)
		return true;
	if (t1.days < t2.days)
		return false;
	if (t1.hours > t2.hours)
		return true;
	if (t1.hours < t2.hours)
		return false;
	if (t1.minutes > t2.minutes)
		return true;
	if (t1.minutes < t2.minutes)
		return false;
	return (t1.seconds >= t2.seconds) ? true : false;
}
bool operator<= (const Time &t1, const Time &t2)
{
	return t2 >= t1;
}
ostream &operator<< (ostream &out, const Time &t)
{
	(t.hours < 10) ? out << "0" << t.hours : out << t.hours;
	(t.minutes < 10) ? out << ":0" << t.minutes : out << ":" << t.minutes;
	(t.seconds < 10) ? out << ":0" << t.seconds : out << ":" << t.seconds;
	if (t.days > 0)
		out << " + " << t.days << " day(s)";
	out << "\n";
	return out;
}
istream &operator>> (istream &in, Time &t)
{
	string time;
	int values[3]{ 0, 0, 0 };
	getline(in, time);
	// Если строка содержит что-то помимо цифр и ":" --> исключение
	if (time.find_first_not_of("0123456789:") != string::npos)
		throw Time::ExScore("Строка содержит недопустимые символы");

	// чтобы заранее знать, сколько раз проходиться по циклу
	int n = count(time.begin(), time.end(), ':');

	for (int i = 0; i <= n && i < 3; i++)
	{
		// для обрезки строки используем pos в качестве конца подстроки
		int pos = time.find(":");
		// отрезаем от начала строки до ":" в новую переменную
		string val = time.substr(0, pos);
		if (val == "")
			// Если между начальной позицией и ":" ничего нет --> исключение
			throw Time::ExScore("Пропущен ввод одной из величин");
		if (val.length() > 7)
			// Если одно из значений оказывается слишком большим --> исключение
			throw Time::ExScore("Введенное значение слишком велико");
		// присваиваем элементу массива конвертированную в int строку
		values[i] = stoi(val);
		// отрезаем от начала строки до ":" для следующего цикла
		time.erase(0, pos + 1);
	}
	t.hours = values[0];
	t.minutes = values[1];
	t.seconds = values[2];
	t.Check();
	return in;
}
Time::~Time() { cout << "\n-------------------Объект Time [" << &*this << "] уничтожен-------------------"; }
#include <iostream>

template <class T>
void ShowArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
template <class T>
void Sorting(T arr[], int size) 
{
	int j = 0;
	for (int i = 0; i < size; i++) 
	{
		T x = arr[i];
		for (j = i - 1; j >= 0 && x < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
}
void sorting_old(int arr[], int size) 
{
	int j = 0;
	for (int i = 0; i < size; i++) 
	{
		int x = arr[i];
		for (j = i - 1; j >= 0 && x < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
}
template <typename T, typename T1>
class array
{
public:
	array(int size) {
		data = new T[size];
		if (data == NULL)
		{
			std::cerr << "Error memory ---- exit program" << std::endl;
			exit(1);
		}
		array::size = size;
		array::index = 0;
	};
	T1 sum()
	{
		T1 sum = 0;
		for (int i = 0; i < index; i++) sum += data[i];
		return(sum);
	}
	T average_value();
	void show_array();
	int add_value(T);
private:
	T *data;
	int size;
	int index;
};
template<class T, class T1> 
T array<T, T1>::average_value()
{
	T1 sum = 0;
	for (int i = 0; i < index; i++) 
		sum += data[i];
	return (sum / index);
}
template<class T, class T1> 
void array<T, T1>::show_array()
{
	for (int i = 0; i < index; i++) std::cout << data[i] << ' ';
	std::cout << std::endl;
}
template<class T, class T1> 
int array<T, T1>::add_value(T value)
{
	if (index == size)
		return(-1);
	else
	{
		data[index] = value;
		index++;
		return(0);
	}
}

template <class T>
T GetArrayAverage(T arr[], int size)
{
	T sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return (sum / size);
}


void lab14_1() 
{
	int arr[] = { 9,3,17,6,5,4,31,2,12 };
	double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
	char arrc[] = "Hello, word";
	int k1 = sizeof(arr) / sizeof(arr[0]);
	int k2 = sizeof(arrd) / sizeof(arrd[0]);
	int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;
	Sorting(arr, k1); ShowArray(arr, k1);
	Sorting(arrd, k2); ShowArray(arrd, k1);
	Sorting(arrc, k3); ShowArray(arrc, k1);
}

void lab14_2() 
{
	array<int, long> numbers(100);
	array<float, float> values(200);
	int i;
	for (i = 0; i < 50; i++) 
		numbers.add_value(i);
	numbers.show_array();
	std::cout << "Sum = " << numbers.sum() << std::endl;
	std::cout << "Average = " << numbers.average_value() << std::endl;
	for (i = 0; i < 100; i++) 
		values.add_value(i * 100);
	values.show_array();
	std::cout << "Sum = " << values.sum() << std::endl;
	std::cout << "Average = " << values.average_value() << std::endl;
}

void lab14_itog()
{
	const int size = 16;
	int ints[size];
	double doubles[size];
	long longs[size];
	long long longlongs[size];
	char chars[size];
	for (int i = 0; i < size; i++)
	{
		ints[i] = i;
		doubles[i] = i + 0.01;
		longs[i] = i + 100000000;
		longlongs[i] = i + 1000000000000000;
		chars[i] = 'а' + i;
	}
	int k1 = sizeof(ints) / sizeof(ints[0]);
	int k2 = sizeof(doubles) / sizeof(doubles[0]);
	int k3 = sizeof(longs) / sizeof(longs[0]);
	int k4 = sizeof(chars) / sizeof(chars[0]) - 1;
	int k5 = sizeof(longlongs) / sizeof(longlongs[0]) - 1;
	std::cout << "Average int = " << GetArrayAverage(ints, k1) << std::endl;
	std::cout << "Average double = " << GetArrayAverage(doubles, k2) << std::endl;
	std::cout << "Average long = " << GetArrayAverage(longs, k3) << std::endl;
	std::cout << "Average longlong = " << GetArrayAverage(longlongs, k5) << std::endl;
	std::cout << "Average char = " << GetArrayAverage(chars, k4) << std::endl;
}



int main()
{
	system("chcp 1251");
	lab14_itog();
}

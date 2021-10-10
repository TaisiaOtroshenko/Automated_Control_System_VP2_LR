#include "Func.h"

template<typename Type>
void Sort(vector <Type> arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		for (size_t j = 0; j < arr.size(); ++j)
		{
			if (arr[j] > arr[i])
			{
				Type tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

template<typename Type>
void Filter(vector <Type> arr)
{
	//выводит элементы массива с выбранным индексом
	size_t par{};
	cout << "\n¬ведите значение параметра (id) дл€ фильтрации:" << endl;
	cin >> par;

	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i].GetId()==par)
		arr[i].Print();
	}
}

template<typename Type>
void Del(vector<Type> arr)
{
	size_t id{};
	cout << "\n¬ведите id элемента, который хотите удалить:" << endl;
	cin >> id;

	for (int i = 0; i < arr.size(); ++i)
	{
		if (id == arr[i].GetId())
		{
			arr.erase(arr.begin() + i);
			cout << "Ёлемент успешно удален" << endl;
			break;
		}
	}
}

template<typename Type>
void Add(vector <Type> arr)
{
	Type tmp{};
	tmp.In();
	arr.push_back(tmp);
}

template<typename Type>
void Edit(vector <Type> arr)
{
	size_t id{};
	cout << "\n¬ведите id элемента, который хотите  редактировать:" << endl;
	cin >> id;

	Type tmp{};
	arr[id].Print();
	cout << "¬едите новые данные" << endl;
	tmp.In();
	arr[id] = tmp;
}
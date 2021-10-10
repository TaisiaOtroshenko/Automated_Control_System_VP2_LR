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
	cout << "\nВведите значение параметра (id) для фильтрации:" << endl;
	cin >> par;

	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i].m_id==par)
		arr[i].Print();
	}
}

template<typename Type>
void Del(vector<Type> arr)
{
	size_t id{};
	cout << "\nВведите id элемента, который хотите удалить:" << endl;
	cin >> id;

	for (int i = 0; i < arr.size(); ++i)
	{
		if (id == arr[i].GetId())
		{
			arr.erase(arr.begin() + i);
			cout << "Элемент успешно удален" << endl;
			break;
		}
	}
	/*
	// поиск номера элемента с заданным id
	bool have = false;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i].m_id == id)
		{
			have = true;
			id = i;
			break;
		}
	}
	//удаление
	if (!have)
	{
		cout << "Нет элементов с таким индексом" << endl;
	}
	else
	{
		for (size_t i = id; i < arr.size() - 1; ++i)
		{
			arr[i] = arr[i + 1];
		}
		arr.pop_back();
	}
	*/
}

template<typename Type>
void Add(vector <Type> arr)
{
	Type tmp{};
	tmp.In();
	cin << tmp;
	arr.push_back(tmp);
}

template<typename Type>
void Edit(vector <Type> arr)
{
	size_t id{};
	cout << "\nВведите id элемента, который хотите  редактировать:" << endl;
	cin >> id;

	Type tmp{};
	cout << arr[id];
	cout << "Ведите новые данные" << endl;
	tmp.In();
	arr[id] = tmp;
}

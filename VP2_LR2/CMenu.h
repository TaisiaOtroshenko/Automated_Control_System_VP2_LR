#pragma once
#include "ItemMenu.h"

typedef void(*void_func)();

namespace otv
{
	class CMenu
	{
	private:
		int m_select = -1; // последний ввод пользователя
		string m_title{}; // ссылка на C-строку -- заголовок меню
		size_t m_count = 0; //колличество пунктов меню 
		ItemMenu* m_items{}; // указатель на массив объектов абстрактного класса ItemMenu
		void_func m_func_save{}; // функция выгрузки данных во время завершения работы

	public:
		CMenu(string title, ItemMenu* items, size_t item_count, void_func func_exit);

		int GetSelect() const;
		string GetTitle() const;
		size_t GetCount() const;
		ItemMenu* GetItems() const;

		void Print() const;
		void RunCommand();
		friend ostream& operator<< (ostream& out, const CMenu& m);
		friend istream& operator>> (istream& in, CMenu& m);
	};
}
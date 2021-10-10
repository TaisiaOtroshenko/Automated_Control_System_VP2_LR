#include <iostream>
#include "CMenu.h"

using namespace std;
namespace otv
{
    CMenu::CMenu(string title, ItemMenu* items, size_t item_count, void_func func_save)
    {
        m_title = title;
        m_items = items;
        m_count = item_count;
        m_func_save = func_save;
    }
#pragma region GetSet
    int CMenu::GetSelect() const
    {
        return m_select;
    }
    size_t CMenu::GetCount() const
    {
        return m_count;
    }

    string CMenu::GetTitle() const
    {
        return m_title;
    }
    ItemMenu* CMenu::GetItems() const
    {
        return m_items;
    }
#pragma endregion
    void CMenu::Print() const
    {
        cout << "\t\t" << m_title << endl;
        for (int i = 0; i < m_count; i++)
        {
            cout << i + 1 << ". ";
            m_items[i].Print();
            cout << endl;
        }
        cout << "0. Exit and save" << endl;
    }
    void CMenu::RunCommand()
    {
        cout << "\n\tSelect >> ";
        try
        {
            cin >> m_select;
            if (m_select <0 || m_select > m_count)
            {
                throw - 1;
            }
        }
        catch (int)
        {
            cerr << "Нет команды с таким номером. Попробуйте еще раз." << endl;
            RunCommand();
        }
        catch (...)
        {
            cerr << "Ошибка ввода. Попробуйте еще раз." << endl;
            RunCommand();
        }
        if (m_select == 0)
        {
            m_func_save();
            exit(0);
        }
        cout << endl;
        m_items[m_select - 1].Run();
    }

    ostream& operator<< (ostream& out, const CMenu& m)
    {
        m.Print();
        return out;
    }
    istream& operator>> (istream& in, CMenu& m)
    {
        m.RunCommand();
        cout << endl;
        return in;
    }
}

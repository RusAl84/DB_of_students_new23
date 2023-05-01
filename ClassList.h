#pragma once
#include <iostream>

using namespace std;

//Визуализация для добавления и удаления элементов в односвязном списке.
//https://www.cs.usfca.edu/~galles/visualization/StackLL.html


/// <summary>
/// Структура узла динамического списка
/// </summary>
struct node {
    string data;
    struct node* next;
};


class ClassList
{
private:
    struct node* myHead;
    int countItem = 0;

public:
    ClassList() {
        myHead;
        countItem = 0;
    }
    ~ClassList() {
        myHead;
        countItem = 0;
    }

    /// <summary>
    /// Добавляет элемент в начало.
    /// </summary>
    /// <param name="data"> данные элемента</param>
    void addItem(string _data)
    {
        struct node* newItem = new node();
        newItem->data = _data;
        if (countItem == 0)
            newItem->next = NULL;
        else
            newItem->next = myHead;
        myHead = newItem;
        countItem++;
    }
    /// <summary>
    /// Вставка элемента в список
    /// </summary>
    /// <param name="index">индекс после которого вставить</param>
    /// <param name="_data">значение которое необходимо вставить</param>
    void insertItem(int index, string _data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(_data);
        else {
            struct node* current = myHead;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            struct node* newItem = new node();
            newItem->data = _data;
            newItem->next = current->next;
            current->next = newItem;
            countItem++;
        }
    }
    void push_back(string _data) {
        insertItem(countItem, _data);
    }
    /// <summary>
    /// Изменить элемент списка
    /// </summary>
    /// <param name="index">индекс изменяемого элемента</param>
    /// <param name="_data">значение на которое нужно изменить</param>
    void editItem(int index, string _data) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
                //cout << "+" << current->data;
            }
            current->data = _data;
        }
        else {
            cout << endl << "Ошибка индекс не в диапазоне";
        }
    }
    /// <summary>
    /// Функция для удаления элемента из динамического списка
    /// </summary>
    /// <param name="index">индекс удаляемого элемента</param>
    void deleteItem(int index) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            struct node* old;
            if (index == 0) {
                old = myHead;
                myHead = current->next;
                delete old;
                countItem--;
            }
            else {
                int i = 0;
                while (current) {
                    if (i == index - 1) {
                        old = current->next->next;
                        delete current->next;
                        current->next = old;
                        countItem--;
                        break;
                    }
                    i++;
                    current = current->next;
                }
            }
        }

    }
    int getCount() {
        return countItem;
    }
    string getItem(int index) {
        string _data = "Error";
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
                //cout << "+" << current->data;
            }
            _data = current->data;
        }
        else {
            cout << endl << "Ошибка индекс не в диапазоне";
        }
        return _data;
    }
    void printItems4Menu()
    {
        struct node* current = myHead;
        int i = 0;
        while (current != NULL){
            cout << i << ". " << current->data << endl;
            i++;
            current = current->next;
        }
    }
};


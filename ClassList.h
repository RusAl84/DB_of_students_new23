#pragma once
#include <iostream>

using namespace std;

//������������ ��� ���������� � �������� ��������� � ����������� ������.
//https://www.cs.usfca.edu/~galles/visualization/StackLL.html


/// <summary>
/// ��������� ���� ������������� ������
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

    /// <summary>
    /// ��������� ������� � ������.
    /// </summary>
    /// <param name="data"> ������ ��������</param>
    void addItem(string _data)
    {
        struct node* newItem = new node();
        newItem->data = data;
        if (countItem == 0)
            newItem->next = NULL;
        else
            newItem->next = myHead;
        myHead = newItem;
        countItem++;
    }
    /// <summary>
    /// ������� �������� � ������
    /// </summary>
    /// <param name="index">������ ����� �������� ��������</param>
    /// <param name="data">�������� ������� ���������� ��������</param>
    void insertItem(int index, int data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(data);
        else {
            struct node* current = myHead;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            struct node* newItem = new node();
            newItem->data = data;
            newItem->next = current->next;
            current->next = newItem;
            countItem++;
        }
    }
    /// <summary>
    /// �������� ������� ������
    /// </summary>
    /// <param name="index">������ ����������� ��������</param>
    /// <param name="data">�������� �� ������� ����� ��������</param>
    void editItem(int index, int data) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
                //cout << "+" << current->data;
            }
            current->data = data;
        }
        else {
            cout << endl << "������ ������ �� � ���������";
        }
    }
    /// <summary>
    /// ������� ��� �������� �������� �� ������������� ������
    /// </summary>
    /// <param name="index">������ ���������� ��������</param>
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
};


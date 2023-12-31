#include "doubly_list.h"
#include <stdio.h>
#include <stdlib.h>

//-------------------- EXAMPLE --------------------
void example() 
{
    node* list = NULL;  //создание указателя на 1 элемент списка (пустой, т.к. пока в списке нет ни одного элемента)

    push_to_head(&list, 2); //добавление нового элемента в список с головы, данные = 2
    push_to_head(&list, 4); //добавление нового элемента в список с головы, данные = 4
    push_to_head(&list, 8); //добавление нового элемента в список с головы, данные = 8
    push_to_head(&list, 9); //добавление нового элемента в список с головы, данные = 9
    push_to_tail(list, -1); //добавление нового элемента в список с хвоста, данные = -1
    push_to_tail(list, 0); //добавление нового элемента в список с хвоста, данные = 0
    print_from_head(list);  //вывод на экран всех элементов списка с головы
    print_from_tail(list);  //вывод на экран всех элементов списка с хвоста
    print_element(list, 2); //вывод на экран данных 2 элемента списка

    int A[] = { 16, 65, 100, 129, 150 };    //создаём массив
    push_array_to_head(&list, A, sizeof(A) / sizeof(A[0])); //добавление новых элементов в список с головы, из чисел в массиве
    print_from_head(list);  //вывод на экран всех элементов списка с головы

    push_to_position(&list, 5, 32); //добавление нового элемента в список в указанную позицию, данные = 32
    print_from_head(list);  //вывод на экран всех элементов списка с головы
    
    printf("Remove element from HEAD: %d\n", pop_from_head(&list)); //удаление одного элемента в списоке с головы (функция возвращает данные удаляемого элемента)
    printf("Remove element from TAIL: %d\n", pop_from_tail(list)); //удаление одного элемента в списоке с хвоста (функция возвращает данные удаляемого элемента)
    printf("Remove element from position: %d\n", pop_from_position(&list, 2)); //удаление одного элемента в список с выбранной позиции(функция возвращает данные удаляемого элемента)    
    print_from_head(list);  //вывод на экран всех элементов списка с головы
    
    printf("Edit element was: %d\n", edit_from_head(list, 128));    //редактирования одного элемента из списка с головы, (функция возвращает старые данные редактируемого элемента)
    printf("Edit element was: %d\n", edit_from_tail(list, 1));  //редактирования одного элемента из списка с хвоста, (функция возвращает старые данные редактируемого элемента)
    printf("Edit element was: %d\n", edit_from_position(list, 2, 64));   //редактирования одного элемента из списка с выбранной позиции, (функция возвращает старые данные редактируемого элемента)
    print_from_head(list);  //вывод на экран всех элементов списка с головы

    printf("There are %d elements in the list\n", count(list)); //функция возвращает количество элементов в списке
}

//-------------------- MAIN --------------------
int main()
{
    example();
    return 0;
}


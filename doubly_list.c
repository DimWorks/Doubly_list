#include "doubly_list.h"
#include <stdlib.h>
#include <stdio.h>

node* HEAD = NULL;
node* TAIL = NULL;

//-------------------- CHECK FUNCTION --------------------
int is_empty(node* list_copy) 
{
    return list_copy == NULL;
}

//-------------------- NUMBER OF NODES --------------------

int count(node* list_copy) {
    int i = 0;
    for (; list_copy != NULL; list_copy = list_copy->next)
    {
        i++;
    }
    return i;
}

//-------------------- PUSH FUNCTION --------------------

void push_to_head(node** list, void* data) 
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = *list;
    tmp->previous = NULL;
    if (*list != NULL)
    {
        tmp->next->previous = tmp;
    }
    else
    {
        TAIL = tmp;
    }
    *list = tmp;    
    HEAD = tmp;

}

void push_array_to_head(node** list, int array[], int y) 
{
    for (int i = 0; i < y; i++)
    {
        push_to_head(list, array[i]);   //вызов функции добавления элемента в список с головы
    }        
}

void push_to_tail(node* list_copy, int data) 
{
    node* tmp = (node*)malloc(sizeof(node));    //выделение памяти под новый элемент списка
    tmp->data = data;   //запись данных в элемент
    tmp->next = NULL;   //запись указателя на NULL

    if (TAIL == NULL)
    {
        TAIL = tmp;
    }
    else
    {
        tmp->previous = TAIL;
        tmp->previous->next = tmp;
        TAIL = tmp;
    }
    //while ((list_copy->next) != NULL) list_copy = list_copy->next; //переход к последнему элементу
    //list_copy->next = tmp;   //запись адреса последнего элемента в указатель предпоследнего элемента
}

void push_to_position(node** list, int position, int data) 
{
    if (position < 1 || position > count(*list) + 1) 
    { 
        printf("Impossible position for the element\n"); 
        return; 
    }   //проверка корректности позиции элемента
    if (position == 1) 
    { 
        push_to_head(list, data); 
        return; 
    }    //частный случай, вызов функции push_from_head, если передана позиция первого элемента
    if (position == count(*list) + 1) 
    { 
        push_to_tail(*list, data); 
        return; 
    }    //частный случай, вызов функции push_from_tail, если передана позиция последнего элемента
    node* tmp = (node*)malloc(sizeof(node));    //выделение памяти под новый элемент списка
    node* list_copy = *list;    //создание вспомогательной переменной для предотвращения потери head-элемента
    tmp->data = data;   //запись данных в элемент
    for (int i = 1; i < position - 1; i++, list_copy = list_copy->next);    //переход к запрашиваемой позиции списка
    tmp->next = list_copy->next;    //установка новой связи между добавляемым и последующим элементами
    list_copy->next = tmp;  //установка новой связи между добавляемым и предыдущим и элементами
}

//-------------------- POP FUNCTION --------------------
int pop_from_head(node** list) 
{
    if (*list == NULL) { printf("Element to remove doesn't exist. List is empty.\n"); return NULL; } //проверка списка на наличие элементов
    node* tmp = *list;  //создание вспомогательной переменной
    int res = tmp->data;    //сохраниение данных удаляемого элемента
    HEAD = tmp->next;
    *list = tmp->next;  //второй элемент становится head-элементом списка
    free(tmp);  //освобождение памяти
    return res; //функция возвращает данные удаляемого элемента
}

int pop_from_tail(node* list_copy) {
    if (list_copy == NULL) 
    { 
        printf("Element to remove doesn't exist. List is empty.\n");
        return NULL; 
    } //проверка списка на наличие элементов

    node* tmp = TAIL;   //создание вспомогательной переменной
    int res = tmp->data;
    tmp->previous = tmp->previous->next = NULL;
    TAIL = tmp->previous;

    free(tmp);  //освобождение памяти
    return res; //функция возвращает данные удаляемого элемента
}

int pop_from_position(node** list, int position) {
    if (*list == NULL) { printf("Element to remove doesn't exist. List is empty.\n"); return NULL; } //проверка списка на наличие элементов
    if (position < 1 || position > count(*list)) { printf("Impossible position for the element\n"); return NULL; }  //проверка корректности позиции элемента
    if (position == 1) { return pop_from_head(list); } //частный случай, вызов функции pop_from_head, если передана позиция первого элемента
    if (position == count(*list)) { return pop_from_tail(*list); } //частный случай, вызов функции pop_from_tail, если передана позиция последнего элемента
    node* list_copy = *list;    //создание вспомогательной переменной для предотвращения потери head-элемента
    node* tmp = list_copy;  //создание вспомогательной переменной
    for (int i = 1; i < position; i++, list_copy = (list_copy)->next) 
        tmp = list_copy;    //сохрание адреса текущего элемента перед переходом к следующему
    int res = list_copy->data;  //сохраниение данных удаляемого элемента
    tmp->next = list_copy->next;    //установка новой связи между предыдущим и последующим элементами, в обход удаляемого
    free(list_copy);  //освобождение памяти
    return res; //функция возвращает данные удаляемого элемента
}

//-------------------- EDIT FUNCTION --------------------
int edit_from_head(node* list_copy, int data) {
    if (list_copy == NULL) { printf("Element to edit doesn't exist. List is empty.\n"); return NULL; } //проверка списка на наличие элементов
    int res = list_copy->data; //сохраниение данных редактируемого элемента
    list_copy->data = data; //замена данных редактируемого элемента
    return res;
}

int edit_from_tail(node* list_copy, int data) {
    if (list_copy == NULL) 
    { 
        printf("Element to edit doesn't exist. List is empty.\n"); 
        return NULL; 
    }  //проверка списка на наличие элементов
    //while (list_copy->next != NULL) list_copy = list_copy->next;    //переход к последнему элементу списка
    list_copy = TAIL;
    int res = list_copy->data;  //сохраниение данных редактируемого элемента
    list_copy->data = data; //замена данных редактируемого элемента
    return res;
}

int edit_from_position(node* list_copy, int position, int data) {
    if (list_copy == NULL) { printf("Element to edit doesn't exist. List is empty.\n"); return NULL; }  //проверка списка на наличие элементов
    if (position < 1 || position > count(list_copy)) { printf("Impossible position for the element.\n"); return NULL; } //проверка корректности позиции элемента
    for (int i = 1; i < position; i++, list_copy = (list_copy)->next);  //переход к запрашиваемому элементу
    int res = list_copy->data;  //сохраниение данных редактируемого элемента
    list_copy->data = data; //замена данных редактируемого элемента
    return res;
}

//-------------------- PRINT FUNCTION --------------------
void print_from_head(node* list_copy) {
    if (list_copy == NULL) { printf("List is empty.\n"); return; } //проверка списка на наличие элементов
    printf("Print from HEAD: ");
    while (list_copy != NULL) {  //условие достижения последнего элемента списка
        printf("%d ", list_copy->data);  //вывод данных элемента
        list_copy = list_copy->next;  //переход к следующему элементу 
    }
    printf("\n");
}

void print_from_tail(node* list_copy) {
    if (list_copy == NULL) 
    { 
        printf("List is empty.\n"); 
        return; 
    } //проверка списка на наличие элементов

    printf("Print from TAIL: ");
    list_copy = TAIL;
    while (list_copy != NULL)
    {
        printf("%d ", list_copy->data);
        list_copy = list_copy->previous;
    }
    printf("\n");
}

void print_element(node* list_copy, int position) {
    if (list_copy == NULL) 
    { 
        printf("List is empty.\n");
        return; 
    } //проверка списка на наличие элементов
    if (position < 1 || position > count(list_copy)) 
    { 
        printf("Impossible position for the element.\n");
        return; 
    } //проверка корректности позиции элемента
    for (int i = 1; i < position; i++, list_copy = (list_copy)->next); //переход к запрашиваемому элементу
    printf("Print %d element: %d", position, list_copy->data); //вывод данных элемента
    printf("\n");
}
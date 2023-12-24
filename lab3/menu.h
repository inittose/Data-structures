#pragma once

#include "queue.h"
#include "queuering.h"
#include "stack.h"
#include "ringbuffer.h"
#include <iostream>
#include <string>
using std::string, std::cout, std::cin, std::endl;

/*!
 * \brief Меню выбора СД
 */
void MainController();

/*!
 * \brief Вывести стек на экран
 * \param stack Объект стека
 */
void ShowStack(Stack* stack);

/*!
 * \brief Вывести очередь из двух стеков
 */
void ShowStackQueue(Queue* queue);

/*!
 * \brief Вывести кольцевой буфер
 * \param ringBuffer Кольцевой буфер
 */
void ShowRingBuffer(RingBuffer* ringBuffer);

/*!
 * \brief Вывести на экран очередь
 */
void ShowQueueRing(QueueRing* queueRing);

/*!
 * \brief Управляет очередью по средствам меню
 */
void ControllerQueueRing();

/*!
 * \brief Управляет кольцевым буфером по средствам меню
 */
void ControllerRingBuffer();

/*!
 * \brief Управляет очередью по средствам меню
 */
void ControllerStackQueue();

/*!
 * \brief Управляет стеком по средствам меню
 */
void ControllerStack();

/*!
 * \brief Ввод с проверкой
 * \param variable Переменная любого типа данных
 */
template <typename Type>
Type ValidInput();

/*!
 * \brief Дополняет имена типов данных
 * \param letter Первая буква типа данных
 * \return Полное название типа данных
 */
string GetTypeName(const char* letter);

/*!
 * \brief Очистить окно терминала
 */
void ClearTerminal();

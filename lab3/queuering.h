#pragma once

#include "ringbuffer.h"

/*!
 * \brief Очередь из кольцевого буфера
 */
class QueueRing
{
private:
    /*!
     * \brief Указатель на кольцевой буфер
     */
    RingBuffer* _ringBuffer;

    /*!
     * \brief Размер буфера
     */
    int _sizeBuffer;

    /*!
     * \brief Поменять размер буфера
     * \param growthFactor Фактор роста буфера
     */
    void ResizeBuffer(const float &growthFactor);

public:
    /*!
     * \brief Конструктор очереди
     */
    QueueRing();

    /*!
     * \brief Деструктор очереди
     */
    ~QueueRing();

    /*!
     * \brief Добавить элемент в очередь
     * \param value Значение элемента
     */
    void Enqueue(const int & value);

    /*!
     * \brief Снять элемент из очереди
     * \return Значение снятого элемента
     */
    int Dequeue();

    /*!
    * \brief Получить объект кольцевого буфера
    * \return Кольцевой буфер
    */
    const RingBuffer* GetRingBuffer();
};

#pragma once

/*!
 * \brief Кольцевой буфер
 */
struct RingBuffer
{
    /*!
     * \brief Массив указателей (буфер)
     */
    int **Data;

    /*!
     * \brief Размер буфера
     */
    int Capacity;

    /*!
     * \brief Индекс первого вошедшего элемента
     */
    int Head;

    /*!
     * \brief Индекс последнего вошедшего элемента
     */
    int Tail;

    /*!
     * \brief Конструктор кольцевого буфера
     * \param size Размер буфера
     */
    RingBuffer(const int &capacity = 4);

    /*!
     * \brief Деструктор кольцевого буфера
     */
    ~RingBuffer();

    /*!
     * \brief Найти свободное место в буфере
     * \return Количество свободного места
     */
    int GetFreeSpace() const;

    /*!
     * \brief Найти занятое место в буфере
     * \return Количество занятого места
     */
    int GetOccupiedSpace() const;

    /*!
     * \brief Добавить элемент в буфер
     * \param value Значение элемента
     */
    void Push(const int &value);

    /*!
     * \brief Вытолкнуть элемент из буфера
     * \return Значение элемента
     */
    int Pop();
};


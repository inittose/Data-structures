#pragma once

/*!
 * \brief Стек
 */
struct Stack
{
    /*!
     * \brief Данные стека
     */
    int* Data;

    /*!
     * \brief Мощность стека
     */
    int Capacity;

    /*!
     * \brief Длина занятого стека
     */
    int Length;

    /*!
     * \brief Поменять размер стека
     * \param growthFactor Фактор роста мощности стека
     */
    void ResizeStack(const float &growthFactor);

    /*!
     * \brief Конструктор стека
     * \param capacity Изначальная мощность стека
     */
    Stack(const int &capacity = 4);

    /*!
     * \brief Деструктор стека
     */
    ~Stack();

    /*!
     * \brief Добавить элемент в стек
     * \param value Значение элемента
     */
    void Push(const int &value);

    /*!
     * \brief Вытолкнуть элемент из стека
     * \return Значение элемента
     */
    int Pop();

    /*!
     * \brief Проверить пустой ли стек
     * \return true - пустой, иначе false
     */
    bool IsEmpty() const;
};

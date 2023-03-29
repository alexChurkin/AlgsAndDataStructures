# Лабораторная работа №4

Создан класс TQueue – реализация очереди с кольцевым буфером. В нём реализованы следующие методы:

- Запись элемента в очередь;
- Чтение элемента из очереди с удалением;
- Проверка на пустоту очереди;
- Проверка на заполненность очереди;
- Сравнение двух очередей (==, !=);
- Очистка очереди.

Реализована визуализация работы очереди (mp2-lab4-queue-form).
С использованием очереди реализована визуализация работы многопроцессорной системы в реальном времени (mp2-lab4-queue-processor).

Проект queue-with-list содержит реализацию очереди на основе структуры данных "односвязный список".

К проекту подключена библиотека Google Test для проверки работы классов TQueue и TLQueue.

![Visualizer screenshot](https://github.com/alexChurkin/mp2-lab4-queue/raw/master/Visualizer.png)

![Processors screenshot](https://github.com/alexChurkin/mp2-lab4-queue/raw/master/Processors.png)

![Console main screenshot](https://github.com/alexChurkin/mp2-lab4-queue/raw/master/ConsoleMain.png)

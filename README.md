# Методы программирования 2: Множества на основе битовых полей

[![Build Status](https://travis-ci.org/381706LembrikovStepan/mp2-lab1-set.svg?branch=master)](https://travis-ci.org/381706LembrikovStepan/mp2-lab1-set)

<!-- TODO
  -
-->

## Новости

  - 2015-10-02
    - Создан [Gitter-чат][gitter], в котором можно задавать вопросы про выполнение лабораторных работ
  - 2015-09-25
    - Опубликованы [видеозаписи][youtube-playlist] с живой демонстрацией Git и
      Google Test.
    - Опубликованы [слайды][slides] с лекций про Git и Google Test.

## Цели и задачи

__Цель данной работы__  — разработка структуры данных для хранения множеств с
использованием битовых полей, а также освоение таких инструментов разработки
программного обеспечения, как система контроля версий [Git][git] и фрэймворк для
разработки автоматических тестов [Google Test][gtest].

Предполагается, что перед выполнением работы студенты получают данный
проект-шаблон, содержащий следующее:

 - Интерфейсы классов битового поля и множества (h-файлы)
 - Готовый набор тестов для каждого из указанных классов
 - Пример использования класса битового поля и множества для решения задачи
   поиска простых чисел с помощью алгоритма ["Решето Эратосфена"][sieve]

Выполнение работы предполагает решение следующих задач:

  1. Реализация класса битового поля `TBitField` согласно заданному интерфейсу.
  1. Реализация класса множества `TSet` согласно заданному интерфейсу.
  1. Обеспечение работоспособности тестов и примера использования.
  1. Реализация нескольких простых тестов на базе Google Test.
  1. Публикация исходных кодов в личном репозитории на GitHub.

## Используемые инструменты

  - Система контроля версий [Git][git]. Рекомендуется использовать один из
    следующих клиентов на выбор студента:
    - [Git](https://git-scm.com/downloads)
    - [GitHub Desktop](https://desktop.github.com)
  - Фреймворк для написания автоматических тестов [Google Test][gtest]. Не
    требует установки, идет вместе с проектом-шаблоном.
  - Среда разработки Microsoft Visual Studio (2008 или старше).
  - Опционально. Утилита [CMake](http://www.cmake.org) для генерации проектов по
    сборке исходных кодов. Она может быть использована для генерации решения для
    среды разработки, отличной от Microsoft Visual Studio 2008 или 2010, предоставленных в данном проекте-шаблоне.

## Общая структура проекта

Структура проекта:

  - `docs` — инструкции по выполнению лабораторной работы, полезные документы.
  - `gtest` — библиотека Google Test.
  - `include` — директория для размещения заголовочных файлов.
  - `samples` — директория для размещения демо-приложений.
  - `sln` — директория с файлами решений и проектов для VS 2008 и VS 2010,
    вложенные директории `vc9` и `vc10` соответственно.
  - `src` — директория с исходными кодами (cpp-файлы).
  - `test` — директория с модульными тестами и основным приложением,
    инициализирующим запуск тестов.
  - `README.md` — информация о проекте, которую вы сейчас читаете.
  - Служебные файлы
    - `.gitignore` — перечень расширений файлов, игнорируемых Git при добавлении
      файлов в репозиторий.
    - `CMakeLists.txt` — корневой файл для сборки проекта с помощью CMake. Может
      быть использован для генерации проекта в среде разработки, отличной от
      Microsoft Visual Studio.
    - `.travis.yml` — конфигурационный файл для системы автоматического
      тестирования Travis-CI. Тесты, входящие в состав шаблонного проекта,
      регулярно запускаются на удаленной [инфраструктуре][travis].

В решении содержатся следующие модули:

  - Модуль `tbitfield`, содержащий реализацию класса битового поля (файлы
    `./include/tbitfield.h`, `./src/tbitfield.cpp`). Предполагается, что в ходе
    выполнения работы реализуются методы класса в файле `./src/tbitfield.cpp`,
    при этом заголовочный файл `./include/tbitfield.h` с объявлениями должен
    оставаться неизменным.
  - Модуль `tset`, содержащий реализацию класса множества (файлы
    `./include/tset.h`, `./src/tset.cpp`). При выполнении работы так же, как и в
    случае класса битового поля, разрабатывается только реализация методов
    класса.
  - Тесты для классов битовое поле и множество (файлы
    `./test/test_tbitfield.cpp`, `./test/test_tset.cpp`).
  - Пример использования класса битового поля и множества для поиска простых
    чисел с использованием алгоритма, называемого ["Решетом Эратосфена"][sieve]
    (файл `./samples/sample_prime_numbers.cpp`).

## Инструкция по выполнению работы

Кроме текстовых инструкций вы также можете обратиться к
[видеозаписи][youtube-playlist] с демонстрацией основных операций.

  1. Освоение общих принципов работы с Git и GitHub. Последовательность
     действий, которую необходимо выполнить перед началом работы с проектом,
     описана в документе, посвященному [Git][git-guide]. Вот основные этапы:
     - Создание форка [центрального репозитория][upstream] с проектом-шаблоном,
       размещенного на GitHub
     - Клонирование форка из своего личного пространства на GitHub к себе на
       рабочую машину
     - Создание новой ветки, внесение некоторых изменений (например в файл
       `README.md`)
     - Публикация изменений в виде pull request на GitHub
     - Вливание изменений в ветку `master` через веб-интерфейс GitHub
  1. Освоение общих принципов работы с Google Test. Инструкции приведены в
     разделе, посвященному [Google Test][gtest-guide]. Вот основные шаги:
     - Построение проекта с тестами, запуск тестов
     - Печать списка имен тестов: опция `--gtest_list_tests`
     - Запуск подмножества тестов: опция `--gtest_filter`
     - Реализация нескольких простых тестов, например: проверить что
       выражение `1+3+5+7+9 = 5^2` и что `1+3+5+7+9+11 = 6^2`
  1. Создание полноценных реализаций классов `TBitField` и `TSet`, проходящих
     все автоматические тесты.
     - Сперва необходимо добиться успешного прохождения всех тестов для класса
       `BitField`, далее для класса `TSet`
     - Затем следует убедиться, что сэмпл-приложение (Решето Эратосфена) также
       успешно работает
     - Далее полезно добавить несколько собственных тестов на классы, например:
       - Убедиться, что двойная очистка бита оставляет его в нулевом состоянии
       - Убедиться, что если взять три битовых поля, и выполнить на них битовую
         операцию в одну строку (например `bf1 | bf2 | bf3`), то получается
         корректный результат
       - Убедиться, что для класса множества также можно в одну строку выполнять
         несколько операций (например `set1 + set2 + set3`)

<!-- LINKS -->

[git]:         https://git-scm.com/book/ru/v2
[gtest]:       https://github.com/google/googletest
[sieve]:       http://habrahabr.ru/post/91112
[travis]:      https://travis-ci.org/UNN-VMK-Software/mp2-lab1-set
[git-guide]:   https://github.com/UNN-VMK-Software/mp2-lab1-set/blob/master/docs/part1-git.md
[gtest-guide]: https://github.com/UNN-VMK-Software/mp2-lab1-set/blob/master/docs/part2-google-test.md
[youtube-playlist]: https://www.youtube.com/playlist?list=PLSzOhsr5tmhrgV7u7CSzX4Ki1a9r0AKzV
[slides]:      https://github.com/UNN-VMK-Software/mp2-lab1-set/tree/master/docs/slides
[upstream]:    https://github.com/UNN-VMK-Software/mp2-lab1-set
[gitter]:      https://gitter.im/UNN-VMK-Software/mp2-lab1-set

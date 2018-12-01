# FixedPoint

## Development Goals ##

1. Accelerate the processing of real numbers on controllers without hardware support for IEEE 754 and the like.
2. Simplify program development.

## The purpose of the library ##

This library is mainly intended for use on controllers, such as atmega, since floating point operations on controllers are quite expensive.

## Supported programming languages and standards ##

* C:
  * C90 - yes
  * C99 - yes
  * C11 - yes

* C ++:
  * C ++ 98 - yes
  * C ++ 11 - yes
  * C ++ 1y - yes

## Implemented functions ##

* Work with fixed16 / fixed32, macro and templates for fixedpoint with any available width.
* Addition

    C++ only. For C, use the normal '+' operator
     
* Subtraction

    C++ only. For C, use the normal '-' operator
     
* Multiplication
* Division
* Getting absolute value
* Conversion double -> fixed
* Conversion fixed -> double

## The Makefile usage ##

* make all

    Default target, runs test, check and install

* make install

    ```make install```

    Install to the default directory ```/usr/local/include```

    ```make install prefix=<directory>```

    Install to the your desired directory.

* make uninstall

    ```make uninstall```

    Uninstall from the default directory ```/usr/local/include```

    ```make uninstall prefix=<directory>```

    Uninstall from the your desired directory.

* make test

    Build the test executable binary.

* make check

    Run the builded test.

* make clean

    Erase the tests binary.

## P.S. ##
Use it for your fun!



## Цели разработки. ##

1. Ускорить обработку  вещественных чисел на контроллерах без аппаратной поддержки IEEE 754 и подобного.
2. Упростить разработку программ.

## Назначение библиотеки. ##

Эта библиотека главным образом предназначена для использования на контроллерах, таких как атмега, поскольку на контоллерах операции с плавающей точкой довольно дорогие.

## Поддерживаемые языки программирования и стандарты ##

* C:
  * С90 - да
  * С99 - да
  * С11 - да

* C++:
  * С++98 - да
  * С++11 - да
  * С++1y - да

## Реализованные функции ##

* Работа с fixed16/fixed32, макросы и шаблоны для fixedpoint любой доступной ширины.
* Сложение
  
  Только C++. Для C используйте обычный оператор '+'
    
* Вычитание
  
  Только C++. Для C используйте обычный оператор '-'
    
* Умножение
* Деление
* Получение абсолютного значения
* Преобразование double -> fixed
* Преобразование fixed -> double


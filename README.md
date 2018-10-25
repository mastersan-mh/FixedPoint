# FixedPoint

## Development Goals ##
1. Accelerate the processing of real numbers on controllers without hardware support for IEEE 754 and the like.
2. Simplify program development.

## The purpose of the library ##
This library is mainly intended for use on controllers, such as atmega, since floating point operations on controllers are quite expensive.

## Supported programming languages and standards ##
* C:
  * C90 - not supported, because "inline"...
  * C99 - yes
  * C11 - yes

* C ++:
  * C ++ 98 - not supported, because move-semantic...
  * C ++ 11 - yes
  * C ++ 1y - yes

## Implemented functions ##
* Work with fixed16 / fixed32
* Addition

  C++ only. For C, use the normal '+' operator
     
* Subtraction

  C++ only. For C, use the normal '-' operator
     
* Multiplication
* Conversion double -> fixed
* Conversion fixed -> double

## P.S. ##
Use it for your fun!



## Цели разработки. ##
1. Ускорить обработку  вещественных чисел на контроллерах без аппаратной поддержки IEEE 754 и подобного.
2. Упростить разработку программ.

## Назначение библиотеки. ##
Эта библиотека главным образом предназначена для использования на контроллерах, таких как атмега, поскольку на контоллерах операции с плавающей точкой довольно дорогие.

## Поддерживаемые языки программирования и стандарты ##
* C:
  * С90 - не поддерживается, потому что "inline"...
  * С99 - да
  * С11 - да

* C++:
  * С++98 - не поддерживается, потому что move-semantic...
  * С++11 - да
  * С++1y - да

## Реализованные функции ##
Работа с fixed16/fixed32
* Сложение
  
  Только C++. Для C используйте обычный оператор '+'
    
* Вычитание
  
  Только C++. Для C используйте обычный оператор '-'
    
* Умножение
* Преобразование double -> fixed
* Преобразование fixed -> double

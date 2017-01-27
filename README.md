Ідз  з ООП::

1. Разработать класс LOGIKA16 для обработки 16-битовых данных типа unsigned short int, в котором реализовать:
1) Ввод числовых данных из файлов, сформированных программно с использованием генератора псевдослучайных значений rand и функции srand подготовки “числа раскачки” для генератора rand. Один из файлов должен быть сформирован в текстовом, а другой – в двоичном формате. Количество генерируемых чисел является параметром программы.
2) Каждая операция должна выполняться многократно для всего набора чисел, составляющих файл исходных данных. По достижению конца файла осуществляется переход к выполнению следующей операции с повторным применением набора чисел, составляющих файл. Если для бинарных операций количество чисел, входящих в состав файла, не кратно двум, то недостающий операнд считать равным нулю.
3) Ввод числовых данных с клавиатуры осуществлять в десятичной или шестнадцатеричной системах счисления.
4) При вводе данных с клавиатуры необходимо осуществлять проверку на ввод нецифрового символа и проверку вводимого числа на принадлежность интервалу допустимых значений чисел:
– для десятичных чисел, вводимых с клавиатуры, недопустимым является набор незначащих нулевых разрядов;
– допускается набор кодовой комбинации, состоящей из многих нолей, т.е. 000…0, которая должна интерпретироваться как “десятичный ноль”;
– вводимая шестнадцатеричная кодовая комбинация должна содержать дескриптор 0x системы счисления и может состоять из буквенных цифр, набранных в верхнем или нижнем регистре клавиатуры;
– допускается набор кодовой комбинации 0х000…0, которая должна интерпретироваться как “ шестнадцатеричный ноль”;
– допускается набор шестнадцатеричной кодовой комбинации 0х000…2Аfd, содержащей незначащие нулевые разряды.
5) При вводе с клавиатуры цифровых кодовых комбинаций возможные ошибки ввода должны диагностироваться следующими сообщениями с учетом количества вводимых значений операндов:
ОШИБКА: в операнде недопустимый дескриптор системы счисления,
ОШИБКА: в 1-м операнде недопустимый дескриптор системы счисления,
ОШИБКА: во 2-м операнде недопустимый дескриптор системы счисления,
ОШИБКА: в операнде избыточное количество символов,
ОШИБКА: в 1-м операнде избыточное количество символов,
ОШИБКА: во 2-м операнде избыточное количество символов,
ОШИБКА: в операнде нецифровой символ,
ОШИБКА: в 1-м операнде нецифровой символ,
ОШИБКА: во 2-м операнде нецифровой символ,
ОШИБКА: в операнде переполнение,
ОШИБКА: в 1-м операнде переполнение,
ОШИБКА: во 2-м операнде переполнение,
ОШИБКА: недопустимый режим приёма данных.
6) Ввод данных с клавиатуры и вывод данных на терминал и в выходной файл, аккумулирующем результаты программы в текстовом формате, реализовать в стиле языка С++.
7) В состав класса должен входить конструктор инициализации, в рамках которого должны создаваться файлы, связанные с объектом, и формироваться диагностические сообщения о возможных ошибках в процессе их создания.
Диагностические сообщения, связанные с набором на клавиатуре имени файла вывода, должны быть следующими:
ОШИБКА: файл вывода не открыт для записи – в имени файла количество символов больше 37,
ОШИБКА: файл вывода не открыт для записи – в конце имени файла недопустимый символ (точка),
ОШИБКА: файл вывода не открыт для записи – в имени файла недопустимый символ,
ОШИБКА: файл вывода не открыт для записи – недопустимое имя файла.
Следующие два сообщения должны формироваться с учетом значения признака успешного или неуспешного создания файла, возвращаемого объектом используемого класса fstream, ofstream или ifstream.
ОШИБКА: файл вывода не открыт для записи,
inFile: ошибка работы с файлом,
где, например, inFile – имя объекта класса ifstream.
8) Разрабатываемая программа должна удовлетворять следующим требованиям:
– структура выбора SWITCH должна быть дополнена блоком default, в котором формируется сообщение “ОШИБКА: введено число, не соответствующее пункту меню”, диагностирующее возможную ошибку в наборе номера пункта меню из интервала [1-7];
– при выводе результатов обработки на терминал и в файл мнемоника выполнения бинарной операции, например AND, должна располагаться в строке второго операнда, а мнемоника унарной операции INV – в строке единственного операнда.
Требования к виду формата вывода результатов выполнения логических операций на видеотерминал и в файл устанавливаются по результатам работы выданных тестовых программ.
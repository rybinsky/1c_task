# 1c_task
Практическое задание для отбора на кафедру КИС

Сложное метро. 

Дана карта метро. В ней указано между какими станциями ходят поезда и сколько времени занимает путь между этими станциями. Наконец, мы знаем, как часто поезд отправляется с начала каждой ветки. Для простоты будем считать, что в нулевую минуту по всем путям отправляются поезда.

Люди заходят в метро, чтобы как можно быстрее добраться с одной станции до другой. Помогите им. Постройте структуру, которая будет строить оптимальный маршрут. При запросе к ней указывается:

Станция отправления;

Станция прибытия;

Минута, в которую человек спустился в метро;

Переходы внутри одной станции происходят мгновенно. Если человек прибыл на станцию ровно в ту минуту, в которую другой поезд - он успевает на него.

-------------------------------------------------------------------------------------

Решение основано на алгоритме Беллмана-Форда.
Будем придерживаться следующих условий на входные данные:
1) Считаем, что время движения по прямой ветке от начала и конца из А в Б и из Б в А одинаково из концов прямой ветки поезда выходят симметрично.
2) К моменту, когда поезда из одного конца достигают другого, все поезда из начала уже вышли, чтобы в любой момент на ветке в одну и другую сторону было одинаковое число поездов и наблюдалась некая симметрия(этим мы пользуемся чтобы поезда равномерно двигались по каждой ветке в обоих направлениях).
3) Входные данные так, чтобы из начала ветки каждые rangeT минут входили поезда, то есть из другого конца ветки они подходят и все с тем же интервалом rangeT выходят в другую сторону.
4) Пусть в сутках 24 * 60 = 1440 минут, входные данные такие, что движение по ветке не превышает 150 минут. Есть полное время движения по ветке. если поед выезжает и до конца суток остается меньше, то он не выезжает.
5) Поезда, идущие по одной ветке в разные стороны - это разные поезда и описываются в начале отдельно

-------------------------------------------------------------------------------------

Для запуска программы необходимо скачать файл task.cpp

Например, входные данные такие:

Первая строка - число станций и типов поездов, видно, что каждые два поезда это поезда с противоположных сторон каждой ветки(то есть всего веток 3)
В каждой из строк: число станций на ветке, интервал выхода из депо, когда начинается движение на ветке, затем станция начала, время между ею и второй, вторая станция, время между второй и третьей, третья станция и так далее, то есть в первой строке(видно, что вторая строка почти повторяет первую): станции 1, 2, 3, 4, 5, время между 1 и 2 - 2 минуты, 2 и 3 - 3 минуты, 3 и 4 - 5 минут, 4 и 5 - 5 минут. Вторая строка(второй тип поезда)аналогично, только станции наоборот. 3 - 6 строки аналогично для двух других веток. Последняя строка из трех чисел - пример запроса к программе: станция откуда, куда и сколько сейчас минут прошло с начала суток.

8 6

5 7 0 1 2 2 3 3 5 4 5 5

5 7 0 5 5 4 5 3 3 2 2 1

3 2 0 8 1 6 1 4

3 2 0 4 1 6 1 8

3 4 0 6 1 3 6 7

3 4 0 7 6 3 1 6

1 4 6

Программы выводит:

Minimal time: 10

Your route:

1, get on a train!

2, keep going

3, wait 2

6, keep going

4, coming out!


Вывод: время и маршрут, сначала садимся, затем где едем дальше, где выходим и ждем следующего поезда на следующую станцию, и где выходим.

Еще примеры запросов и корректных выводов к приведенному выше расписанию:

8 4 1

Minimal time: 3

Your route:

8, please, wait 1 minutes

6, keep going

4, coming out!

8 4 0

Minimal time: 2

Your route:

8, keep going

6, keep going

4, coming out!

8 4 2

Minimal time: 2

Your route:

8, keep going

6, keep going

4, coming out!

8 4 1439

You can't get to the station 4 from the station 8 by metro

8 4 1438

Minimal time: 2

Your route:

8, keep going

6, keep going

4, coming out!

7 3 0

Minimal time: 6

Your route:

7, keep going

3, coming out!






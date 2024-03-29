import math as m

N_REPS = 1000  # константа, отвечающая за число интервалов разбиения в методе трапеций


class LaplaceFuncHalfDiv:
    """
    Класс для нахождения аргумента функции Лапласа при заданном значении функции
    """
    """
    Функция Лапласа нечетная
    Согласно таблицам значений этой функции, для метода половинного деления можно взять отрезок 
    от -5 до 5, поскольку для x > 5 можно принять f(x) = 0.5
    """

    def __init__(self):
        """
        Инициализация атрибутов класса
        """

    @staticmethod
    def __input_func_value() -> float:
        """
        Метод, позволяющий ввести значение функции Лапласа
        """

        return float(input("\nВведите значение функции Лапласа, для которого требуется найти аргумент: "))

    @staticmethod
    def __input_eps() -> float:
        """
        Метод, позволяющий ввести точность вычисления
        """

        return float(input("\nВведите требуемую точность: "))

    @staticmethod
    def __x_by_func(func_value: int | float):
        """
        Как то для моего собственного понимания я это сделал
        """

        def laplace(x: int | float):
            """
            Собственно, сама функция Лапласа
            """

            def f(_x: int | float):
                """
                Подынтегральное выражение функции Лапласа
                """
                f_x = (1 / m.sqrt(2 * m.pi)) * m.exp(-(_x ** 2) / 2)

                return f_x

            #  интеграл вычисляется методом трапеций
            n = N_REPS
            h = (x - 0) / n  # шаг разбиения
            integr = (f(0) + f(x)) / 2  # суммируем значения функции на концах интервала

            for i in range(1, n + 1):
                x = 0 + i * h  # вычисляем x на текущем интервале
                integr += f(x)  # добавляем значение функции на текущем интервале к интегралу
            integr *= h  # умножаем сумму значений на шаг

            return func_value - integr

        return laplace

    @staticmethod
    def laplace(x: int | float):
        """
        Собственно, сама функция Лапласа
        """

        def f(_x: int | float):
            """
            Подынтегральное выражение функции Лапласа
            """
            f_x = (1 / m.sqrt(2 * m.pi)) * m.exp(-(_x ** 2) / 2)

            return f_x

        #  интеграл вычисляется методом трапеций
        n = N_REPS
        h = (x - 0) / n  # шаг разбиения
        integr = (f(0) + f(x)) / 2  # суммируем значения функции на концах интервала

        for i in range(1, n - 1):
            x = 0 + i * h  # вычисляем x на текущем интервале
            integr += f(x)  # добавляем значение функции на текущем интервале к интегралу
        integr *= h  # умножаем сумму значений на шаг

        return integr

    def get_solve_x(self):
        """
        Метод позволяет получить аргумент функции по значению,
        используя метод трапеций для вычисления интеграла,
        а также используя метод половинного деления для нахождения самого корня
        """
        func_value = self.__input_func_value()
        if func_value >= 0.5:
            print(f"\nЗначение функции Лапласа не может превышать 0.5")
            return

        my_f = self.__x_by_func(func_value)  # получил функцию, для которой будем искать корень

        eps = self.__input_eps()  # точность

        a_k, b_k = -5, 5  # начальный интервал неопределенности

        condition = True

        count_iter = 0

        while condition:
            c_k = (a_k + b_k) / 2  # находим середину текущего интервала неопределенности

            if my_f(a_k) * my_f(c_k) < 0:
                b_k = c_k
            if my_f(c_k) * my_f(b_k) < 0:
                a_k = c_k

            count_iter += 1

            if b_k - a_k <= eps:
                condition = False

        x = (a_k + b_k) / 2

        print(f"\nЗначение функции: {func_value}, найденный по этому значению x = {x: .3f}")

        print(f"Функция Лапласа от этого x, вычисленный методом трапеций: {self.laplace(x): .3f}")

        print(f"Для вычисления аргумента методом половинного деления потребовалось {count_iter} итераций")

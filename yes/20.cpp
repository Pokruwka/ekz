/*
Принципы SOLID
Single Responsibility/Принцип единственной ответственности: Каждый класс должен иметь только одну причину для изменения, то есть он должен выполнять только одну задачу.
Случай несоблюдения принципа на примере разработки Git:
Если проект разрабатывает 2 и более разработчиков, и им нужно изменить разные части кода, после чего отправить их на сервер, то у последнего возникнет ошибка и ему прийдётся вносить изменения заново.
Пример: 
# Плохо: класс выполняет несколько задач
class Report:
    def generate_report(self):
        # Генерация отчета
        pass

    def save_to_file(self, filename):
        # Сохранение отчета в файл
        pass

# Хорошо: каждый класс отвечает за свою задачу
class Report:
    def generate_report(self):
        # Генерация отчета
        pass

class ReportSaver:
    def save_to_file(self, report, filename):
        # Сохранение отчета в файл
        pass
Оpen/Closed Principle/Принцип открытости/закрытости: Программные сущности (классы, модули, функции и т.д.) должны быть открыты для расширения, но закрыты для модификации.


Liskov Substitution Principle/Принцип подстановки Лисков: Объекты в программе должны быть заменяемыми экземплярами их подтипов без изменения правильности программы.

# Плохо: подкласс нарушает поведение базового класса
class Bird:
    def fly(self):
        return "I can fly!"

class Ostrich(Bird):
    def fly(self):
        raise Exception("Ostriches can't fly!")

# Хорошо: все подклассы соблюдают поведение базового класса
class Bird:
    def fly(self):
        return "I can fly!"

class Sparrow(Bird):
    pass

class Eagle(Bird):
    pass

Interface Segregation Principle/Принцип разделения интерфейса: Клиенты не должны зависеть от интерфейсов, которые они не используют. Лучше иметь несколько специализированных интерфейсов, чем один универсальный.

# Плохо: один интерфейс для всех
class Worker:
    def work(self):
        pass

    def eat(self):
        pass

# Хорошо: разделение интерфейсов
class Workable:
    def work(self):
        pass

class Eatable:
    def eat(self):
        pass

class Employee(Workable, Eatable):
    def work(self):
        # Работа
        pass

    def eat(self):
        # Обед
        pass

Dependency Inversion Principle/Принцип инверсии зависимостей:Зависимости должны быть от абстракций, а не от конкретных реализаций. Высокоуровневые модули не должны зависеть от низкоуровневых, оба должны зависеть от абстракций.

# Плохо: зависимость от конкретного класса
class Database:
    def connect(self):
        pass

class User:
    def __init__(self):
        self.database = Database()

# Хорошо: зависимость от абстракции
class DatabaseInterface:
    def connect(self):
        pass

class User:
    def __init__(self, database: DatabaseInterface):
        self.database = database


*/
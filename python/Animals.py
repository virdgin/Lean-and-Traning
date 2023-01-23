from functools import total_ordering
class Animal:
    __cnt = 0

    @staticmethod
    def __gen_id():
        Animal.__cnt += 1
        return Animal.__cnt

    @staticmethod
    def description():
        print("Hello, I am the class Animal")

    def __init__(
        self, type, name, age, weight=0, isWalk=True, isFly=False, isSwim=False
    ):
        self.type = type
        self.name = name
        self.age = age
        self.weight = weight
        self.isWalk = "Да" if isWalk else "Нет"
        self.isFly = "Да" if isFly else "Нет"
        self.isSwim = "Да" if isSwim else "Нет"
        self.id = self.__gen_id()

    def __str__(self):
        return self.display()

    def display(self):
        return f"Тип: {self.type}, Имя: {self.name}, Возраст: {self.age}, Вес: {self.weight}, Умеет летать: {self.isFly}, Умеет ходить: {self.isWalk}, Умеет плавать: {self.isSwim} id: {self.id}"

    def holiday(self, k):
        self.weight += 0.1 * k

    def getAge(self):
        return self.age

    def setAge(self, age):
        self.age = age

    def rename(self, name):
        self.name = name
    @total_ordering
    def __lt__(self, other):
        return self.weight<other.weight
    def __le__(self,other):
        return self.weight<=other.weight
    def __eq__(self, other):
        return self.weight==other.weight

class Bird(Animal):
    def __init__(self, name, age):
        super().__init__(self.__class__.__name__, name, age)
        self.area = None
        self.winterFly = None
        self.isFly = True

    def chirik_chirik(self):
        print("Chirik-Chirik")

    def display(self):
        return (
            f"I am {self.type}, "
            + super().display()
            + f", Среда обитания: {self.area}, Зимовка: {self.winterFly}."
        )


class Fish(Animal):
    def __init__(self, name, age):
        super().__init__(self.__class__.__name__, name, age)
        self.squama = None
        self.upStreamSwim = None
        self.isSwim = True
        self.isWalk = False

    def bul_bul(self):
        print("Bul-Bul")

    def display(self):
        return (
            f"I am {self.type}, "
            + super().display()
            + f", Чешуя: {self.squama}, Плавает против течения: {self.upStreamSwim}."
        )


class Insect(Animal):
    def __init__(self, name, age):
        super().__init__(self.__class__.__name__, name, age)
        self.isWalk = True
        self.wingCount = None
        self.likeJesus = None

    def ggggg(self):
        print("Ggggg")

    def display(self):
        return (
            f"I am {self.type}, "
            + super().display()
            + f", Крылья: {self.wingCount}, Ходит по воде: {self.likeJesus}."
        )


a = Animal("Cat", "Vasya", 3)
a.weight = 8
d = Animal("Dog", "Sharik", 10)
d.weight = 15
b = Animal("Bird", "Ara", 5)
b.weight = 8

print(a > d)  #False
print(a < d)  #True
print(a >= d) #False
print(a <= d) #True
print(a == d) #False
print(a != d) #True

print(a > b)  #False
print(a < b)  #False
print(a >= b) #True
print(a <= b) #True
print(a == b) #True
print(a != b) #False

class Fraction():

    def __init__(self, *args):
        if len(args) == 2:
            self.n = args[0]
            self.d = args[1]
        else:
            if isinstance(args[0], int):
                self.n = args[0]
                self.d = 1
            elif args[0].find('/') != -1:
                self.n, self.d = map(int, args[0].split('/'))
            else:
                self.n = int(args[0])
                self.d = 1
        self._gcd()

    def _check(self, other):
        if other.__class__ is not self.__class__:
            return Fraction(other)
        return other

    def _gcd(self):
        a = abs(self.n)
        b = abs(self.d)
        while b != 0:
            a, b = b, a % b
        self.n = self.n // a
        self.d = self.d // a
        if self.d < 0:
            self.n = -self.n
            self.d = -self.d

    def numerator(self, new_value=None):
        if new_value is not None:
            self.n = new_value * (-1 if self.n < 0 else 1)
            self._gcd()
            return self
        else:
            return abs(self.n)

    def denominator(self, new_value=None):
        if new_value is not None:
            self.d = new_value
            self._gcd()
            return self
        else:
            return abs(self.d)

    def __neg__(self):
        return Fraction(-self.n, self.d)

    def __str__(self):
        return f'{self.n}/{self.d}'

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}('{self.__str__()}')"

    def _normal(self, other):
        other = self._check(other)
        a = self.d
        b = other.d
        for i in range(max(a, b), a * b + 1):
            if i % a == 0 and i % b == 0:
                return self.n * (i // self.d), other.n * (i // other.d), i

    def __add__(self, other):
        a, b, c = self._normal(other)
        return Fraction(a + b, c)

    def __sub__(self, other):
        a, b, c = self._normal(other)
        return Fraction(a - b, c)

    def __iadd__(self, other):
        a, b, c = self._normal(other)
        self.n = a + b
        self.d = c
        self._gcd()
        return self

    def __isub__(self, other):
        a, b, c = self._normal(other)
        self.n = a - b
        self.d = c
        self._gcd()
        return self

    def reverse(self):
        return Fraction(self.d, self.n)

    def __mul__(self, other):
        other = self._check(other)
        return Fraction(self.n * other.n, self.d * other.d)

    def __imul__(self, other):
        other = self._check(other)
        self.n = self.n * other.n
        self.d = self.d * other.d
        self._gcd()
        return self

    def __truediv__(self, other):
        other = self._check(other)
        return Fraction(self.n * other.d, self.d * other.n)

    def __itruediv__(self, other):
        other = self._check(other)
        self.n = self.n * other.d
        self.d = self.d * other.n
        self._gcd()
        return self

    def __lt__(self, other):
        a, b, c = self._normal(other)
        return a < b

    def __le__(self, other):
        a, b, c = self._normal(other)
        return a <= b

    def __eq__(self, other):
        a, b, c = self._normal(other)
        return a == b

    def __ne__(self, other):
        a, b, c = self._normal(other)
        return a != b

    def __gt__(self, other):
        a, b, c = self._normal(other)
        return a > b

    def __ge__(self, other):
        a, b, c = self._normal(other)
        return a >= b

    def __radd__(self, other):
        a, b, c = self._normal(other)
        return Fraction(b + a, c)

    def __rsub__(self, other):
        a, b, c = self._normal(other)
        return Fraction(b - a, c)

    def __rmul__(self, other):
        other = self._check(other)
        return Fraction(self.n * other.n, self.d * other.d)

    def __rtruediv__(self, other):
        other = self._check(other)
        return Fraction(self.d * other.n, self.n * other.d)

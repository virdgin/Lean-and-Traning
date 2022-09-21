from sys import stdin
from copy import deepcopy


class MatrixError (BaseException):

    def __init__(self, m_1, m_2):
        self.matrix1 = m_1
        self.matrix2 = m_2


class Matrix:

    def __init__(self, A):
        self.matrix = deepcopy(A)

    def __str__(self):
        return '\n'.join(['\t'.join(map(str, line)) for line in self.matrix])

    def size(self):
        return (len(self.matrix), len(self.matrix[0]))

    def __add__(self, B):
        l1 = len(self.matrix)
        l2 = len(B.matrix)
        if l1 == l2 and len(self.matrix[0]) == len(B.matrix[0]):
            result = []
            for i in range(len(self.matrix)):
                temp = list(map(lambda x, y: x+y, self.matrix[i], B.matrix[i]))
                result.append(temp)
            return Matrix(result)
        else:
            raise MatrixError(self, B)

    def __mul__(self, B):
        if isinstance(B, Matrix):
            result = []
            if len(self.matrix[0]) == len(B.matrix):
                return Matrix(list(map(
                    lambda x: list(
                        map(
                            lambda y: sum(map(
                                lambda z: z[0] * z[1],
                                zip(x, y))
                            ),
                            zip(*B.matrix))),
                    zip(*Matrix.transposed(self).matrix))
                )
                )
            else:
                raise MatrixError(self, B)
        elif isinstance(B, int) or isinstance(B, float):
            result = []
            for i in range(len(self.matrix)):
                temp = [j*B for j in self.matrix[i]]
                result.append(temp)
            return Matrix(result)

    __rmul__ = __mul__

    def transpose(self):
        self.matrix = [[self.matrix[j][i] for j in range(
            len(self.matrix))] for i in range(len(self.matrix[0]))]
        return self

    def transposed(self):
        result = [[self.matrix[j][i] for j in range(
            len(self.matrix))] for i in range(len(self.matrix[0]))]
        return Matrix(result)

    @staticmethod
    def determinant(m):
        if m.size()[0] == 2:
            return m.matrix[0][0] * m.matrix[1][1] - \
                m.matrix[0][1] * m.matrix[1][0]
        elif m.size()[0] == 3:
            return \
                m.matrix[0][0] * m.matrix[1][1] * m.matrix[2][2] \
                + m.matrix[2][0] * m.matrix[0][1] * m.matrix[1][2] \
                + m.matrix[1][0] * m.matrix[2][1] * m.matrix[0][2] \
                - m.matrix[2][0] * m.matrix[1][1] * m.matrix[0][2] \
                - m.matrix[0][0] * m.matrix[2][1] * m.matrix[1][2] \
                - m.matrix[1][0] * m.matrix[0][1] * m.matrix[2][2]
        else:
            raise Exception("\nMatrix's range more than 3.\n")

    def solve(self, A):
        if self.size()[1] != self.size()[0]:
            raise Exception("\nThe Matrix is not square.\n")
        elif self.size()[1] != len(A):
            raise Exception("\nThe Matrix and vector have different length.\n")
        outList = []
        for i in range(len(A)):
            m = Matrix(self.matrix)
            for ii in range(len(A)):
                m.matrix[ii][i] = A[ii]
            outList.append(Matrix.determinant(m))
        return list(map(lambda x: x / Matrix.determinant(self), outList))


class SquareMatrix(Matrix):

    def __mul__(self, n):
        return(SquareMatrix(super().__mul__(n).matrix))

    def __pow__(self, n):
        if n == 0 or n == 1:
            return self
        elif n == 2:
            return self*self
        if n % 2 != 0:
            return(self*(self**(n-1)))
        else:
            return(self*self)**(n//2)


exec(stdin.read())

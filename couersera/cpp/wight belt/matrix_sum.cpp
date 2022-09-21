#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
public:
  Matrix()
  {
    rows = 0;
    cols = 0;
  }
  Matrix(int row, int col)
  {
    Reset(row, col);
  }
  void Reset(int row, int col)
  {
    if (row < 0)
    {
      throw out_of_range("num_rows must be >= 0");
    }
    if (col < 0)
    {
      throw out_of_range("num_columns must be >= 0");
    }
    if (row == 0 || col == 0)
    {
      row = 0;
      col = 0;
    }
    rows = row;
    cols = col;
    matrix.assign(rows, vector<int>(col));
  }
  int &At(int row, int col)
  {
    return matrix.at(row).at(col);
  }
  int At(int row, int col) const
  {
    return matrix.at(row).at(col);
  }

  int GetNumRows() const
  {
    return rows;
  }
  int GetNumColumns() const
  {
    return cols;
  }

private:
  int rows;
  int cols;
  vector<vector<int>> matrix;
};
istream &operator>>(istream &stream, Matrix &mat)
{
  int row = 0, col = 0;
  stream >> row >> col;
  mat.Reset(row, col);
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
      stream >> mat.At(r, c);
    }
  }
  return stream;
}
ostream &operator<<(ostream &out, const Matrix &mat)
{
  out << mat.GetNumRows() << " " << mat.GetNumColumns() << endl;
  for (int r = 0; r < mat.GetNumRows(); r++)
  {
    for (int c = 0; c < mat.GetNumColumns(); c++)
    {
      if (c > 0)
      {
        out << " ";
      }
      out << mat.At(r, c);
    }
    out << endl;
  }
  return out;
}
bool operator==(const Matrix &lhs, const Matrix &rhs)
{
  if (lhs.GetNumRows() != rhs.GetNumRows())
  {
    return false;
  }
  if (lhs.GetNumColumns() != rhs.GetNumColumns())
  {
    return false;
  }
  for (int i = 0; i < lhs.GetNumRows(); i++)
  {
    for (int j = 0; j < lhs.GetNumColumns(); j++)
    {
      if (lhs.At(i, j) != rhs.At(i, j))
      {
        return false;
      }
    }
  }
  return true;
}
Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
  if (lhs.GetNumRows() != rhs.GetNumRows())
  {
    throw invalid_argument("Mismatched number of rows");
  }
  if (lhs.GetNumColumns() != rhs.GetNumColumns())
  {
    throw invalid_argument("Mismatched number of columns");
  }
  Matrix summ(lhs.GetNumRows(), lhs.GetNumColumns());
  for (int i = 0; i < summ.GetNumRows(); i++)
  {
    for (int j = 0; j < summ.GetNumColumns(); j++)
    {
      summ.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
    }
  }
  return summ;
}
// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main()
{
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}

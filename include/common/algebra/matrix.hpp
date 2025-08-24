#ifndef ALGEBRA_MATRIX_HPP
#define ALGEBRA_MATRIX_HPP

#include <vector>

#include <stdexcept>
#include <string>

namespace common::algebra {

class SizeMismatchException: public std::runtime_error {
public: 


};  

class InvalidSizeException: public std::runtime_error {
public:


};

  
template <typename T>
class Matrix {
public:
  Matrix(std::size_t rows, size_t cols):Matrix(rows, cols, T{}) noexcept {}

  Matrix(std::size_t rows, size_t cols, T initial_value):
    rows(rows),
    cols(cols)
    noexcept
  {
    values.capacity(rows * cols);
  }

  Matrix(std::vector<std::vector<T>> mat) {
    std::size_t rows = mat.size();
    if (rows == 0) {
      throw;
    }

    std::size_t cols = mat[0].size();

    values.capacity(rows * cols);
    for (std::vector<T> row: mat)
    {
      if (row.size() != cols) {
        throw;
      }

      for (T value: row) {
        values.emplace_back(value);
      }
    }
  }

  Matrix(std::size_t rows, std::size_t cols, std::vector<T> folded_mat) rows(rows), cols(cols) {
    if (rows * cols != folded_mat.size()) {
      throw;
    }

    values = folded_mat;

  }

  void set(size_t row, size_t col, T value) noexcept {
    values[row * cols + col] = value;
  }
  
  T get(size_t row, size_t col) const noexcept {
    return values[row * cols + col];
  }


  Matrix<T> add(Matrix<T> const& other) const {
    if rows != other.rows || cols != other.cols {
      throw SizeMismatchException {};
    }

    Matrix<T> res_mat(rows, cols);
    for (std::size_t row = 0; row < rows; row ++) {
      for (std::size_t col = 0; col < cols; col ++) {
        res_mat.set(row, col) = get(row, col) + other.get(row, col);
      }
    }
  }
  
private:
  std::size_t rows, cols;
  std::vector<T> values;
};

}

#endif // ALGEBRA_MATRIX_HPP

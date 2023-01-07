//
// Created by Alvin Jenkins on 15.12.2022.
//
#include <iostream>
#include <valarray>
#include <cstddef>


void test_print(std::valarray<float>& v, int rows, int cols)
{
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout
                    << v[r * cols + c]
                    << ' ';
        }
        std::cout << '\n';
    }
}

int main(int argc, char* argv[]){
    float coefficient = atof(argv[1]);
    int number_of_rows = atoi(argv[2]);

    int number_of_entries = argc - 2;
    int number_of_columns = number_of_entries / number_of_rows;
    std::valarray<float> matrix(number_of_entries);

    for (int i = 0; i < number_of_entries; i++){
        matrix[i] = atof(argv[2 + i]);
    }

    for (int i = 0; i < number_of_columns; i++){
//        std::size_t start = i;
//        std::size_t size[] = {number_of_rows};
//        std::size_t stride[] = {number_of_columns};
//        std::gslice my_gslice(start, std::valarray<std::size_t>(size, 1), std::valarray<std::size_t>(stride, 1));

        std::size_t start = i;
        std::size_t size = number_of_rows;
        std::size_t stride = number_of_columns;
        std::slice my_slice(start, size, stride);

        std::valarray<float> coef(number_of_rows);
        for (int i =0; i < size; i++) {
            coef[i] = coefficient;
        }

//        matrix[my_gslice] = coefficient * matrix[my_gslice]_cplx;
        matrix[my_slice] = my_slice.apply(coef);
    }

    test_print(matrix, number_of_rows, number_of_columns);

    return 0;
}

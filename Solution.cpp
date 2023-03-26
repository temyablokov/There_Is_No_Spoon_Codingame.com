#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{

    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // создаем матрицу для значений ячеек игровой сетки
    vector<vector<char>> grid(height, vector<char>(width));

    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .

        for (int j = 0; j < width; j++) {
            grid[i][j] = line[j]; // сразу записываем значения ячеек в матрицу
        }
    }

    // проходим по матрице, ищем ноды
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == '0') { // если в ячейке есть нода ('0')
                int right = -1, bottom = -1; // задаем координаты для соседних нод
                // по заданию координаты -1 - отсутствие соседа, те по умолчанию его нет

                // проверяем ячейку справа на наличие соседа
                for (int k = j + 1; k < width; k++) {
                    if (grid[i][k] == '0') { // если есть сосед справа
                        right = k; // записываем координату ноды справа
                        break;
                    }
                }
                // проверяем ячейку снизу на наличие ноды
                for (int k = i + 1; k < height; k++) {
                    if (grid[k][j] == '0') { // если есть сосед снизу
                        bottom = k; // записываем координату ноды снизу
                        break;
                    }
                }
                // выводим координаты ноды и ее соседей
                cout << j << " " << i << " ";
                if (right == -1) { // если нет соседа справа
                    cout << "-1 -1 "; // выводим координаты отсутствия
                } else {
                    cout << right << " " << i << " "; // если есть, выводим координаты соседа
                }
                if (bottom == -1) { // если нет соседа снизу
                    cout << "-1 -1"; // выводим координаты отсутствия
                } else {
                    cout << j << " " << bottom; // // если есть, выводим координаты соседа
                }
                cout << endl;
            }
        }
    }

    return 0;
}

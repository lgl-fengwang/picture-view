#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    string file_name;
    string var_string;
    int width, height, pixel, r, g, b;
    char var_char;
    ifstream is_file;
    HWND hwnd = GetForegroundWindow();
    HDC dc = GetDC(hwnd);
    cout << "输入文件名:";
    cin >> file_name;
    cin.get();
    is_file.open(file_name, ios::binary);
    if (getline(is_file, var_string, ' ')) {
        if (var_string != "P6") {
            cout << "文件头格式错误" << endl;
        }
        else {
            is_file >> width;
            is_file.get();
            is_file >> height;
            is_file.get();
            is_file >> pixel;
            is_file.get();
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    r = is_file.get();
                    g = is_file.get();
                    b = is_file.get();
                    SetPixel(dc, j, i, RGB(r, g, b));
                }
            }
        }
    }
    else {
        cout << "文件读取错误" << endl;
    }
    is_file.close();
    ReleaseDC(hwnd, dc);
    cin.get();
    return 0;
}
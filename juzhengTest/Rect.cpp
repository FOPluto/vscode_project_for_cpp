// Rect.cpp
#include "Rect.h"
/*--------------------------------------------------------------*/
Rect::Rect(int rows, int cols)
{                                    //构造函数
    assert(rows >= 0 && cols >= 0);  //断言是否行数和列数是否小于零
    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    this->head = arr, this->rows = rows, this->cols = cols;
}
/*--------------------------------------------------------------*/
Rect Rect::operator+(const Rect& rect)
{  //重载了+号运算符的实现
    assert(this->rows == rect.rows &&
           this->cols == rect.cols);  //断言函数，可以保证矩阵的大小相等
    Rect rectTemp(rect.rows, rect.cols);
    for (int i = 0; i < rect.rows; i++) {
        for (int j = 0; j < rect.cols; j++) {
            rectTemp.head[i][j] = rect.head[i][j] + this->head[i][j];
        }
    }
    return rectTemp;
}
/*-------------------------------------------------------------*/
Rect Rect::operator-(const Rect& rect)
{  //重载了-号运算符的实现
    assert(this->rows == rect.rows &&
           this->cols == rect.cols);  //断言函数，可以保证矩阵的大小相等
    Rect rectTemp(rect.rows, rect.cols);
    for (int i = 0; i < rect.rows; i++) {
        for (int j = 0; j < rect.cols; j++) {
            rectTemp.head[i][j] = rect.head[i][j] - this->head[i][j];
        }
    }
    return rectTemp;
}
/*-------------------------------------------------------------*/
Rect::Rect(const Rect& rectTemp)
{  //用深拷贝的方式来初始化一个矩阵的构造函数
    this->head = new int*[rectTemp.rows];
    this->rows = rectTemp.rows, this->cols = rectTemp.cols;
    for (int i = 0; i < rectTemp.rows; i++) {
        this->head[i] = new int[rectTemp.cols];
        for (int j = 0; j < rectTemp.cols; j++) {
            this->head[i][j] = rectTemp.head[i][j];
        }
    }
}
/*-------------------------------------------------------------*/
void Rect::show()
{  // show函数，用于展示打印的函数
    int rows = this->rows, cols = this->cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << this->head[i][j] << " ";
        }
        puts("");
    }
}
/*-------------------------------------------------------------*/
void Rect::input()
{  // input函数，用来cin输入更改的函数
    std::cout << "Please input you rect" << std::endl;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            std::cin >> this->head[i][j];
        }
    }
}
/*-------------------------------------------------------------*/
void Rect::find(int x, int y)
{  // find查询函数，用来查询对应的下标的值
    std::cout << "result:" << std::endl;
    std::cout << head[x][y] << std::endl;
}
/*-------------------------------------------------------------*/
Rect::~Rect()
{  //析构函数的实现
    int** headTemp = this->head;
    for (int i = 0; i < this->rows; i++) {
        if (headTemp[i] != nullptr)
            delete headTemp[i];
    }
    if (this->head != nullptr)
        delete this->head;
}
/*--------------------------------------------------------------*/
// Rect.cpp
#include "Rect.h"
/*--------------------------------------------------------------*/
Rect::Rect(int rows, int cols)
{                                    //���캯��
    assert(rows >= 0 && cols >= 0);  //�����Ƿ������������Ƿ�С����
    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    this->head = arr, this->rows = rows, this->cols = cols;
}
/*--------------------------------------------------------------*/
Rect Rect::operator+(const Rect& rect)
{  //������+���������ʵ��
    assert(this->rows == rect.rows &&
           this->cols == rect.cols);  //���Ժ��������Ա�֤����Ĵ�С���
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
{  //������-���������ʵ��
    assert(this->rows == rect.rows &&
           this->cols == rect.cols);  //���Ժ��������Ա�֤����Ĵ�С���
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
{  //������ķ�ʽ����ʼ��һ������Ĺ��캯��
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
{  // show����������չʾ��ӡ�ĺ���
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
{  // input����������cin������ĵĺ���
    std::cout << "Please input you rect" << std::endl;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            std::cin >> this->head[i][j];
        }
    }
}
/*-------------------------------------------------------------*/
void Rect::find(int x, int y)
{  // find��ѯ������������ѯ��Ӧ���±��ֵ
    std::cout << "result:" << std::endl;
    std::cout << head[x][y] << std::endl;
}
/*-------------------------------------------------------------*/
Rect::~Rect()
{  //����������ʵ��
    int** headTemp = this->head;
    for (int i = 0; i < this->rows; i++) {
        if (headTemp[i] != nullptr)
            delete headTemp[i];
    }
    if (this->head != nullptr)
        delete this->head;
}
/*--------------------------------------------------------------*/
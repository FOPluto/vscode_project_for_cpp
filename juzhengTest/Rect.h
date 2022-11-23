// Rect.h
#pragma once
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>

class Rect {
  private:
    int** head;  //ָ��
  public:
    int rows;  //��¼����������Ϊ����
    int cols;  //��¼����������Ϊ����
  public:
    Rect() {}                   //�޲ι��캯��
    Rect(int** h) : head(h) {}  //�ö�ά��������ʼ������Ĺ��캯��
    Rect(int rows, int cols);  //��rows��cols����ʼ������Ĺ��캯��
    Rect(const Rect& rectTemp);  //������ķ�ʽ����ʼ��һ������Ĺ��캯��

    ~Rect();  //��������

    void show();  // show����������չʾ��ӡ�ĺ���

    void input();  // input����������cin������ĵĺ���

    void find(int x, int y);  // find��ѯ������������ѯ��Ӧ���±��ֵ

    Rect operator+(const Rect& rect);  //������+�������

    Rect operator-(const Rect& rect);  //������-�������
};
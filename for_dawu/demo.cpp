#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

const int N = 100010;

typedef pair<int, vector<double>::iterator> PII;

//肖维涅的系数表
double test[11] = {0 ,0 ,0 ,0 ,0 ,1.65, 1.73, 1.80, 1.86, 1.92, 1.96};

class Solusion{
  private:
    vector<double> arr;

    vector<PII> check;

    bool have_zero_error = false;//是否有零点误差?
    double zero_error;
    double math_standard_deviation;
    double E;

    int num;

    char name[100];

    double average_value;

    double standard_deviation;

    double Instrument_error;

    //获取平均值
    void get_average_value(){
        printf("\n1、计算%s平均值:\n", name);

        double sum = 0;
        for(int i = 0;i < num;i++){
            sum += arr[i];
        }
        this->average_value = sum / num;
        printf("d平均值 = %lf\n", average_value);
    }
    //获取标准偏差
    void get_standard_deviation(){
        printf("\n2、测量列的标准偏差：\n");
        double sum = 0;
        for(int i = 0;i < num;i++){
            sum += pow((arr[i] - average_value), 2);
        }
        this->standard_deviation = sqrt(sum / (num - 1));
        printf("S(d) = %lf\n", standard_deviation);
    }

    //肖维涅准则检查
    void ChauvignyCheck(){
        printf("\n3、根据肖维涅准则，d平均值+-cn*S(d) = ");
        double lower = average_value - test[num] * standard_deviation;
        double upper = average_value + test[num] * standard_deviation;

        printf(" (%lf, %lf)mm\n", lower, upper);

        for(auto i = arr.begin();i != arr.end();i++){
            if(*i < lower || *i > upper){
                check.push_back({*i, i});
            }
        }
        if(!check.empty()) {
            PII max_item;
            max_item.first = 0;
            for(auto i = arr.begin();i != arr.end();i++){
                if(max_item.first < *i) max_item = {*i, i};
            }
            arr.erase(max_item.second);
            check.clear();
            ChauvignyCheck();
            return;
        }
        printf("此时，所有的数据都处在了此范围里边\n");
    }

    //修正零点误差
    void Fixed_zero_error(){
        if(!have_zero_error) return;
        printf("\n4、修正零点误差：d = d - (%lf)\n", this->zero_error);
        this->average_value -= this->zero_error;
    }

    //算数平均值的标准偏差
    void get_math_standard_deviation(){
        printf("\n5、计算算数平均值的标准偏差：\n");
        printf("\tS(d平均值) = S(d) / 根号下n = %lf / 根号下%d\n", standard_deviation, num);
        this->math_standard_deviation = standard_deviation / sqrt(num);
        printf("%lf\n", this->math_standard_deviation);
    }

    //偏差比较
    void Bias_comparison(){
        printf("\n6、偏差比较\n");
        printf("\t将S(d平均值) = %lf，与仪器误差限%lf比较，较大值作为标准偏差，则S(d平均值) = %lf\n",
            math_standard_deviation, Instrument_error, max(math_standard_deviation, Instrument_error));
        
        math_standard_deviation = max(math_standard_deviation, Instrument_error);
    }

    //相对误差
    void relative_error(){
        this->E = 100 * math_standard_deviation / (average_value);
        printf("\n7、相对误差：%lf%", E);
    }

    //展示结果
    void show_res(){
        printf("\n8、%s的测量结果表达式为：\n");
        printf("\td = (%lf, %lf)\n", average_value, math_standard_deviation);
        printf("\tE = %lf%\n", E);
    }

    void input(){
        printf("请输入实验要测量的量: \n");
        scanf("%s", this->name);
        for(int i = 0;i < num;i++){
            double item;
            scanf("%lf", &item);
            this->arr.push_back(item);
        }
        printf("请输入仪器误差限：\n");
        cin >> Instrument_error;
        printf("请输入零差：\n");
        cin >> zero_error;
    }

  public:
    
    Solusion(int num, bool have_zero_error){
        this->num = num;
        this->have_zero_error = have_zero_error;
    }
    void compute(){
        input();
        get_average_value();
        get_standard_deviation();
        ChauvignyCheck();
        Fixed_zero_error();
        get_math_standard_deviation();
        Bias_comparison();
        relative_error();
        show_res();
    }
};


int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    Solusion solution(10, true);
    solution.compute();

    //double res = 5.3 / 239.189;
    return 0;
}

// 14.40
// 14.45
// 14.37
// 14.42
// 14.40
// 14.39
// 14.36
// 14.31
// 14.35
// 14.37

// 1.963
// 1.962
// 1.966
// 1.964
// 1.963
// 1.961
// 1.965
// 1.967
// 1.961
// 1.960
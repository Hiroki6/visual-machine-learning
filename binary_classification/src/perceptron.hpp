//
//  perceptron.hpp
//  machine learning
//
//  Created by 藤野宏樹 on 2016/06/09.
//
//
/*
   パーセプトロンによる２値線形分類
   */

#ifndef perceptron_hpp
#define perceptron_hpp

#pragma once
#include <stdio.h>
#include "ofMain.h"

const int W_DIM = 3; // 重み行列の次元

class Perceptron{
private:
    const int N = 200; // データ数
    double learnrate = 0.01; // 学習率
    float *W; // 重み行列
    int mean1[2] = {-2, 2};
    int mean2[2] = {2, -2};
    double cov[2][2] = {{1.0, 0.0}, {0.0, 1.0}};
    struct vec {
        float x;
        float y;
    };
    vec *data1;
    vec *data2;
    bool finish_flag;
    
public:
    void ~Perceptron(); // デストラクタ
    void train(); // 学習
    void setup();
    void update();
    void draw();

};

#endif /* perceptron_hpp */

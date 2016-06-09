//
//  perceptron.cpp
//  machine learning
//
//  Created by 藤野宏樹 on 2016/06/09.
//
//

#include "perceptron.hpp"
#include <random>

void Perceptron::setup(){
    
    W = new float[W_DIM];
    data1 = new vec[N];
    data2 = new vec[N];
    random_device rd;
    mt19937 mt(rd());
    normal_distribution<float> rand100(0, 99);
    normal_distribution<> norm1(100, 50);
    normal_distribution<> norm2(-100, 50);
    for(int i = 0; i < N; i++){
        data1[i].x = norm1(mt);
        data1[i].y = norm2(mt);
        data2[i].x = norm2(mt);
        data2[i].y = norm1(mt);
    }
    for(int i = 0; i < W_DIM; i++){
        W[i] = 1.0;
    }
    finish_flag = false;
}

void Perceptron::update(){
    
    int correct_num = 0;
    if(!finish_flag){
        for(int i = 0; i < N; i++){
            float sum1 = W[0] + W[1]*data1[i].x*1.0 + W[2]*data1[i].y*1.0;
            float sum2 = W[0]*(-1.0) + W[1]*data2[i].x*(-1.0) + W[2]*data2[i].y*(-1.0);
            if(sum1 > 0){
                correct_num += 1;
            }else{
                W[0] += learnrate * 1.0;
                W[1] += learnrate * data1[i].x * 1.0;
                W[2] += learnrate * data1[i].y * 1.0;
            }
            if(sum2 > 0){
                correct_num += 1;
            }else{
                W[0] += learnrate * (-1.0);
                W[1] += learnrate * data1[i].x * (-1.0);
                W[2] += learnrate * data1[i].y * (-1.0);
            }
        }
        if(correct_num == N*2) finish_flag = true;
    }
}

void Perceptron::draw(){
    for(int i = 0; i < N; i++){
        ofSetColor(249, 37, 0);
        ofDrawCircle(data1[i].x, data1[i].y, 3);
        ofSetColor(50, 204, 18);
        ofDrawCircle(data2[i].x, data2[i].y, 3);
    }
    for(float i = -400.0; i < 400.0; i += 0.8){
        ofSetColor(200, 200, 0);
        float y = -W[1]/W[2] * i - W[0]/W[2];
        ofDrawCircle(i, y, 1);
    }
}

void Perceptron::train(){

}
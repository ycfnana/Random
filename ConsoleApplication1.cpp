// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include"RandomForest.h"
#include"MnistPreProcess.h"
#include <string>
#include<iostream>

#define TRAIN_NUM 1234800
#define TEST_NUM 1234800
#define FEATURE 12
#define NUMBER_OF_CLASSES 2

using namespace std;

int main(int argc, const char * argv[])
{
	

	//1. prepare data
	float**trainset;
	float** testset;
	float*trainlabels;
	float*testlabels;
	trainset = new float*[TRAIN_NUM];
	testset = new float*[TRAIN_NUM];
	trainlabels = new float[TRAIN_NUM];
	testlabels = new float[TEST_NUM];
	for (int i = 0; i<TRAIN_NUM; ++i)
	{
		testset[i] = new float[FEATURE];
	}
	RandomForest randomForest("F:\\RandomForest.Model");
	const char* train_path = "F:\\cuSizeDecision\\train_data.csv";
	const char* label_path = "F:\\cuSizeDecision\\labels.csv";

	readData(testset, testlabels, train_path,label_path);
	
	//	readData(trainset,trainlabels,
	//        "/Users/xinling/PycharmProjects/MNIST_data/train-images-idx3-ubyte",
	//		"/Users/xinling/PycharmProjects/MNIST_data/train-labels-idx1-ubyte");
	//	readData(testset,testlabels,
	//        "/Users/xinling/PycharmProjects/MNIST_data/t10k-images-idx3-ubyte",
	//		"/Users/xinling/PycharmProjects/MNIST_data/t10k-labels-idx1-ubyte");

	//2. create RandomForest class and set some parameters
	//RandomForest randomForest(18, 10, 10, 0);

	//3. start to train RandomForest
	//	randomForest.train(trainset,trainlabels,TRAIN_NUM,FEATURE,10,true,56);//regression
	//randomForest.train(trainset, trainlabels, TRAIN_NUM, FEATURE, 2, false);//classification

	//restore model from file and save model to file
	//randomForest.saveModel("F:\\RandomForest_new.Model");
	//randomForest.readModel("F:\\RandomForest.Model");
	
	
	//predict single sample
	//  float resopnse;
	//	randomForest.predict(testset[0],resopnse);

	//predict a list of samples
	float*resopnses = new float[TEST_NUM];
	randomForest.predict(testset, TEST_NUM, resopnses);
	float errorRate = 0;
	for (int i = 0; i<TEST_NUM; ++i)
	{
		if (resopnses[i] != testlabels[i])
		{
			errorRate += 1.0f;
		}
		//for regression
		//		float diff=abs(resopnses[i]-testlabels[i]);
		//		errorRate+=diff;
	}
	errorRate /= TEST_NUM;
	printf("the total error rate is:%f\n", errorRate);

	//delete[] resopnses;
	for (int i = 0; i<TRAIN_NUM; ++i)
	{
		delete[] trainset[i];
	}
	/*for (int i = 0; i<TEST_NUM; ++i)
	{
		delete[] testset[i];
	}*/
	delete[] trainlabels;
	delete[] testlabels;
	delete[] trainset;
	delete[] testset;
	system("pause");
	return 0;
};

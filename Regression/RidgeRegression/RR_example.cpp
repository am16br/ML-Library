//g++ -std=c++11 RR_example.cpp ../../ReadMatrix/ReadMatrix.cpp RidgeRegression.cpp -o RR_example && ./RR_example
#include "../../ReadMatrix/ReadMatrix.h"
#include "RidgeRegression.h"
#include <Eigen/Dense>
#include <iostream>
using namespace std;
using namespace Eigen;
#define LINE cout<<string(65,'-')<<endl;

int main()
{
	ReadMatrix dataReader;
	string filename = "dataset";
	string delimiter = ",	";
	MatrixXd data = dataReader.read(filename, delimiter);

	LINE;
	RR rr;
	rr.train(data);

	//predict on first 20 X;
	LINE;
	cout << "Prediction of y on first 20 x: " << endl << endl;
	cout << rr.predict(data.block(0, 0, 20, data.cols() - 1)).transpose() << endl<<endl;
	cout << (data.block(0, data.cols() - 1, 20, 1)).transpose() << endl;
	LINE;
}

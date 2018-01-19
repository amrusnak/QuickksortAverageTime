//Alex Rusnak, October 18th 2017
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <array>
#include <cstdlib> 
#include <fstream>
#include <chrono>
#include <sstream>

using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;
using std::string;


void quickSort(double arr[], int left, int right) { // actual sorting function
      int i = left, j = right;
      double tmp;
      double pivot = arr[(left + right) / 2];
      

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
	};
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

std::vector<double> dataCreator(int inputSize){ // creates arrays of random data
	std::vector<double> output(inputSize);
	for(int i = 0; i< inputSize; ++i){
	 	double random_double = ((double)rand() / 100000000);
	 	output[i]= random_double;
	}
	return output; 
}

void writeFile(string fileName, double arr[], int size){ // writes array to file
	ofstream fileMaker;
	fileMaker.open(fileName);
	double z = 0;
	for(int i=0; i<size; ++i){
		z= arr[i];
		fileMaker << z << " "; 
	} 
	fileMaker.close();
}

string createDataSet(int i, int size, string name){ //creates datasets and writes it to a particular name for scaling
		string arbit = name;
		stringstream ss;
		ss << i;
		string str = ss.str();
		string give = arbit + str + ".txt";
		std::vector<double> dataSet = dataCreator(size);
		double arr[size];
		for (int i = 0; i < size; ++i){
			
			arr[i] = dataSet[i];
		}

		writeFile(give, arr, size);
		return give;
}


double doTask(string inputFile, string outputFile){ // performs all the file io and calls most other methods.. a faux main so I can test
	auto start = std::chrono::high_resolution_clock::now();
	ifstream inFile;
	inFile.open(inputFile);
	int n = 0;
	double x = 0;
	while (inFile >> x){
		++n;
	}
	ifstream inFile2;
	inFile2.open(inputFile);
	double array[n];
	double u = 0;
	for (int i = 0; i< n; ++i){
		inFile2 >> u; 
		array[i] = u;
	}

	quickSort(array, 0, n-1);

	stringstream sss;
		sss << n;
		string str = sss.str();

auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;

ofstream fileTail;
fileTail.open(outputFile, std::fstream::app);

fileTail << "Input: " + str + "          Time: " << (1000 * elapsed.count()) << endl;;
fileTail << endl; //Wasn't sure if we were supposed to output to the file or the screen..
cout << "Input: " + str + "          Time: "<< (1000 * elapsed.count()) << endl;  
return (1000 * elapsed.count()) ;
}


     
int main(int argc, char** argv) {
	int i = 1; 
	while (i == 1){ // these loops create the data and run the algorithmn the correct amount of times. Probably should have made this a function but ehhhh
		string z = "Ten";
	double x;
	string outputFile = "rusnak_Alexander_ExecutionTime.txt";
	for (int i = 0; i < 100; ++i){
		string inputFile = createDataSet(i, 10, z);
	x =  x + doTask(inputFile, outputFile); 
	}
	double avg = x/100;
	ofstream fileT;
	fileT.open(outputFile, std::fstream::app);
	fileT << "Average time for input size 10: " << avg << endl;
	fileT.close();
	ofstream fileF;
	fileF.open("rusnak_Alexander_AverageExecutionTime.txt", std::fstream::app);
	fileF << "Average time for input size 10: " << avg << endl;
	fileF.close();
	++i;

	} 
	i = 1; 
	while (i == 1){
		string z = "Hundred";
		int size = 100;
	double x;
	string outputFile = "rusnak_Alexander_ExecutionTime.txt";
	for (int i = 0; i < 100; ++i){
		string inputFile = createDataSet(i, size, z);
	x =  x + doTask(inputFile, outputFile); 
	}
	double avg = x/100;
	ofstream fileT;
	fileT.open(outputFile, std::fstream::app);
	fileT << "Average time for input size 100: " << avg << endl;
	fileT.close();
	ofstream fileF;
	fileF.open("rusnak_Alexander_AverageExecutionTime.txt", std::fstream::app);
	fileF << "Average time for input size 100: " << avg << endl;
	fileF.close();
	++i;

	} 
	i = 1; 
	while (i == 1){
		string z = "Thousand";
		int size = 1000;
	double x;
	string outputFile = "rusnak_Alexander_ExecutionTime.txt";
	for (int i = 0; i < 100; ++i){
		string inputFile = createDataSet(i, size, z);
	x =  x + doTask(inputFile, outputFile); 
	}
	double avg = x/100;
	ofstream fileT;
	fileT.open(outputFile, std::fstream::app);
	fileT << "Average time for input size 1000: " << avg << endl;
	fileT.close();
	ofstream fileF;
	fileF.open("rusnak_Alexander_AverageExecutionTime.txt", std::fstream::app);
	fileF << "Average time for input size 1000: " << avg << endl;
	fileF.close();
	++i;

	} 
	i = 1; 
	while (i == 1){
		string z = "TenThou";
		int size = 10000;
	double x;
	string outputFile = "rusnak_Alexander_ExecutionTime.txt";
	for (int i = 0; i < 100; ++i){
		string inputFile = createDataSet(i, size, z);
	x =  x + doTask(inputFile, outputFile); 
	}
	double avg = x/100;
	ofstream fileT;
	fileT.open(outputFile, std::fstream::app);
	fileT << "Average time for input size 10000: " << avg << endl;
	fileT.close();
	ofstream fileF;
	fileF.open("rusnak_Alexander_AverageExecutionTime.txt", std::fstream::app);
	fileF << "Average time for input size 10000: " << avg << endl;
	fileF.close();
	++i;

	} 

	i = 1; 
	while (i == 1){
		string z = "hunthou";
		int size = 100000;
	double x;
	string outputFile = "rusnak_Alexander_ExecutionTime.txt";
	for (int i = 0; i < 100; ++i){
		string inputFile = createDataSet(i, size, z);
	x =  x + doTask(inputFile, outputFile); 
	}
	double avg = x/100;
	ofstream fileT;
	fileT.open(outputFile, std::fstream::app);
	fileT << "Average time for input size 100000: " << avg << endl;
	fileT.close();
	ofstream fileF;
	fileF.open("rusnak_Alexander_AverageExecutionTime.txt", std::fstream::app);
	fileF << "Average time for input size 100000: " << avg << endl;
	fileF.close();
	++i;

	} 




}

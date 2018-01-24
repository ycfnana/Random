#include"MnistPreProcess.h"
#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>  
using namespace std;
void readData(float** dataset, float*labels,const char* dataPath, const char*labelPath)
{
	
	ifstream dataFile(dataPath);
	ifstream labelsFile(labelPath);
	string line;
	int i = 0;
	int index = 0;
	while (getline(dataFile, line)){
		
		if (i < 1234800){
			
			istringstream sin(line); //�������ַ���line���뵽�ַ�����istringstream��  

			vector<string> fields; //����һ���ַ�������  
			string field;
			int j = 0;
			
			while (getline(sin, field, ',')) //���ַ�����sin�е��ַ����뵽field�ַ����У��Զ���Ϊ�ָ���  
			{
				
				
				dataset[index][j] = atoi(field.c_str());
				j++;
			}
			index++;
		}
		
		
		
		
		i++;
		

	}
	i = 0;
	index = 0;
	while (getline(labelsFile, line)){

		if (i < 1234800){
			if (line.compare("True")){
				labels[index] = 1;
			}
			else{
				labels[index] = 0;
			}
			index++;
			
		}
		
		i++;
		

		
	}

	dataFile.close();
	labelsFile.close();
};

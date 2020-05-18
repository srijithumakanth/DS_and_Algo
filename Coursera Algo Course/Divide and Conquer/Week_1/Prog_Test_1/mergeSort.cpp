#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<int> inputVector;
using std::string;

void mergeSort(int low, int high);
void merge(int low, int high);

bool readInputFile(string fileName)
{
    // Open the File
	std::ifstream stream(fileName.c_str());
   
    if (stream)
    {
        int count = 0;

        while (stream >> count)
        {
            inputVector.push_back(count);
            ++count;
        }
        
        std::cout << "inputVector populated\n";
        // Close the file
        stream.close();
        
        return true;
    }
    else
    {
        std::cout << "Cannot open the File : "<<fileName<<std::endl;
		return false;
    }
}

void mergeSort(int low, int high) {
	if (high > low) {
		mergeSort(low, (high + low) / 2);
		mergeSort(((high + low) / 2) + 1, high);
		merge(low, high);
	}
}

void merge(int low, int high) {
	std::vector<int> firstVector, secondVector;
	int j = 0, k = 0;
	for (int i = low; i <= high; i++) {
		if (i <= (high + low) / 2)
			firstVector.push_back(inputVector[i]);
		else
			secondVector.push_back(inputVector[i]);
	}
	for (int i = low; i <= high; i++) {
		if (j == firstVector.size()) {
			inputVector[i] = secondVector[k];
			// outputVector[i] = secondVector[k];
			k++;
		} else if (k == secondVector.size()) {
			inputVector[i] = firstVector[j];
			// outputVector[i] = firstVector[j];
			j++;
		} else if (firstVector[j] <= secondVector[k]) {
			inputVector[i] = firstVector[j];
			// outputVector[i] = firstVector[j];
			j++;
		} else {
			inputVector[i] = secondVector[k];
			// outputVector[i] = secondVector[k];
			k++;
		}
	}
}

void displayTitle() {
	std::cout << "Merge Sort" << std::endl << std::endl;
}

void createVector() {
	for (int i = 10; i > 0; i--)
		inputVector.push_back(i);
}

void displayInput() {
	std::cout << "Input: ";
	for (int i = 0; i < inputVector.size(); i++)
	{
		std::cout << inputVector[i] << " ";
		// outputVector.push_back(inputVector[i]);
	}
	// outputVector = inputVector;
	std::cout << std::endl << std::endl;
}

void displayOutput() {
	std::cout << "Output: ";
	for (int i = 0; i < inputVector.size(); i++)
		std::cout << inputVector[i] << " ";
}

// void displayOutput() {
// 	std::cout << "Output: ";
// 	for (int i = 0; i < outputVector.size(); i++)
// 		std::cout << outputVector[i] << " ";
// }

int main() {
	// displayTitle();
	// createVector();
	displayInput();
	bool result = readInputFile("IntegerArray.txt");
	if (result)
	{
		// displayInput();
		mergeSort(0, inputVector.size() - 1);
	}
	// mergeSort(0, inputVector.size() - 1);
	// displayOutput();
	// displayInput();

}
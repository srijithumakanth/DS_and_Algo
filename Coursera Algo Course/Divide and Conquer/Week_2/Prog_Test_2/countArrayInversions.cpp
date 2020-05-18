#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using std::vector;
using std::string;

class MergeSort
{
    public:
        vector<int> inputVector;
        size_t inversionCount = 0;

        void mergeSort(int low, int high);
        void merge(int low, int high);
        void displayInput();
        void displayOutput();
        void createVector(int num);
        bool readInputFile(string fileName);
    
    private: 
        vector<int> outputVector;
         
};

bool MergeSort::readInputFile(string fileName)
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


void MergeSort::mergeSort(int low, int high)
{
    if (high > low)
    {
        mergeSort(low, (low + high) / 2);
        mergeSort(((low + high) / 2) + 1, high);
        merge(low, high);
    }
}

void MergeSort::merge(int low, int high)
{
    vector<int> firstVector, secondVector;

    int j = 0, k = 0;
    
    // Divide
    for (int i = low; i <= high; i++)
    {
        if (i <= (low + high) / 2)
        {
            firstVector.push_back(outputVector[i]);
        }
        else
        {
            secondVector.push_back(outputVector[i]);
        }   
    }
    
    for (int i = low; i <= high; i++)
    {
        if (j == firstVector.size())
        {
            outputVector[i] = secondVector[k];
            k++;
        }
        else if (k == secondVector.size())
        {
            outputVector[i] = firstVector[j];
            j++;
        }
        else if (firstVector[j] <= secondVector[k])
        {
            outputVector[i] = firstVector[j];
            j++;
        }
        else
        {
            outputVector[i] = secondVector[k];
            k++;
            for (int l = j; l <= firstVector.size() - 1; l++)
            {
                inversionCount++;
            }
        }
        
    }
}

void MergeSort::displayInput()
{
    std::cout << "Merge Sort" << std::endl << std::endl;
    std::cout << "Input: ";
	// for (int i = 0; i < inputVector.size(); i++)
    // {
    //     std::cout << inputVector[i] << " ";
    // }

    // Initialize the O/P as I/P for manipulation by merge.
    outputVector = inputVector;
	std::cout << std::endl << std::endl;
}

void MergeSort::displayOutput()
{
    std::cout << "Output: ";
	for (int i = 0; i < outputVector.size(); i++)
		std::cout << outputVector[i] << " ";
    std::cout <<  std::endl;
}

void MergeSort::createVector(int num)
{
    for (int i = num; i > 0; i--)
    {
        inputVector.push_back(i);
    }
    inputVector.push_back(25);
    inputVector.push_back(15);
    inputVector.push_back(31);
    inputVector.push_back(11);
}

int main()
{
    MergeSort m;
    // m.createVector(10);
    // bool result = m.readInputFile("IntegerArray.txt");
    bool result = m.readInputFile("IntegerArray.txt");
    if (result)
    {
        m.displayInput();
        m.mergeSort(0, m.inputVector.size() - 1);
        std::cout << "Inversion Count: " << m.inversionCount << std::endl;
    }
    else
    {
        std::cout << "Error reading file!\n";
    }
    
    // m.displayOutput();
}
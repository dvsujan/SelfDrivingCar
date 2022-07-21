#include<iostream>
#include<fstream> 
#include<string> 
#include<iostream> 

class FileHandler{ 
private:
    std::string filePath ; 
    std::ofstream file ;
public:
    FileHandler(std::string filePath,std::string columns){ 
        this->filePath = filePath;
        file.open(filePath,std::ios::app);
        file<<columns<<std::endl;
        file.close(); 
    }
    bool is_open(){ 
        return file.is_open();
    }
    void writeLineToFile(std::string line){ 
        file.open(filePath,std::ios::app);
        file<<line<<std::endl;
        file.close(); 
    }
    void close(){ 
        file.close();
    }
};
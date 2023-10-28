#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <sys/stat.h>




//1. Write a program in C++ to create and store information in a text file.
void ex1(std::string fileName) {
  std::string str;
  std::ofstream file;

  file.open(fileName, std::ios::out);
  if (!file.is_open())
  {
    std::cout << "file failed to open" << std::endl;
  }
  std::cout << "Input a sentence for the file: ";
  std::getline(std::cin, str);
  file << str;
  if (file.is_open())
  {
    file.close();
    std::cout << "\nthe file " << fileName << " created successfuly" << std::endl;
  }
}

//2. Write a program in C++ to read an existing file.
void ex2(std::string filePath) {
  std::ifstream file;
  file.open(filePath, std::ios::in);
  if (!file.is_open())
  {
    std::cout << "file failed to open" << std::endl;
  }
  std::string line;
  while (getline(file, line)) {
    std::cout << line << std::endl;
 }
  file.close();
}
//3. Write a program in C++ to write multiple lines to a text file.
void ex3(std::string filePath) {
  std::string str;
  int num{ 0 };
  std::ofstream file;

  std::cout << "enter number of lines" << std::endl;
  
  std::cin >> num;
  if (!std::cin)
  {
    std::cout << "unvaled input" << std::endl;
  }
  else {
    file.open(filePath, std::ios::out);
    if (!file.is_open())
    {
      std::cout << "file failed to open" << std::endl;
    }
    std::cin.ignore(); // Ignore the new line character
    for (size_t i = 0; i < num; i++)
    {
      std::cout << "enter the line number: " << i + 1 << std::endl;
      std::getline(std::cin, str);
      file << str << std::endl;
    }
    std::cout << "The file was opened and written successfully" << std::endl;
  }
  if (file.is_open())
  {
    file.close();
    std::cout << "file is closed" << std::endl;
  }
}
//4. Write a program in C++ to read the file and store the lines in an array.
std::vector<std::string> ex4(std::string filePath) {
  std::vector<std::string> vec;
  std::ifstream file;
  file.open(filePath, std::ios::in);
  if (!file.is_open())
  {
    std::cout << "file failed to open" << std::endl;
  }
  std::string line;
  while (getline(file, line)) {
    //std::cout << line << std::endl;
    vec.push_back(line);
  }
  if (file.is_open())
  {
    file.close();
  }
  return vec;
}
//5. Write a program in C++ to find the number of lines in a text file
int ex5(std::string filePath) {
  int lineCount{ 0 };
  std::ifstream file;
  file.open(filePath, std::ios::in);
  if (!file.is_open())
  {
    std::cout << "file failed to open" << std::endl;
  }
  std::string line;
  while (getline(file, line)) {
    //std::cout << line << std::endl;
    lineCount++;
  }
  file.close();
  return lineCount;
}
std::vector < std::string > customSplit(std::string str, char separator) {
  std::vector < std::string > strings;
  int startIndex = 0, endIndex = 0;
  for (int i = 0; i <= str.size(); i++) {

    // If we reached the end of the word or the end of the input.
    if (str[i] == separator || i == str.size()) {
      endIndex = i;
      std::string temp;
      temp.append(str, startIndex, endIndex - startIndex);
      strings.push_back(temp);
      startIndex = endIndex + 1;
    }
  }
  return strings;
}
//7. Write a program in C++ to count the number of words and characters in a file.
void ex7(std::string path) {
  int numOfWords{ 0 }, numOfCharacters{ 0 };
  std::ifstream file;
  file.open(path);
  if (!file.is_open())
  {
    std::cout << "file failed open" << std::endl;
  }
  std::string line{""};
  std::vector<std::string> wordsInline();
  std::cout << "The content of the file test.txt are: " << std::endl;
  while (getline(file, line))
  {
    std::cout << line << std::endl;
    numOfCharacters += line.size();
    numOfWords += customSplit(line, ' ').size();

  }
  if (file.is_open())
  {
    file.close();
  }
  std::cout << "The number of words in the file test.txt are : " << numOfWords << std::endl;
  std::cout << "The number of characters in the file test.txt are : " << numOfCharacters << std::endl;
}
//8. Write a program in C++ to delete a specific line from a file.
void ex8(std::string filName, int lineNuToDelete) {
  std::ifstream file;
  std::fstream tempFile;
  std::string line, tNameFile{ "temp.txt" };
  lineNuToDelete--;
  int counter{ 0 };
  file.open(filName, std::ios::in);
  if (!file.is_open())
  {
    std::cout << "file failed to open" << std::endl;
  }
  tempFile.open(tNameFile, std::ios::out);
  if (!tempFile.is_open())
  {
    std::cout << "tempfile failed to open" << std::endl;
    file.close();
  }
  while (getline(file, line)) {
    if (counter != lineNuToDelete) {
      tempFile << line<<std::endl;
    }
    counter++;
  }
  if (tempFile.is_open())
  {
    tempFile.close();
  }
  if (file.is_open())
  {
    file.close();
  }
  remove(filName.c_str());
  rename(tNameFile.c_str(), filName.c_str()); // rename the temporary file to the original name

}
//9. Write a program in C++ to replace a specific line with another text in a file.
void ex9(std::string filName, int lineNuToDelete, std::string text) {
  std::ifstream file;
  std::fstream tempFile;
  std::string line, tNameFile{ "temp.txt" };
  lineNuToDelete--;
  int counter{ 0 };
  file.open(filName, std::ios::in);
  if (!file.is_open())
  {
    std::cout << "file failed to open" << std::endl;
  }
  tempFile.open(tNameFile, std::ios::out);
  if (!tempFile.is_open())
  {
    std::cout << "tempfile failed to open" << std::endl;
    file.close();
  }
  while (getline(file, line)) {
    if (counter != lineNuToDelete) {
      tempFile << line << std::endl;
    }
    else
    {
      tempFile << text << std::endl;
    }
    counter++;
  }
  if (tempFile.is_open())
  {
    tempFile.close();
  }
  if (file.is_open())
  {
    file.close();
  }
  remove(filName.c_str());
  rename(tNameFile.c_str(), filName.c_str()); // rename the temporary file to the original name

}
//10. Write a program in C++ to append multiple lines to the end of a text file.
void ex10(std::string filePath) {
  std::string str;
  int num{ 0 };
  std::ofstream file;

  std::cout << "enter number of lines" << std::endl;

  std::cin >> num;
  if (!std::cin)
  {
    std::cout << "unvaled input" << std::endl;
  }
  else {
    file.open(filePath, std::ios::app);
    if (!file.is_open())
    {
      std::cout << "file failed to open" << std::endl;
    }
    std::cin.ignore(); // Ignore the new line character
    for (size_t i = 0; i < num; i++)
    {
      std::cout << "enter the line number: " << i + 1 << std::endl;
      std::getline(std::cin, str);
      file << str << std::endl;
    }
    std::cout << "The file was opened and written successfully" << std::endl;
  }
  if (file.is_open())
  {
    file.close();
    std::cout << "file is closed" << std::endl;
  }
}
//12. Write a program in C++ to merge two files and write them to another file.
int ex12() {
  std::string fName1, fName2, fName3;
  char ch;
  std::ifstream file1, file2;
  std::ofstream newfile;

  std::cout << "what is the first file name?" << std::endl;
  std::cin >> fName1;
  file1.open(fName1);
  if (!file1)
  {
    std::cout << "The file " << fName1 << " is not exist or error in opening." << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "what is the second file name?" << std::endl;
  std::cin >> fName2;
  file2.open(fName2);
  if (!file2)
  {
    std::cout << "The file " << fName2 << " is not exist or error in opening." << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "what is the new file name?" << std::endl;
  std::cin >> fName3;
  newfile.open(fName3, std::ios::out);
  if (!file2)
  {
    std::cout << "The file " << fName3 << " is not exist or error in opening." << std::endl;
    return EXIT_FAILURE;
  }

  while (file1.get(ch))
  {
    newfile.put(ch);
  }
  newfile.put('\n');

  while (file2.get(ch))
  {
    newfile.put(ch);
  }
  newfile.put('\n');

  std::cout << "The two files merged into file " << fName3 << " successfully" << std::endl;
  file1.close();
  file2.close();
  newfile.close();
  return 0;
}
//13. Write a program in C++ to encrypt a text file.
int ex13(std::string fileName) {
  char ch;
  std::string encryptedFileName{ "encryptedFile.txt" };
  std::ifstream iffile;
  std::ofstream offile;

  iffile.open(fileName);
  if (!iffile)
  {
    std::cout << "The file " << fileName << " is not exist or error in opening." << std::endl;
    return EXIT_FAILURE;
  }
  offile.open(encryptedFileName);
  if (!offile)
  {
    std::cout << "The file " << encryptedFileName << " is not exist or error in opening." << std::endl;
    return EXIT_FAILURE;
  }
  while (iffile.get(ch))
  {
    ch += 100;
    offile.put(ch);
  }
  iffile.close();
  offile.close();
  std::cout << "The file " << fileName << " is successfully encrypted in file " << encryptedFileName << std::endl;
    return 0;
}
//14. Write a program in C++ to decrypt a previously encrypted file.
int ex14(std::string fileName) {
  char ch;
  std::string decryptedFileName{ "decryptedFile.txt" };
  std::ifstream iffile;
  std::ofstream offile;
  iffile.open(fileName);
  if (!iffile)
  {
    std::cout << "The file " << fileName << " is not exist or error in opening." << std::endl;
    return EXIT_FAILURE;
  }

  offile.open(decryptedFileName);
  if (!offile)
  {
    std::cout << "The file " << decryptedFileName << " is not exist or error in opening." << std::endl;
    return EXIT_FAILURE;
  }

  while (iffile.get(ch))
  {
    ch -= 100;
    offile.put(ch);
  }
  iffile.close();
  offile.close();
  std::cout << "The file " << fileName << " is successfully decrypted in file " << decryptedFileName << std::endl;
  return 0;
}
//15. Write a program in C++ to remove a file from the disk.
int ex15(std::string fileName) {
  if (std::remove(fileName.c_str()) !=0)
  {
    std::cout << "error removing the file " << fileName << std::endl;
  }
  else
  {
    std::cout << "the file " << fileName << " successfully removed." << std::endl;
  }
  return 0;
}
//16. A set of strings represent directory paths and a single character directory separator (/).
//Write a program in C++ language to get a part of the directory tree 
//that is common to all directories.
int ex16(std::vector<std::string> names, char sep) {
  int pos{ 0 };
  for (size_t pos = 0; ; pos++)
  {
    for (size_t i = 0; i < names.size(); i++)
    {
      if (names[i][pos]!= NULL && names[0][pos] == names[i][pos])
      {
        continue;
      }
      while (pos > 0 && names[0][--pos] != sep);
      std::cout << "The commen path is: " << names[0].substr(0, pos) << std::endl;
      return pos;
    }
  }
  return 0;
}


void ex18(std::ifstream file /*std::filesystem::path filePath*/)
{
  /*if (std::filesystem::exists(filePath))
  {
    std::filesystem::file_time_type time = std::filesystem::last_write_time(filePath);
    std::time_t modifiedTime = std::chrono::system_clock::to_time_t(time);
    std::cout << "Last modified time: " << std::ctime(&modifiedTime);
  }
  else
  {
    std::cout << "File not found.\n";
  }*/


  /*struct stat status;
  if (file)
  {
    fstat(fileno(file), &status);
    std::cout << "Last date of File modification: " << ctime(&status.st_ctime);
  }
  else
  {
    std::cout << "File not found.\n";
  }*/

}




int main()
{
  //ex1("test.txt");
  //ex2("test.txt");
  //ex3("test.txt");

  //std::vector<std::string> vec = ex4("test.txt");
  //for (size_t i = 0; i < vec.size(); i++)
  //{
  //  std::cout <<"vector element nu: "<<i<<"is -> "<< vec[i] << std::endl;
  //}

  /*int lineNumber = ex5("test.txt");
  std::cout << "The lines in the file test.txt are : " << lineNumber << std::endl;*/

  //ex7("test.txt");
  //ex8("test.txt", 1);
  //ex9("test.txt", 1, "Replacement did successfully..!!");
  //ex10("test.txt");
  //ex12();
  //ex13("test1.txt");
  //ex14("encryptedFile.txt");
  //ex15("test.txt");

  /*std::vector<std::string> names = {
        "/home/me/user/temp/a",
        "/home/me/user/temp/b",
        "/home/me/user/temp/c/d", };

  ex16(names, '/');*/

  //ex18("C:\\Users\\Praktikum\\source\\repos\\fileHandlingW3School\\fileHandlingW3School\\test2.txt")
  
}




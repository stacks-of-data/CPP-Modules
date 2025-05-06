#include <iostream>
#include <ctime>
#include "../includes/Array.hpp"

#define MAX_VAL 10
int main(int, char**)
{
	Array<int>* numbers;
	try
	{
		numbers = new Array<int>(MAX_VAL);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
    
    std::srand(time(NULL));
	for (size_t i = 0; i < MAX_VAL; i++)
		(*numbers)[i] = rand() % 101;
	std::cout << "Array preview:\n";
	for (size_t i = 0; i < MAX_VAL; i++)
		std::cout << (*numbers)[i] << '\n';
	std::cout << "Attempting access to index -1 and MAX_VAL:\n";
	try
	{
		std::cout << (*numbers)[-1] << '\n';
		std::cerr << "THATS NOT SUPPOSED TO HAPPEN!!!" << std::endl;
		delete numbers;
		return (EXIT_FAILURE);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << (*numbers)[MAX_VAL] << '\n';
		std::cerr << "THATS NOT SUPPOSED TO HAPPEN!!!" << std::endl;
		delete numbers;
		return (EXIT_FAILURE);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	delete numbers;
    return (EXIT_SUCCESS);
}

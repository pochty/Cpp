/*Комментарии и итерфейс пока не завезли :( 
* Не успел сделать все, как хотелось
*/
#include "StudentGroup.h"

int main()
{
	Student st("Jhon Doe", 1999, 9, 9);
	Student st1("Jhon One", 1998, 9, 9);
	Student st2("Jhon Two", 1997, 9, 9);
	StudentGroup gr("Test");
	gr.Push(st);
	gr.Push(st);
	gr.Push(st1);
	gr.Push(st2);
	std::cout << gr << "\n";
	gr.Remove("Jhon Doe");
	gr.Remove("-");
	std::cout << gr << "\n";
	gr.Push(st);
	gr.Push(st);
	std::cout << gr << "\n";

}
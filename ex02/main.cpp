/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:11:34 by maw               #+#    #+#             */
/*   Updated: 2025/10/09 18:52:26 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* NewA(void)
{
	return (new A()); 
}

Base* NewB(void)
{
	return (new B()); 
}

Base* NewC(void)
{
	return (new C());
}

Base* generate()
{
	Base* (*tabptr[3])() = {&NewA, &NewB, &NewC};
	Base *result;

	srand(static_cast<unsigned>(time(0)));
	int r = rand() % 3;

	result = (tabptr[r])();
	return (result);
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "Type: A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (a != NULL)
	{
		std::cout << "Type: B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(p);
	if (a == NULL)
	{
		std::cout << "Type: C" << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
	}
	catch (std::bad_cast)
	{
		std::cout << "Type: A" << std::endl;
		return ;		
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
	}
	catch (std::bad_cast)
	{
		std::cout << "Type: B" << std::endl;
		return ;		
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
	}
	catch (std::bad_cast)
	{
		std::cout << "Type: C" << std::endl;
		return ;		
	}		
}


int main()
{
	Base *pointer;
	
	pointer = generate();

	identify(pointer);
	return (0);
}
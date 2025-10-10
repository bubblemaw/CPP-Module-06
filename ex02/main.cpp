/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:11:34 by maw               #+#    #+#             */
/*   Updated: 2025/10/10 14:37:37 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* NewA(void)
{
	std::cout << "creating a new A" <<  std::endl;
	return (new A()); 
}

Base* NewB(void)
{
	std::cout << "creating a new B" <<  std::endl;	
	return (new B()); 
}

Base* NewC(void)
{
	std::cout << "creating a new C" <<  std::endl;	
	return (new C());
}

Base* generate()
{
	Base* (*tabptr[3])() = {&NewA, &NewB, &NewC};
	Base *result;

	srand(static_cast<unsigned int>(time(0)));
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
	if (b != NULL)
	{
		std::cout << "Type: B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "Type: C" << std::endl;
		return ;
	}
	std::cout << "aucun type bitch" <<  std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;		
	}
	catch (std::bad_cast)
	{
	
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;		
	}
	catch (std::bad_cast)
	{
				
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;		
	}
	catch (std::bad_cast)
	{
		
	}		
}


int main()
{
	Base *pointer;

	pointer = generate();

	identify(pointer);
	identify(*pointer);

	delete pointer;
	return (0);
}
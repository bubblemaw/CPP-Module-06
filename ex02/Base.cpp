/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:11:39 by maw               #+#    #+#             */
/*   Updated: 2025/10/09 17:56:52 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	std::cout << "Base Destructor" << std::endl;
}


// Base* Base::NewA(void)
// {
// 	return (new A); 
// }

// Base* Base::NewB(void)
// {
// 	return (new B); 
// }

// Base* Base::NewC(void)
// {
// 	return (new C); 
// }

// Base* Base::generate()
// {
// 	Base* (Base::*tabptr[3])() = {&Base::NewA, &Base::NewB, &Base::NewC};
// 	Base *result;

// 	srand(time(0));
// 	int r = rand() % 3;

// 	result = (this->*tabptr[r])();
// 	return (result);
// }

// void	Base::identify(Base* p)
// {
// 	A *a = dynamic_cast<A*>(p);
// 	if (a == NULL)
// 	{
// 		std::cout << "Type: A" << std::endl;
// 		return ;
// 	}
// 	B *b = dynamic_cast<B*>(p);
// 	if (a == NULL)
// 	{
// 		std::cout << "Type: B" << std::endl;
// 		return ;
// 	}
// 	C *c = dynamic_cast<C*>(p);
// 	if (a == NULL)
// 	{
// 		std::cout << "Type: C" << std::endl;
// 		return ;
// 	}
// }

// void	Base::identify(Base& p)
// {
// 	try
// 	{
// 		A &a = dynamic_cast<A&>(p);
// 	}
// 	catch (std::bad_cast)
// 	{
// 		std::cout << "Type: A" << std::endl;
// 		return ;		
// 	}
// 	try
// 	{
// 		B &b = dynamic_cast<B&>(p);
// 	}
// 	catch (std::bad_cast)
// 	{
// 		std::cout << "Type: B" << std::endl;
// 		return ;		
// 	}
// 	try
// 	{
// 		C &c = dynamic_cast<C&>(p);
// 	}
// 	catch (std::bad_cast)
// 	{
// 		std::cout << "Type: C" << std::endl;
// 		return ;		
// 	}		
// }

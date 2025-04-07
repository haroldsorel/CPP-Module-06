/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:39:56 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/07 19:39:57 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    Base *base;
    int num = std::rand() % 3;

    switch (num)
    {
        case 0:
            base = new A;
            std::cout << "An A was randomly generated!" << std::endl;
            break;
        case 1:
            base = new B;
            std::cout << "An B was randomly generated!" << std::endl;
            break;
        case 2:
            base = new C;
            std::cout << "An C was randomly generated!" << std::endl;
            break;
    }
    return (base);
}

/* Dynamic cast used with pointers checks type at runtime and returns a null pointer if the cast fails -> not compatible. */
void identify(Base *p)
{
    if (dynamic_cast<A*>(p)) 
        std::cout << "A!" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B!" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C!" << std::endl;
    else
        std::cout << "Unknown class" << std::endl;
}

/* Dynamic cast used with references checks type at runtime and throws an exception if the cast fails -> not compatible. */
void identify(Base& p) {
    try 
    {
        (void)dynamic_cast<A&>(p); //typecasted to void to ignore compiler value
        std::cout << "A!" << std::endl;
        return ;
    } catch (const std::exception& e) { std::cout << "not A" << std::endl; }
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B!" << std::endl;
        return ;
    } catch (const std::exception& e) { std::cout << "not B" << std::endl; }
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C!" << std::endl;
        return ;
    } catch (const std::exception& e) { std::cout << "not C" << std::endl; }
}

int main()
{
    std::srand(clock());

    std::cout << std::endl;
    std::cout << "Generating..." << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    Base *abc = generate();
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Identifying..." << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    identify(abc);
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Identifying..." << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    identify(*abc);
    std::cout << std::endl;
    delete abc;
    return (0);
}

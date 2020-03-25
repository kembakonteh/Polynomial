//
//  main.cpp
//  Program1
//
//  Created by Kemba Konteh on 1/9/20.
//  Copyright © 2020 Kemba Konteh. All rights reserved.
//
#include "Polynomial.hpp"
#include <iostream>

//================= This is my driver. Istructor's driver is at the bottom =======================
int main( )

{
cout << "========================== This is my driver ================================" << endl;
    cout << " " << endl;
    cout << "============= Testing the program to see if working as expected ===========" << endl;

  Polynomial p1, test;

 p1.changeCoefficient( 4, 4 );

  p1.changeCoefficient( 2.2, 2 );

  p1.changeCoefficient( -3.8, 3 );

  cout << "p1 = " << p1 << endl;



    p1.changeCoefficient( 1, 1 );

    p1.changeCoefficient( 5, 0 );

    p1.changeCoefficient( 7, 2 );

    p1.changeCoefficient( -2.8, 3 );

    cout << "p1 = " << p1 << endl;

    p1.changeCoefficient( 1, 2.2);

    cout << "p1 = " << p1 << endl;

    cout << " " << endl;

    cout << "========================= Testing negative powers =======================" << endl;

    test.changeCoefficient(4, -1);
    test.changeCoefficient(3,-2);
    test.changeCoefficient(2, -3);
    cout << "p1 = " << test << endl;

    cout << " " << endl;

    cout << "=================== More testing to ensure correctness ===================="<< endl;

    Polynomial testp2 = p1;

    testp2.changeCoefficient( 8.3, 2 );

    cout << "p1 = " << p1 << endl;

    cout << "p2 = " << testp2 << endl;

    Polynomial testp3 = p1 + testp2;

    cout << "p3 = " << testp3 << endl;

    cout << " " << endl;


    cout << "===================== Testing default constructor ======================== " << endl;
    Polynomial p;
    cout<<"After the default constructor, p is:    "<< p <<endl;
    Polynomial cp (p);
    cout<<"After the copy constructor, pc is:    "<< cp <<endl;

    cout << " " << endl;

    cout << "==================== Testing insert method ============================== " << endl;
       p.changeCoefficient(5,1);
       p.changeCoefficient(20,2);
       p.changeCoefficient(8,11);
       p.changeCoefficient(12,9);
       p.changeCoefficient(13,13);

    cout<<"After adding or inserting terms, p is: "<< p<< endl;

    cout << " " << endl;

    cout << "========================= Testing degree method ========================= " << endl;
    cout << "the highest degree of p is: " << p.degree() << endl;

    cout << " " << endl;

    cout << "==================== Testing the coefficient msthod ======================" << endl;
    cout << "The coefficient of the 1th power term for p is:\t" << p.coefficient(1)<<endl;
    cout << "The coefficient of the 2th power term for p is:\t" << p.coefficient(2)<<endl;
    cout << "The coefficient of the -12th power term for p is: " << p.coefficient(-12)<<endl;
    cout << "The coefficient of the 14th power term for p is: " << p.coefficient(14)<<endl;
    cout << endl;


    cout << "==================== Testing the copy constructor ========================" << endl;
       Polynomial p2(p);
    cout << "After using the copy constructor, p2 is: " << p2 << endl;
    cout << "the degree of p2 is: " << p2.degree() << endl;
    cout << endl;

    cout << "===================== Testing the (==) overloaded operator ===============" << endl;
    cout<<"Checks if p and p2 are equal, " << " p == p2: " << (p==p2) << endl;
    cout << endl;

    cout << "===================== Testing the (=) overloaded operator =================" << endl;
    Polynomial p3 = p;
    cout << "p1 is: " << p << endl;
    cout << "Polynomial p3 = p is: " << p3 << endl;

    cout << endl;

    cout << "Testing the (!=) overloaded operator " << endl;
    cout << "p3 != p2: " << (p3 != p2) << endl << endl;
    cout << endl;

    cout<<"======================= Testing the  + - += -= operators ====================="<<endl;
           // cout << endl;

       Polynomial p4;
       p4.changeCoefficient(10,10);
       p4.changeCoefficient(77,9);
       p4.changeCoefficient(6,12);
       p4.changeCoefficient(32,7);
       cout << "p + p4 =   " << (p + p4) << endl;
       cout << "p - p4 =   " << (p - p4) << endl;
      cout << "p += p4 is: " << (p += p4) << endl;
       p -= p4;
       cout << "p -= p4 is:\t" << (p -= p4) << endl;

       cout << endl;


       Polynomial p5;
       p5.changeCoefficient(4.5,10);
       p5.changeCoefficient(4.32,6);

       Polynomial p6;
       p6.changeCoefficient(4.5,10);
       p6.changeCoefficient(4.41,14);

       Polynomial p7;
       p7.changeCoefficient(1.11,20);
       p7.changeCoefficient(4.71,10);


       cout << "p6 is:\t" << p6 << endl;
       cout << "p7 is:\t" << p7 << endl;
       cout << "p5 is:\t" << p5 << endl;
       cout << "p5 + p6 is:\t" << (p5 + p6) << endl;
       cout << "p5 + p7 is:\t" << (p5 + p7) << endl;
       cout << "p7 + p6 is:\t" << (p7 + p6) << endl;
       cout << "p5 - p7 is:\t" << (p5 - p7) << endl;
       cout << "p7 - p6 is:\t" << (p7 - p6) << endl;
       cout << "p6 - p5 is:\t" << (p5 - p6) << endl;

       cout<<endl;

    cout << "==========================================================================" << endl;

      return 0;

}


// ================ This is the driver provided by Instructor ==================================


//    cout << "================ This is Instrustor's driver output ==========================" << endl;
//  Polynomial p1;
//
//
//
//  p1.changeCoefficient( 1, 1 );
//
//  p1.changeCoefficient( 4, 4 );
//
//  p1.changeCoefficient( 2.2, 2 );
//
//  p1.changeCoefficient( -3.8, 3 );
//
//  cout << "p1 = " << p1 << endl;
//
//
//
//  p1.changeCoefficient( 0, 2 );
//
//  cout << "p1 = " << p1 << endl;
//
//
//
//  Polynomial p2 = p1;
//
//  p2.changeCoefficient( 9.5, 2 );
//
//  cout << "p1 = " << p1 << endl;
//
//  cout << "p2 = " << p2 << endl;
//
//
//
//  Polynomial p3 = p1 + p2;
//
//  cout << "p3 = " << p3 << endl;
//
//}

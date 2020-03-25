//
//  Polynomial.cpp
//  Program1
//
//  Created by Kemba Konteh on 1/9/20. (CSS 343)
//  Copyright © 2020 Kemba Konteh. All rights reserved.
//

#include "Polynomial.hpp"


//---------------------------------- Default Constructor -----------------------------------------
/*
 This is the default constructor that cretaes and initializes the polynomial class object with a
 doubly-linked circular list, with a dummy header, which is pointed to head.
 
 Precondition: No precondition required
 Postcondition: A polynomial object with circular linked list has been created
 */
//------------------------------------------------------------------------------------------------

Polynomial::Polynomial()
{
    // initializes the size to zero
    size = 0;
    
    // creates the dummy header
    head = new Term;
    
    // creates the circular linked list
    head->next = head;
    head->prev = head;
    
    // initializes the coefficient and power of the "Term object" correctly as shown below
    head->power = 0;
    head->coeff = 0.0;
    
}



//=================================== Copy Constructor ==========================================
/*
 This constructs and makes a deep copy of an
 object and initializes it with an object of the same class.
 
 Precondition: The head should not be null and also the list must not be empty
 Postcondition: The left and the right sides of the object must be identical. And each object is            copied as expected.
 */

//===============================================================================================

Polynomial::Polynomial(const Polynomial& p )
{
    // initializes the head
    head = new Term;
    
    // creates a circular linked list
    head->next = head;
    head->prev = head;
    
    // sets and initializes Their values to zero as shown below.
    head->coeff = 0;
    head->power = 0;
    
    // sets size to zero
    size = 0;
    
    // Assignment operator is called and deep copying is complete.
    *this = p;
}



//=================================== Destructor ================================================
/*
 This de-allocates memory, that is, deletes every node and then points head to null pointer
 
 Precondition: Not applicable
 Postcondition: Memory has been de-allocated
 */

//===============================================================================================
Polynomial::~Polynomial()
{
    
    clearList();
    
}

//==================================== clearList =================================================
/*
 Method clears the entire linked list so there is no memory leak. Method is being called in destructor
 */
//================================================================================================
void Polynomial::clearList()
{
    Term* current = head->next;
    while(current != head)
    {
        Term* nodeToDelete = current;
        Term* next = current->next;
        delete nodeToDelete;
        current = next;
    }
    delete head;
    head = nullptr;
}


//===================================== Degree ==================================================
/*
 The Degree method returns the highest (max) degree of the polynomials. Notice that the polynomial is sorted in descending order so the max degree is always going to be at the front or at the top.
 
 Precondition: A polynomial list with head not equal to null exists
 Return: Returns an integer representing the polynomial (returns 0 if polynomial is empty). This is based on the request
 
 */
//===============================================================================================
int Polynomial::degree() const
{
     return head->power;
}

//======================================== Coefficient ==========================================
/* Method returns the coefficient of a given polynomial.
 precondition: A polynomial list with head not equal null exists
 @param power an integer that represents a polynomial degree
 @return returns a double representing the coefficient of the power
 */
//===============================================================================================
double Polynomial::coefficient(const int power) const
{
    // cheks if the list is empty
    if (head == nullptr || size == 0) {
        return 0;
    }
    // traverses the list to find the coefficient
    Term* current = head; // or we can point it to head->next
    while (current->next != head && current->power != power)
    {
        current = current->next;
    }
    
    if (current->power == power) // check this with a tutor
    {
       return current->coeff;
    }
    
    // in this case, we could not find the coefficient we are looking for, so zero is returned
    return 0;
    
}

//====================================== ChangeCoefficient ======================================
/* Method inserts a new polynomial to the list. If the coefficient is not found then it inserts the newCoefficient and power to the polynomials. If the coefficient to be inserted is zero, then we remove the term from the polynomial. The method makes use of both the insert and removes private methods.
 
    @param newCoefficient a double value used as coefficient
    @param power          an integer valueused as the power
    @return a new polynomial is either inserted to an existing polyomial or the
         existing polynomials coefficient is changed.
 */
//===============================================================================================

bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
    Term *temp = head;

     if(temp->next == temp)
     {
       insert(temp,newCoefficient, power);
     }
     else
     {
           while(temp->next != head && temp->power != power)
           {
           temp = temp->next;
           }
         
           if(temp->power == power && temp->coeff == newCoefficient)
           {
               return false;
           }
           else if(temp->power == power && newCoefficient != 0)
           {
               temp->coeff = newCoefficient;
               return true;
           }
             // if coefficient to be inserted is zero we remove the term from the polynomial
           else if(temp->power == power && newCoefficient == 0)
           {
                 remove(temp);
           }
           else
           {
                insert(temp->next,newCoefficient, power);
           }
         
         }
    
         return false;
    
        }



//==================================== + Operator ================================================
/*
 This method takes two non-zero polynomial objects and add their like terms
 Precondition: head != nullptr
 Parameter: p the polynomial object to be added
 Return: the sum of the two terms that have been added. Returns 0 if the parameter is zero
 */
//================================================================================================
Polynomial Polynomial::operator + (const Polynomial& p) const
{
        Polynomial sum;
        Term* current = p.head;
        Term* temp1 = this->head;
        Term* temp2 = sum.head;
    
    while(current->next != p.head || temp1->next != this->head)
    {
        int power1;
        double coeff1;
        int power2;
        double coeff2;
        
         if(current->next == p.head)
         {
               power1 = 0;
               coeff1 = 0;
         
         }else
         {
             power1 = current->power;
             coeff1 = current->coeff;
         }
        
        if(temp1->next == this->head)
        {
              power2 = 0;
              coeff2 = 0;
        }else
        {
            power2 = temp1->power;
            coeff2 = temp1->coeff;
        }
            
        if(power1 > power2)
        {
            Term *newNode = new Term;
            newNode->coeff = coeff1;
            newNode->power = power1;
            newNode->next = temp2->next;
            temp2->next->prev = newNode;
            newNode->prev = temp2;
            temp2->next = newNode;
            temp2 = temp2->next;
        
        
        if(current->next != p.head)
        {
             current = current->next;
                
        }else if(power2 > power1)
        {
              Term* newNode = new Term;
              newNode->coeff = coeff2;
              newNode->power = power2;
              newNode->next = temp2->next;
              temp2->next->prev = newNode;
              newNode->prev = temp2;
              temp2->next = newNode;
              temp2 = temp2->next;
        }
        if(temp1->next != this->head)
        {
              temp1 = temp1->next;
        }
        
        }else{
              Term *newNode= new Term;
              newNode->coeff = coeff1 + coeff1;
              newNode->power = power2;
              newNode->next = temp2->next;
              temp2->next->prev = newNode;
              newNode->prev = temp2;
              temp2->next = newNode;
              temp2 = temp2->next;
            
          if(temp1->next != this->head)
          {
              temp1 = temp1->next;
          }
            
          if(current->next != p.head)
          {
              current = current->next;
          }
              
        }
    }
        
    sum.head = sum.head->next;
            
    return sum;
}



//================================ minus (-) operator ===========================================
/*
 This method takes two non-zero polynomial objects and subtract their like terms
 Precondition: head cannot be nullptr (head != nullptr)
 Parameter: p the polynomial object to be returned
 Return: the difference between the two polynomial objects is returned. Zero is returned if the parameter is zero
 */
//================================================================================================

Polynomial Polynomial:: operator - ( const Polynomial& p) const{
    
    //creates a copy of the parameter object
    Polynomial negativeSum(p);
    
    Term* currentRight = negativeSum.head->next;
    
    while(currentRight != negativeSum.head){
        
        negativeSum.changeCoefficient(currentRight->coeff *(-1), currentRight->power);
        
        currentRight = currentRight->next;
        
    }
    
    return (*this + negativeSum);
}


//===================================== The != operator ==========================================
/*
 This method checks if two polynomial terms are identical or not
 Parameter: p head != nullptr
 Return: a boolean value is returned based on the condition
 */
//================================================================================================

bool Polynomial::operator != (const Polynomial &p)const
{

    return !(*this == p);
}


    
//=================================== The (==) operator ==========================================
/*
 This method checks if two polynomial terms are equal (checks for equality) or not.
 Precondition: head != nullptr
 Parameter: p the object to be copied
 Return: a boolean value is returned based on the condition. true or false
 */
//================================================================================================

bool Polynomial::operator == (const Polynomial &p)const{
    
    Term *current = head ->next;
    Term *currentRight = p.head ->next;
    
    while (current != head && currentRight != head)
    {
        
        if(current ->coeff != currentRight ->coeff || current ->power != currentRight ->power)
        {
            return false;
        }
        current = current ->next;
        currentRight = currentRight ->next;
        
    }
    // could have existed the loop because either list reached its end
    // check each condition explicitly
    if((current == head && currentRight != head) || (current !=head && currentRight == head))
    {
        
        return false;
    }
    
    else{
    
        return true;
    }
    
}

//======================================== The (=) operator ======================================
/*
 This is the assignment operator. The operator assigns the value on the right to the variable on the left
 Precondition: parameter is initialized
 Parameter: p object where term "this" is copied to
 Return: "this" is returned
 */
//================================================================================================
Polynomial& Polynomial::operator = (const Polynomial &p)
{
     
     // checks size first
     if(p.size == 0){
         
         return *this;
     }
     
     // travertse the list and copy everything
     Term *traverse = p.head ->next;
     
     while(traverse != p.head){
         
         // calls method changeCoefficient to add the p
         changeCoefficient(traverse ->coeff,traverse ->power);
         traverse = traverse ->next;
         
     }
     
 
     return *this;
}

//====================================== The (+=) operator =======================================
/*
 Takes two polynomial objects and adds the like terms and then save the result to "this"
 Precondition: head != nullptr
 Parameter: p the polynomial object to be added
 Return:this is returned
 */
//================================================================================================

Polynomial& Polynomial:: operator += ( const Polynomial& p)
{
    
    return (*this=(*this + p));
    
}


//===================================== The (-=) operator ========================================
 /*
  Method takes two polynomial objects and subtract their like terms and save the result to "this" object
 Precondition: head != nullptr
 Parameter: p the polynomial object to be subtracted
 Return: the difference between the polynomial objects is returned. Zero is returned if the parameter is zero
 */
//================================================================================================
Polynomial& Polynomial:: operator-=( const Polynomial& p)
{
    
    return (*this=(*this - p));
}



//================================= Insert =======================================================
/*
  Method inserts new polynomial to the list based on the param specification and returns
 boolean value. The function checks multiple stages before inserting an item to
 the polynomial list. The parameter value to be inserted has a term power that is greater than
 what already existed in the parameter as a leading term. The function checks to ensure
 the final insertion is in the standard form: a_0x^n+a_1x^(n-1)+...+a_(n-1)x+a_n=0
 @param next pointer to the next object
 @param newCoefficient new value to be inserted as a coefficient
 @param power  new integer value to be inserted as power
 @return new item is insereted to the polynomial list
 
 */
//================================================================================================

bool Polynomial::insert (Term* next, const double newCoefficient, const int power)
{
    if(newCoefficient == 0)
    {
        return false;
    }
    Term* temp = next;
    Term* newNode = new Term;
    newNode->power = power;
    newNode->coeff = newCoefficient;

      if(temp->next == temp)
      {
          newNode->prev = newNode;
          newNode->next = newNode;
          head = newNode;
          size++;
          //return true;
       }
  Term* lastNode = temp->prev;

      if(power > temp->power)
      {
          newNode->next = temp;
          temp->prev = newNode;
          newNode->prev = lastNode;
          lastNode->next = newNode;
          head = newNode;
          size++;
      //return true;
      }
      else
      {
          while(temp->next->next != next && power <= temp->power)
          {
              temp = temp->next;
          }
          
     if(temp->power<power && temp != lastNode)
      {
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
              size++;
              //return true;
     }
     else
     {
          newNode->next = temp->next;
          temp->next->prev = newNode;
          newNode->prev = temp;
          temp->next = newNode;
            size++;
            //return true;
     }
          
 }
    
 return false;
    
}

//===================================== Remove ===================================================
/*
 Method removes the polynomial term based on a given list
 Precondition: head != nullptr
 @param pos head pointer to the term object
 @return the removed object passed in as an agument
 */
//================================================================================================
bool Polynomial::remove(Term* pos)
{
  Term *temp=pos;
  Term *lastNode=head->prev;
  if( temp==head && temp->next!=temp)
  {
    head=temp->next;
    temp->next->prev=lastNode;
    lastNode->next=temp->next;

    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
      size--;
  }
  else if(temp->next==temp)
  {
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
      size--;
  }
  else if(temp==head->prev)
  {
    temp->prev->next=head;
    head->prev=temp->prev;
  
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
  size--;
  }
  else
  {
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
      size--;
  }
  return true;
}


//================================= Ostream or (<<) operator =====================================
/*
 Method prints the data of the polynomials in the form cX^power to the console
 @param output used to overload the cout object
 @param p passed by reference to print its data content
 @return an overload print statement
 */
//================================================================================================
ostream& operator<<( ostream &output, const Polynomial& p )
{
    
    Polynomial::Term* temp;
      temp = p.head;
      if(temp->next == p.head)
      {
        cout << "";
        return output;
      }
cout << temp->coeff << "X^" << temp->power;
temp = temp->next;
while(temp->next != p.head)
{
  if(temp->coeff > 0){
   if(temp->power == 1)
   {
   cout << " + " << "X";
    temp = temp->next;
  }else if(temp->power == 0){
    cout << " + " << temp->coeff;
     temp = temp->next;
  }
  else {
    cout << " + " << temp->coeff << "X^" << temp->power;
     temp = temp->next;
  }
}else
{
   if(temp->coeff == -1)
   {
   cout << "-X";
    temp = temp->next;
  }else if(temp->power == 0){
    cout << temp->coeff;
     temp = temp->next;
  }
  else{
  cout << temp->coeff << "X^" << temp->power;
     temp = temp->next;
  }
}
    
}
return output;
}




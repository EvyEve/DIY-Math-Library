#include <iostream>

      //swaps the values of two reference parameters
void swap(int &num1, int &num2)
{
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

      //returns the  gcd of three integer parameters
int Gcd(int num1, int num2, int num3)
{
  int divisor = 0;

  for(int i = 1; i <= num1; i++)
  {
    if(num1 % i == 0 && num2 % i == 0 && num3 % i ==0)
    {
      divisor = i;
    }
  }
  return divisor;
}
      //returns the lcm of three integers parameters
int Lcm(int num1, int num2, int num3)
{
  int least = 0;
  if (num1 > num2 && num1 > num3)
  {
    least = num1;
  }
  else if(num2 > num1 && num2 > num3)
  {
    least = num2;
  }
  else
  {
    least = num3;
  }
  while(!(least % num1==0 && least % num2 == 0 && least % num3 ==0))
  {
    least+=1;
  }
  return least;
}
      //returns the average of the array parameter
double Average(int theArr[], int size)
{
  /*
    Cannot use sizeof to get array size inside of function as it will
    always return 1 as the size, regardless of the actual size of the
    array. 
    Hence it is better to simply include a parameter that will hold
    the size of the array. 
    This method is better suited for when looking for the size
    outside of a function.
    double size = sizeof(double) / sizeof(*theArr);
  */
  double sum = 0;
  for(int i = 0; i < size; i++)
  {
    sum+=theArr[i];
  }
  double average = sum / size;
  return average;
}                       
      //returns the maximum value of the array parameter
int Max(int theArr[], int size)
{
  int max = theArr[0];
  for(int i = 1; i < size; i++)
  {
    if(max < theArr[i])
    {
      max = theArr[i];
    }
  }
  return max;
}
      //returns the minimum value of the array parameter
int Min(int theArr[], int size)
{
  int min = theArr[0];
  for(int i = 1; i < size; i++)
  {
    if(min > theArr[i])
    {
      min = theArr[i];
    }
  }
  return min;
}
      //Reverses the array elements of the array parameter
void Reverse(int theArr[], int size)
{
  int num = 0, temp = 0;
  // for(int i = 0; i < size; i++)
  // {
  //   for(int j = i; j > 0; j--)
  //   {
  //     //swap(theArr[j], theArr[j-1]);
  //     num = theArr[j];
  //     temp = theArr[j-1];
  //     theArr[j] = temp;
  //     theArr[j-1] = num;
  //   }
  // }

  for(int i = size; i > size - i /*  or 0 */ ; i--) 
  {
    //swap(theArr[i-1], theArr[size-i]);
    temp = theArr[i-1];
    theArr[i-1] = theArr[size-i];
    theArr[size-i] = temp;
    //i--;
  
  }

  for(int i = 0; i < size; i++)
  {
    std::cout << theArr[i] << " "; 
  }

}
      //Returns the sum of array of the array parameter
int Sum(int theArr[], int size)
{
  int sum = 0;
  for(int i = 0; i < size; i++)
  {
    sum+=theArr[i];
  }
  return sum;
}
      //Sorts the element of the array parameter
void Sort(int theArr[], int size)
{
  // int num, temp;
  for(int i = 0; i < size; i++)
  {
    for(int j = i; j > 0; j--)
    {
      if(theArr[j] < theArr[j-1])
      {
        swap(theArr[j], theArr[j-1]);
        // num = theArr[j];
        // temp = theArr[j-1];
        // theArr[j] = temp;
        // theArr[j-1] = num;
      }
    }
  }
}
/*  returns the alternating sum of the array parameter.
    e.g. suppose array has {2,5,3,9,15} then the alternating sum is 6
    Because 2 - 5 + 3 - 9 + 15 = 6
*/
int AlternatingSum(int theArr[], int size)
{
  int sum = theArr[0], add = 0, sub = 0;
  for(int i = 1; i < size; i++)
  {
    if(i % 2 == 0)
    {
      sum += theArr[i];
    }
    else
    {
      sum-=theArr[i];
    }
  }
  return sum;
}
/*
  Your function must use a reference parameter
  You are not allowed to use abs( ) from a math library
*/
void AbsoluteValue(int &num)
{
  if(num < 0)
  {
    num = num * -1;
  }
}
/*
  returns the remainder after division of one first integer parameter by the second integer parameter. 
  You are not allowed to use the built-in  modulo % operator or any math library.
*/
int Remainder(int num1, int num2)
{
   int remain = 0;
   // Method 1: Keep subtracting until it's not possible to
  // while(!(num1 - num2 < 0))
  // {
  //   remain = num1 - num2;
  //   num1 = remain;
  // }
  /* Method 2: 
      Quotient remainder theorem: A = b * Q + R
      I Transposed it to: A - (B* Q) = R : to get remainder
  */
  int divide = num1 / num2;
  remain = num1 - (num2 * divide);
  return remain;
}
/*
  returns the long long integer value of  base parameter raised to exponent parameter.
  You are not allowed to use any math library
*/
long long int Pow(int base, int exp)
{
  long long int sum = 1;
  if(exp == 0)
  {
    sum = 1;
    return sum;
  }

  for(int i=1; i <= exp; i++)
  {
    sum *=base;
  }
  return sum;  
}

/* Own custom integer to string function */
std::string IntToString(int num)
{
  std::string number = "\0";
  while(num < 1000000)
  {
    int holdNum = num;
    if(holdNum <= 9)
    {
      number += (num % 10) + 48;
      return number;
    }
    if(holdNum >= 10)
    {
      while(num > 0)
      {
        number.insert(number.begin(), (num%10) + 48);
        num = num /10;
      }
      return number;
    }
  }
  return "0";
}

/*
  returns the last digit of the int parameter.
e.g.  When input is 237  output is 7
        When input is 183  output is 3
*/
int LastDigit(int num)
{
  std::string number = IntToString(num);
  
  // std::string let = "\0";
  // let += number[number.length()];
  char let = number[number.length()-1];
  //converts a char to digit 
  int digit = let - 48; //let - '0'
  return digit;
}

//Method to convert string of numbers into an integer
int StrToInt(std::string num)
{
  int number = 0;
  for(int i = 0; i < num.length(); i++)
  {
    number = number * 10 + (num[i] - 48);
  }
  return number;
}

/* Note: You are not allowed to use the built-in modulo operator, i.e. do not use %. The  only functions that you are allowed to use are the functions from the DIY Math Library.
*/

/*  bool IsDivisibleBy2( ) with integer parameter x
    Returns true if x is divisible by 2; otherwise returns false
*/
bool IsDivisibleBy2(int x)
{
  //A number is divisible by 2 if the last number is even
  int num = LastDigit(x);
  if(Remainder(num, 2) == 0)
  {
    return true;
  }
  return false;
}
/* bool IsDivisibleBy3( ) with integer parameter x 
  Returns true if x is divisible by 3; otherwise returns false
*/
bool IsDivisibleBy3(int x)
{
  //The sum of a number is divisible by 3 
  std::string num = IntToString(x);
  int sum = 0;
  for(int i = 0; i < num.length(); i++)
  {
    //converts a char to a digit
    sum+= num[i] - 48; // '0'
  }
  if(Remainder(sum, 3) == 0)
  {
    return true;
  }
  return false;
}

/* bool IsDivisibleBy4( ) with integer parameter x 
  Returns true if x is divisible by 4; otherwise returns false
*/

bool IsDivisibleBy4(int x)
{
  //The last two digits of a number are divisible by 4
  std::string num1 = IntToString(x);
  int last = 0;

 //Putting last two digits together from string 
  for(int i = 2; i != 0; i--)
  {
    //Is putting number together in each iteration in proper nth place  
    last = last * 10 + (num1[num1.length()-i] - 48);
  } 

  if(Remainder(last, 4) == 0)
  {
    return true;
  }
  return false; 

}

/* bool IsDivisibleBy7( ) with integer parameter x 
  Returns true if x is divisible by 7; otherwise returns false
*/
bool IsDivisibleBy7(int x)
{
  /* Double the last digit and subtract it from a number made by the other digits. 
    The result must be divisible by 7
  */
  int lastDouble = LastDigit(x) * LastDigit(x);
  std::string num = IntToString(x);
  int digit = 0;
  for(int i = 0; i < num.length()-1; i++)
  {
    digit = digit * 10 + (num[i] - 48);
  }
  int remain  = digit - lastDouble;
  if(Remainder(remain, 7) == 0)
  {
    return true;
  }
  return false;
}


int main() {
  //int arr[] = {34, 22, 12, 44};
  int arr[] = { 1, 2, 3, 4, 6, 7, 12};
  std::cout << Max(arr, 5);
  Sort(arr, 4);
  for(int i = 0; i < 4; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout<<"\n" << Sum(arr, 4) << "\n";
  int arr1[] = {2,5,3,9,15};
  std::cout << AlternatingSum(arr1, 5) << "\n";
  std::cout << Pow(2, 0) << "\n";
  std::cout << LastDigit(234) << "\n";
  std::cout << IsDivisibleBy7(905) << "\n";
  return 0;
}
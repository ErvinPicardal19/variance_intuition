#include "../include/stats.h"
#include <iostream>
#include <algorithm>
#include <cmath>

double stats::variance(std::vector<double> arr, double mean, bool bias)
{
   double sum = 0;
   for(int i=0; i<arr.size(); i++)
   {
      sum += ((arr[i] - mean) * (arr[i] - mean));
   }

   if(bias) return sum/arr.size();
   else return sum/(arr.size()-1);
}

bool stats::isFound(double val, std::vector<double> arr)
{
   if(arr.size() > 0) {
      for(int i=0; i<arr.size(); i++)
      {
         if(val == arr[i]) {
            return true;
         }
      }
   }

   return false;
}

double stats::iqr(std::vector<double> arr)
{
   std::vector<double> lower_half;
   std::vector<double> upper_half;
   if(arr.size() % 2)
   {
      for(int i=0; i<std::floor(arr.size()/2); i++)
      {
         lower_half.push_back(arr[i]);
      }
      for(int i=std::floor(arr.size()/2) + 1; i<arr.size(); i++)
      {
         upper_half.push_back(arr[i]);
      }
   }
   else
   {
      for(int i=0; i < (arr.size()/2); i++)
      {
         lower_half.push_back(arr[i]);
      }
      for(int i=(arr.size()/2); i<arr.size(); i++)
      {
         upper_half.push_back(arr[i]);
      }
   }

   return median(upper_half) - median(lower_half);

}

std::vector<double> stats::set(std::vector<double> arr)
{
   std::vector<double> set;

   for(int i=0; i<arr.size(); i++)
   {
      if(!stats::isFound(arr[i], set) || i==0)
      {
         set.push_back(arr[i]);
      }
   }

   return set;
}

double stats::mode(std::vector<double> arr)
{
   if(arr.size() <= 0) return 0;

   double curr_mode;
   std::vector<double> unique = stats::set(arr);
   int prev_counter=0;

   for(double x : unique)
   {
      int counter = 0;
      for(int i=0; i<arr.size(); i++)
      {
         if(x == arr[i]) {
            counter++;
         }
      }

      if(counter >= prev_counter) 
      {
         curr_mode = x;
         prev_counter = counter;
      }
   }

   return curr_mode;
}

double stats::median(std::vector<double> arr)
{

   if(arr.size() % 2)
   {
      return arr[std::floor(arr.size()/2)];
   }

   return (arr[(arr.size()/2) - 1] + arr[(arr.size()/2)]) / 2 ;
}

double stats::mean(std::vector<double> arr)
{
   double sum = 0;
   for(double x : arr)
   {
      sum += x;
   }
   return sum/arr.size();
}

void stats::sort_array(std::vector<double> &arr)
{
   std::sort(std::begin(arr), std::end(arr));
}

void stats::sort_array(double arr[], size_t size)
{
   std::sort(arr, &arr[size]);
}

void stats::display_array(std::vector<double> arr)
{
   for(double x : arr)
   {
      std::cout << x << "\t";
   }
   std::cout << std::endl;
}

void stats::display_array(const double arr[], size_t size)
{
   for(int i=0; i<size; i++)
   {
      std::cout << arr[i] << "\t";
   }
   std::cout << std::endl;
}
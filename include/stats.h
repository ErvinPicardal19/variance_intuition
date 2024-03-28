#ifndef STATS_UTILS_H
#define STATS_UTILS_H

#include <vector>
#include <chrono>

class Timer
{
   std::chrono::high_resolution_clock::time_point start_duration;
   std::chrono::high_resolution_clock::time_point end_duration;

   public:
      void start()
      {
         this->start_duration = std::chrono::high_resolution_clock::now();
      }
      void end()
      {
         this->end_duration = std::chrono::high_resolution_clock::now();
      }
      double get_exec_time()
      {
         std::chrono::duration<double, std::milli> duration = this->end_duration - this->start_duration;
         return duration.count();
      }
};

namespace stats
{
   std::vector<double> set(std::vector<double> arr);
   void sort_array(std::vector<double> &arr);
   void sort_array(double arr[], size_t size);
   void display_array(std::vector<double> arr);
   void display_array(const double arr[], size_t size);
   double mean(std::vector<double> arr);
   double median(std::vector<double> arr);
   double mode(std::vector<double> arr);
   bool isFound(double val, std::vector<double> arr);
   double iqr(std::vector<double> arr);
   double variance(std::vector<double> arr, double mean, bool bias = false);
}


#endif 
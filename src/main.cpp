#include <iostream>
#include <stdio.h>
#include <thread>
#include <cmath>
#include <random>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include "../include/gnuplot.h"
#include "../include/stats.h"

inline bool isFileExist (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

std::vector<double> random_distribution(int size, double max_y)
{
   std::vector<double> new_arr;
   srand(time(nullptr));
   for(int i=0; i<size; i++)
   {
      double new_data = std::floor(((double)std::rand() / RAND_MAX) * max_y);

      new_arr.push_back(new_data);
   }

   return new_arr;
}

std::vector<double> get_sample(std::vector<double> population, int sample_size)
{
   std::vector<double> samples;

   if(!population.size()) return samples;
   
   for(int i=0; i<sample_size; i++)
   {
      int index = std::floor(((double)std::rand() / RAND_MAX) * population.size());
      samples.push_back(population.at(index));
   }
   
   return samples;
}

void write_file(std::vector<int> steps, std::vector<double> y, std::string file_name="")
{
   if(file_name=="") file_name="data.dat";
   std::string directory = "../data/";
   std::ofstream output(directory+file_name);
   
   for(int i=0; i<steps.size(); i++)
   {
      output << "\t" << steps[i] << "\t" << y[i] << std::endl;
   }

   output.close();
}

void write_file(int col1, double col2, bool append = true, std::string file_name="")
{
   if(file_name=="") file_name="data.dat";
   std::string directory = "../data/";
   
   std::ofstream output;
   if(append)
   {
      output.open(directory+file_name, std::ios_base::app);
   }
   else
   {
      output.open(directory+file_name);
   }
   
   output << "\t" << col1 << "\t" << col2 << std::endl;

   output.close();
}

void start_plotting()
{
   GnuplotPipe gp;
   std::string prefix_cmd = "load \"../scripts/";

   std::string loadStyles = prefix_cmd + "loadStyles.gp" + "\"";
   std::string gnuplot_script = prefix_cmd + "livePlot.gp" + "\"";

   gp.sendLine(loadStyles);
   gp.sendLine(gnuplot_script);
}

void start_program()
{
   if(isFileExist("../data/unbiased_data.dat") || isFileExist("../data/biased_data.dat"))
   {
      remove("../data/unbiased_data.dat");
      remove("../data/biased_data.dat");
   }
   std::vector<double> population = random_distribution(201, 200);

   double true_mean = stats::mean(population);
   double true_variance = stats::variance(population, true_mean, true);

   
   std::vector<int> sample_size_steps;
   std::vector<double> unbiased_variances;
   std::vector<double> biased_variances;
   std::vector<double> unbiased_variances_means;
   std::vector<double> biased_variances_means;

   int i = 0;
   int samples = 300;
   int sample_size = 5;
   
   write_file(samples, true_variance, false, "population_data.dat");

   while(i < samples)
   {
      std::vector<double> sample = get_sample(population, sample_size);
      double mean_ = stats::mean(sample);


      biased_variances.push_back(stats::variance(sample, mean_, true));
      unbiased_variances.push_back(stats::variance(sample, mean_, false));

      write_file(i * sample_size, stats::mean(unbiased_variances), true, "unbiased_data.dat");
      write_file(i * sample_size, stats::mean(biased_variances), true, "biased_data.dat");
      i++;


      std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }


   std::cout << "Population Mean: " << true_mean << std::endl;
   std::cout << "Population Variance: " << true_variance << std::endl;
   std::cout << "\n";
   std::cout << "Sample Variance(n): " << stats::mean(biased_variances) << std::endl;
   std::cout << "Sample Var/Pop Var(n) %: " << stats::mean(biased_variances)/true_variance << std::endl;
   std::cout << "\n";
   std::cout << "Sample Variance(n-1): " << stats::mean(unbiased_variances) << std::endl;
   std::cout << "Sample Var/Pop Var(n-1) %: " << stats::mean(unbiased_variances)/true_variance << std::endl;
}

int main(int argc, char** argv)
{

   std::thread t1(start_program);
   std::thread t2(start_plotting);


   t1.join();
   t2.join();

   std::cout << "\n";
   std::cout << "Finished Plotting." << std::endl;
   
   return 0;
}

# load "loadstyles.gp"
# START PLOTTING BELOW -----------

# plot sin(x) ls 1 title "Theory", "./dataerrors.dat" using 1:2:($3/1000) ls 2 with errorbars title "Measurement"


# plot "biased_data.dat" ls 2, "unbiased_data.dat" ls 3

# print(STATS_records)

true_variance=system("awk '{print $2}' ../data/population_data.dat")
num_samples=system("awk '{print $1}' ../data/population_data.dat")

num_samples = num_samples+0
f(x) = true_variance+0

set ytics ("0" 0, "True variance" true_variance)

while(1) {
   pause 0.200
   stats "../data/unbiased_data.dat" nooutput
   
   if(STATS_records) {
      plot "../data/biased_data.dat" ls 2 title "n", "../data/unbiased_data.dat" ls 3 title "n-1", f(x) notitle lw 2
   }

   if(STATS_records >= num_samples) {
      break
   }
}
# Uncomment to export image
# set term pngcairo
# set output "variance_intuition.png"
# replot
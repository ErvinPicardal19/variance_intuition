# window and grid
# set terminal qt size 1300,600
set grid
set border 3
set border lw 2

# x/y axis
set yrange [0:8000]
set autoscale x
set tics nomirror
# set xtics 240
# set ytics 250
unset tics
# set xtics scale 1.5

set xlabel "# of samples" font ",16"
set ylabel "Cumulative Variance" font ",16"
# set ylabel offset 0

# Legends
set key box
set key width 1
set key font ",14"
# set key at -0.0, -1.7

# set line styles
set style line 1 lc rgb "#8b0000" lw 2
set style line 2 lc "#8b0000" pt 7 ps 0.9
set style line 3 lc 27 pt 7 ps 0.9
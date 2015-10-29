make

for f in {1..100}
do
	for r in {1..3}
	do
		./matmul $f mat.dat >> repitition.txt
	done
done
./graph repitition.txt 3 100 result.txt
echo "set terminal 'png'" >> plot.txt
echo "set output 'graph.png'" >> plot.txt
echo "plot 'result.txt' with linespoints" >> plot.txt
gnuplot < plot.txt
rm plot.txt
rm repitition.txt
rm result.txt
echo "done with graph plotting."

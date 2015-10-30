make
./data 100 1000
for f in {1..600}
do
	for r in {1..1}
	do
		./matmul $f mat.dat >> repitition.txt
	done
	echo "$f"
done
./graph repitition.txt 1 600 result.txt
echo "set terminal 'png'" >> plot.txt
echo "set output 'graph2.png'" >> plot.txt
echo "plot 'result.txt' with linespoints" >> plot.txt
gnuplot < plot.txt
rm plot.txt
rm repitition.txt
rm result.txt
rm *.dat
echo "done with graph plotting."
make clean

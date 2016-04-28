
#rm main.cu.o
#rm median 
#/usr/local/cuda-6.0/bin/nvcc -ccbin g++ -I/usr/local/cuda/samples/common/inc  -m64     -o main.cu.o -c main.cu
#/usr/local/cuda-6.0/bin/nvcc -ccbin g++ -m64 -o median main.cu.o  -lcublas -lcusparse

rm cgs.cu.o
rm cgs_lab 
/usr/local/cuda-6.0/bin/nvcc -ccbin g++ -I/usr/local/cuda/samples/common/inc  -m64     -o median.cu.o -c median.cu
/usr/local/cuda-6.0/bin/nvcc -ccbin g++ -m64 -o median median.cu.o  -lcublas -lcusparse




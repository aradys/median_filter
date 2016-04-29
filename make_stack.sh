rm stack.cu.o
rm stack 
/usr/local/cuda-6.0/bin/nvcc -ccbin g++ -I/usr/local/cuda/samples/common/inc  -m64     -o stack.cu.o -c stack.cu
/usr/local/cuda-6.0/bin/nvcc -ccbin g++ -m64 -o stack stack.cu.o

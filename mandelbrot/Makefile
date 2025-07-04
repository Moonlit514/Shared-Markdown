CC        = gcc
CFLAGS    = -std=c11 -Wall -Wextra -Wpedantic -O3 -Isrc/include -fopenmp
LDFLAGS   = -lm

FORMAT    ?= bmp

.PHONY: all run doc clean help

all: build build/mandelbrot

build:
	mkdir -p build

build/mandelbrot: src/mandelbrot.c src/test.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

run: build/mandelbrot
	@$< $(FORMAT)

clean:
	rm -rf build
	rm -f mandelbrot.bmp mandelbrot.png mandelbrot.jpg

help:
	@echo "make				# 编译项目"
	@echo "make run			# 生成bmp图像(默认)"
	@echo "make run FORMAT=png		# 生成png图像"
	@echo "make run FORMAT=jpg		# 生成jpeg图像"
	@echo "make clean			# 清理所有生成文件"
obj-m += pir_driver.o

KDIR := /work/achroimx6q/achroimx_kernel

all:
	make -C $(KDIR) SUBDIRS=$(PWD) modules

app:
	arm-none-linux-gnueabi-gcc pir_app.c -o pir_test -static
install:
	cp -a *.ko /nfsroot/
	cp -a *test /nfsroot/
clean:
	rm -rf *.ko
	rm -rf *.mod*
	rm -rf .*.cmd
	rm -rf *.o 
	rm -rf Module.symvers
	rm -rf modules.order
	rm -rf pir_test

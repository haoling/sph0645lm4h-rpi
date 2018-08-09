ifndef KERNEL
	KERNEL=$(shell uname -r)
endif

obj-m := sph0645lm4h.o

all:
	make -C /lib/modules/${KERNEL}/build M=$(PWD) modules

clean:
	make -C /lib/modules/${KERNEL}/build M=$(PWD) clean

install:
	sudo cp sph0645lm4h.ko /lib/modules/${KERNEL}
	sudo depmod -a

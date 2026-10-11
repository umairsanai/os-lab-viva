build-dirs:
	mkdir -p build build/obj build/lib/finance build/lib/logger build/bin

lib-finance: build-dirs libs/finance/finance.c libs/finance/finance.h
	gcc -c -Wall libs/finance/finance.c -o build/obj/finance.o
	ar crs build/lib/finance/libfinance.a build/obj/finance.o

lib-logger: build-dirs libs/logger/logger.c libs/logger/logger.h
	gcc -o build/obj/logger.o -fPIC -c libs/logger/logger.c -Ilibs/logger
	gcc -shared build/obj/logger.o -o build/lib/logger/liblogger.so

libs: lib-finance lib-logger

src: build-dirs libs src/account.c src/report.c src/transaction.c src/validation.c
	gcc -o build/obj/account.o -c -Wall src/account.c -Iinclude -Ilibs/logger
	gcc -o build/obj/report.o -c -Wall src/report.c -Iinclude -Ilibs/finance -Ilibs/logger
	gcc -o build/obj/transaction.o -c -Wall src/transaction.c -Iinclude -Ilibs/finance -Ilibs/logger
	gcc -o build/obj/validation.o -c -Wall src/validation.c -Iinclude 

all: src main.c
	gcc -o build/obj/main.o -c -Wall main.c -Iinclude -Ilibs/logger -Ilibs/finance
	gcc -o build/bin/main build/obj/account.o build/obj/main.o build/obj/report.o build/obj/transaction.o build/obj/validation.o -Lbuild/lib/finance -Lbuild/lib/logger -lfinance -llogger -lm -lpthread

run: build/bin/main
	clear
	LD_LIBRARY_PATH=build/lib/finance LD_LIBRARY_PATH=build/lib/logger ./build/bin/main

clean:
	rm -rf build
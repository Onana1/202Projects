CXX = g++
CXXFLAGS = -Wall

proj4: Mail.o Carrier.o Ups.o FedEx.o Package.o Letter.o MailHouse.o driver.cpp
	$(CXX) $(CXXFLAGS) Mail.o Carrier.o Ups.o FedEx.o Package.o Letter.o MailHouse.o driver.cpp -o proj4

Mail.o: Mail.cpp Mail.h
	$(CXX) $(CXXFLAGS) -c Mail.cpp

Carrier.o: Carrier.cpp Carrier.h Mail.o
	$(CXX) $(CXXFLAGS) -c Carrier.cpp

FedEx.o: FedEx.cpp FedEx.h Carrier.o
	$(CXX) $(CXXFLAGS) -c FedEx.cpp

Ups.o: Ups.cpp Ups.h Carrier.o
	$(CXX) $(CXXFLAGS) -c Ups.cpp

Letter.o: Letter.cpp Letter.h Mail.o
	$(CXX) $(CXXFLAGS) -c Letter.cpp

Package.o: Package.cpp Package.h Mail.o
	$(CXX) $(CXXFLAGS) -c Package.cpp

MailHouse.o: MailHouse.cpp MailHouse.h Carrier.o Package.o Letter.o Ups.o FedEx.o 
	$(CXX) $(CXXFLAGS) -c MailHouse.cpp 

clean:
	rm *~

run:
	./proj4

run1:
	./proj4 proj4_t1.txt

val1:
	valgrind ./proj4 proj4_t1.txt

run2:
	./proj4 proj4_t2.txt

val2:
	valgrind ./proj4_t2.txt

run3:
	./proj4 proj4_t3.txt

val3:
	valgrind ./proj4 proj4_t3.txt

run4:
	./proj4 proj4_t4.txt

val4:
	valgrind ./proj4 proj4_t4.txt

#include <iostream>

#define BASEI 320000000L

//#include <swbuf.h>
//typedef sword::SWBuf StringType;

#include <string>
typedef std::string StringType;

using std::cout;
using std::cerr;


void appendChTest() {
	cerr << "\nSTART: append ch test -------\n";
	cerr.flush();
	StringType s;
	for (unsigned long i = 0; i < BASEI+14; i++) {
		s += (char) (i%125)+1;
	}
	cerr << "\nEND: append ch test -------\n";
	cerr.flush();
}


void appendStringTest() {
	cerr << "\nSTART: append string test -------\n";
	cerr.flush();
	StringType s;
	unsigned long iterations = BASEI/2L;
	for (unsigned long i = 0; i < iterations; i++) {
		s.append("this is a test", 3);
		if (!(i%3))s.append("test");
	}
	cerr << "\nEND: append string test -------\n";
	cerr.flush();
}


void subscriptTest() {
	cerr << "\nSTART: subscript access test -------\n";
	cerr.flush();
	StringType s;
	for (int j = 0; j < 100; j++) {
		s += "0123456789";
	}
	for (int j = 0; j < BASEI/500; j++) {
		for (unsigned long i = s.length()-1; i; i--) {
			s[i] = (char) (i%40)+65;
		}
	}
	cerr << "\nEND: subscript access test -------\n";
	cerr.flush();
}

void ctorAssignTest() {
	cerr << "\nSTART: constructor and assign test -------\n";
	cerr.flush();
	StringType s;
	for (int j = 0; j < 100; j++) {
		s += "0123456789";
	}
	for (unsigned long i = (BASEI/4); i; i--) {
		StringType s2;
		s2 = s;
		s2.c_str();	// keep us from being optimized out
	}
	cerr << "\nEND: constructor and assign test -------\n";
	cerr.flush();
}

void compareTest() {
	cerr << "\nSTART: compare test -------\n";
	cerr.flush();
	StringType first =  "firsttestAfirst";
	StringType second = "firsttestBsecond";
	for (unsigned long i = BASEI/2; i; i--) {
		if (first != second)
			if (first <= second)
				if (first > second);
				else if (!(BASEI%10000)) first[0] = 'f';	// keep us from being optimized out
	}
	cerr << "\nEND: compare test -------\n";
	cerr.flush();
}


void insertStringTest() {
	cerr << "\nSTART: insert string test -------\n";
	cerr.flush();
	StringType s;
	StringType sub = "text ->this part should not appear :)";
	for (int j = 0; j < BASEI/10000; j++) {
		s = "Start    end";
		for (int i = 0; i < 1000; i++) {
			s.insert(s.length()/2, sub, 0, 5);
		}
	}
	cerr << "\nEND: insert string test -------\n";
	cerr.flush();
}

int main(int argc, char **argv) {
	StringType x;
	cout << "x should be (): (" << x << ")\n";
	cout << "size should be 0: " << x.size() << "\n";
	x = "hello";
	cout << "x should be (hello): (" << x << ")\n";
	x += " world";
	cout << "x should be (hello world): (" << x << ")\n";
	cout << "size should be 11: " << x.size() << "\n";
	cout << "x[7] should be 'o': '" << x[7] << "'\n";
	x[7] = 'u';
	cout << "x[7] should be 'u': '" << x[7] << "'\n";
	cout << "x should be (hello wurld): (" << x << ")\n";
	StringType y = x + " " + x;
	cout << "should be (hello wurld hello wurld): (" << y << ")\n";
//	y.appendFormatted(" from %d %s running %02.05f miles", 4, "dogs", 1.9f);
//	cout << "should be (hello wurld hello wurld from 4 dogs running 1.90000 miles): (" << y << ")\n";
//	y += '!';
//	cout << "should be (hello wurld hello wurld from 4 dogs running 1.90000 miles!): (" << y << ")\n";
//	y.append(y.c_str(),5);
//	cout << "should be (hello wurld hello wurld from 4 dogs running 1.90000 miles!hello): (" << y << ")\n";

	appendChTest();
	appendStringTest();
	subscriptTest();
	ctorAssignTest();
 	compareTest();
	insertStringTest();
}


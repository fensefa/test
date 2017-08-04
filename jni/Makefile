all: Test.class libtest.so

Test.class: Test.java
	javac Test.java

Test.h: Test.class
	javah -jni Test

libtest.so: Test.h Test.cpp
	g++ -shared -fPIC -I/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.141-1.b16.el7_3.x86_64/include -I/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.141-1.b16.el7_3.x86_64/include/linux/ Test.cpp -o libtest.so

java_run: Test.class libtest.so
	java -Djava.library.path=. Test

scala_run: Test.class libtest.so Test.scala
	scala -Djava.library.path=. Test.scala

clean:
	rm -f Test.h Test.class libtest.so

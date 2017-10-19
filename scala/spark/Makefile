TARGET := target/scala-2.10/simple-project_2.10-1.0.jar

all : $(TARGET)
	sbt package

run : $(TARGET)
	spark-submit --class Feature --master local[4] target/scala-2.10/simple-project_2.10-1.0.jar

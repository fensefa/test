import org.apache.spark._
import org.apache.spark.streaming._

object Feature {
    def main(args : Array[String]) : Unit = {
        val conf = new SparkConf()
        val sc = new SparkContext(conf)
        val lines = sc.textFile("3.txt", 1)
        val out1 = lines.map(line => line.split('\t'))
        val out2 = out1.map(x => (x(0), (x(1).toFloat, x(1)::Nil)))
        val out3 = out2.reduceByKey((x, y) => (x._1 + y._1, x._2 ::: y._2))
        val out4 = out3.map(x => (x._1, x._2._1, x._2._2))
        val out5 = out4.sortBy(x => x._2)
        val out6 = out5.map(x => (x._1, x._2, x._3.mkString("\t")))
        val out7 = out6.map(_.productIterator.mkString("\t"))
        out5.saveAsTextFile("5.out")
        out7.saveAsTextFile("7.out")
    }
}

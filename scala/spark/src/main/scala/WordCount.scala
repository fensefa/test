import org.apache.spark._
import org.apache.spark.streaming._

object WordCount {
    val conf = new SparkConf()
    val sc = new SparkContext(conf)
    def main(args : Array[String]) : Unit = {
        println("WordCount")
        new Array[Int](8)
        /*
        var y1 = sc.parallelize(List(1,2,3,4,5,6,7,8)).aggregate(0,0)(seq,comb)
        println(y1.toString())
        */
        var y2 = sc.parallelize(List((1,3),(2,4),(3,9))).aggregateByKey(0)(seq3,comb3)
        println(y2.toString())
    }
    def seq(a:(Int, Int), b:Int) = {
        var c = (a._1 + b, a._2 + 1)
        println(s"$a,$b,$c")
        c
    }
    def comb(a:(Int, Int), b:(Int,Int)) = {
        var c = (a._1 + b._1, a._2 + b._2)
        println(s"$a,$b,$c")
        c
    }
    def seq2(a:(Int, Int), b:Int) = {
        (1,3)
    }
    def comb2(a:(Int, Int), b:(Int,Int)) = {
        var c = (a._1 + b._1, a._2 + b._2)
        println(s"$a,$b,$c")
        c
    }
    def seq3(a:Int, b:Int) : Int ={
        println("seq: " + a + "\t " + b)
            a + b
    }
    def comb3(a:Int, b:Int) : Int ={
        println("comb: " + a + "\t " + b)
            a + b
    }
}

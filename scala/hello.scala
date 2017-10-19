import scala.collection.mutable.ArrayBuffer
import java.util.Random

object HelloWorld {
    def main(args: Array[String]): Unit = {
        println("Hello, world!")
        println(func(3))
        val x = new ArrayBuffer[String]()
        x += "fdas"
        x += "abc"
        val y = x.flatMap(x => x.split("a"))
        println(y.mkString("_"))
        val z = new Random().nextInt(20)
        println(z)
    }
    def func(args: Int): Int = {
        args + 1
    }
    def func(args: Array[Int]): Array[Int] = {
        args
    }
}

trait traitTest {
    var x : Int = 3
    def fun(y : Int) : Int = {
        y + 3
    }
}

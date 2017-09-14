object Solution {

    def main(args: Array[String]) {
        var data : Array[(Int, Int)] = Array()
        var n = readInt()

        for( i <- 1 to n ){
            var x = readLine().split(" ").map( x => x.toInt )
            data = data :+ ( x(0), x(1) )
        }
        data = data :+ data( 0 )

        var sum = 0
        for( i <- 0 until n ){
            val first = data( i )
            val second = data( i + 1 )

            sum = sum + first._1 * second._2 - first._2 * second._1
        }
        println( sum.abs/2.0 )
    }
}

object Solution {

    def op( sum : Double, i : ( (Int,Int), (Int, Int ) ) ) = {
        sum + math.hypot(( i._1._1 - i._2._1),( i._1._2 - i._2._2) )
    }

    def main(args: Array[String]) {
        var n = readInt()
        var input = List[(Int, Int)]()

        for( i <- 1 to n ){
            var pair = readLine().split(" ").map( x => x.toInt )
            input = ( pair( 0 ), pair( 1 ) )::input
        }

        println(input.zip( input.tail :+ input.head ).foldLeft(0.0){ op })
    }
    
}

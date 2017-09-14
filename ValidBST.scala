object Solution {
    sealed trait AbstractNode{
        def insert( v : Int ) : AbstractNode
    }

    case class Node(right: AbstractNode, left: AbstractNode, value: Int) extends AbstractNode{
        def insert( v : Int ): AbstractNode = {
            if( v <= value ){
                Node(right.insert( v ), left, value )
            } else {
                Node(right, left.insert( v ), value )
            }
        }
    }

    case object None extends AbstractNode{
        def insert( v : Int ): AbstractNode ={
            Node( None, None, v )
        }
    }

    def preorder( root : AbstractNode ) : List[Int] =
        root match {
            case None => Nil
            case Node( right, left, value ) => value :: preorder( right ) ::: preorder( left )
        }

    def main(args: Array[String]) {
        val t = readInt()

        for( _ <- 1 to t ){
            val n = readInt()
            val l : List[Int] = readLine().split(" ").toList.map( x => x.toInt )
            var bst : AbstractNode = None

            for( x <- l ) {
                bst = bst.insert( x )
            }

            if( preorder( bst ).equals( l ) ){
                println("YES")
            }
            else {
                println("NO")
            }
        }

    }
}

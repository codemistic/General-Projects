package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class memorytest extends FreeSpec with ChiselScalatestTester{
    "memory testing" in {
        test(new memory()){c=>
        c.io.addr.poke(4.U)
        c.io.data.poke(4.U)
        c.io.r_enable.poke(1.B)
        c.io.w_enable.poke(0.B)
        c.io.output.expect(0.U)
        }
    }
}        
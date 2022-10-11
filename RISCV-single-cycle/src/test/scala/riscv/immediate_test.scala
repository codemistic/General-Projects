package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class immediatetest extends FreeSpec with ChiselScalatestTester{
    "immm testing" in {
        test(new immediate()){c=>
        c.io.instr.poke("b0000000000000001100011".U)
        c.io.pc.poke(4.U)
        c.clock.step(1)
        }
    }
}        
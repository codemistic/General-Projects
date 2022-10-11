package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class toptest extends FreeSpec with ChiselScalatestTester{
    "top testing" in {
        test(new Top()){c=>
        c.clock.step(30)
        }
    }
}        
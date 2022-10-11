package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class imemtest extends FreeSpec with ChiselScalatestTester{
    "immm testing" in {
        test(new imem()){c=>
        c.io.address.poke(2.U)
        c.clock.step(1)
        //c.io.readdata.expect(2.U)
        }
    }
}        
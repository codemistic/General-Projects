package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class jaltest extends FreeSpec with ChiselScalatestTester{
    "immm testing" in {
        test(new JALR()){c=>
        c.io.addr.poke(14.U)
        c.io.pc.poke(10.U)
        c.clock.step(1)
        c.io.out.expect(24.U)
        }
    }
}        
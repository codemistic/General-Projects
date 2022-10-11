package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class pctest extends FreeSpec with ChiselScalatestTester{
    "pc testing" in {
        test(new pc()){c=>
        c.io.addr.poke(4.U)
        c.io.pc_out.expect(0.U)
        c.clock.step(4)
        c.io.pc_out4.expect(8.U)
        }
    }
}       
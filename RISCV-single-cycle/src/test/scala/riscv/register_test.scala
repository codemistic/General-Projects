package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class regtest extends FreeSpec with ChiselScalatestTester{
    "reg testing" in {
        test(new register()){c=>
        c.io.regwrite.poke(1.U)
        c.io.writereg.poke(1.U)
        c.io.writedata.poke(0.S)
        c.io.rs1.poke(1.U)
        c.io.rs2.poke(3.U)
        c.io.rd1.expect(0.S)
        c.io.rd2.expect(0.S)
        c.clock.step(4)
        }
    }
}       
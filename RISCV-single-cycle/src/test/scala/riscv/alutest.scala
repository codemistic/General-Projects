package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class alutest extends FreeSpec with ChiselScalatestTester{
    "immm testing" in {
        test(new ALU()){c=>
        c.io.in_A.poke(5.U)
        c.io.in_B.poke(5.U)
        c.io.alu_Op.poke("b00000".U)
        c.clock.step(1)
        c.io.out.expect(10.U)
        //c.io.branch.expect()
        
        }
    }
}        
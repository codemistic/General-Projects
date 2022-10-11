package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class bcontrol extends FreeSpec with ChiselScalatestTester{
    "branch TESTING" in {
        test(new branchControl()){c=>
            c.io.aluop.poke("b10001".U)
            c.io.branch.poke(1.B)
            c.io.arg_x.poke(4.S)
            c.io.arg_y.poke(5.S)
            c.clock.step(20)
            c.io.br_taken.expect(1.B)
        }

    }


}

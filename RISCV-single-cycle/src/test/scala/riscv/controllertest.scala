package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class controltest extends FreeSpec with ChiselScalatestTester{
    "control testing" in {
        test(new controller()){c=>
            c.io.in.poke("b0010011".U)
            c.io.memwrite.expect(0.B)
            c.io.branch.expect(0.B)
            c.io.memread.expect(0.B)
            c.io.regwrite.expect(1.U)
            c.io.memtoreg.expect(0.B)
            c.io.aluop.expect(1.U)
            c.io.opA.expect(0.U)
            c.io.opB.expect(1.U)
            c.io.extendsel.expect(0.U)
            c.io.nextpcsel.expect(0.U)
        }

    }


}

package riscv
import chisel3._
import org.scalatest._
import chiseltest._
class alucontroltest extends FreeSpec with ChiselScalatestTester{
    "immm testing" in {
        test(new alucontrol()){c=>
        c.io.alu.poke("b011".U)
        c.io.f3.poke("b000".U)
        c.io.f7.poke(0.U)
        c.clock.step(1)
        c.io.alucontrolout.expect("b11111".U)
        }
    }
}        
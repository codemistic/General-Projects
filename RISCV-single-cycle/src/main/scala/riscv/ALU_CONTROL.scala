package riscv
import chisel3._
import chisel3.util._
class alucontrolIO extends Bundle{
    val alu = Input ( UInt (3.W ) )
    val f3 = Input(UInt(3.W))
    val f7= Input(UInt(1.W))
    val alucontrolout = Output(UInt(5.W))
}
class alucontrol extends Module {
    val io = IO (new alucontrolIO())
    io.alucontrolout:=0.U
    when(io.alu==="b001".U){    //i type
        io.alucontrolout:=Cat(io.alu(2,1),io.f3)
    }.elsewhen(io.alu==="b000".U){  //R type
        io.alucontrolout:=Cat(io.alu(1,1),io.f7,io.f3)
    }.elsewhen(io.alu==="b010".U){  //SB type
        io.alucontrolout:=Cat("b10".U,io.f3)
    }.elsewhen(io.alu==="b000".U){  //SW type
        io.alucontrolout:=Fill(5,"b0".U)
    }.elsewhen(io.alu==="b011".U){     //JAL/JALR type
        io.alucontrolout:=Fill(5,"b1".U)
    }.elsewhen(io.alu==="b110".U){      // u type
        io.alucontrolout:=Fill(5,"b0".U)
    }}

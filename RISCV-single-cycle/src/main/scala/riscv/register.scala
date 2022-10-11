package riscv
import chisel3._
import chisel3.util._
class register extends Module{
    val io= IO(new Bundle{
        val regwrite = Input ( UInt (1.W) )
        val writereg = Input(UInt(5.W))
        val rs1 = Input ( UInt (5. W ) )
        val rs2 =Input(UInt(5.W))
        val writedata =Input(SInt(32.W))
        val rd1 =Output(SInt(32.W))
        val rd2=Output(SInt(32.W))
    })
    val register = RegInit(VecInit(Seq.fill(32)(0.S(32.W))))
    register(0):=(0.S)
    io.rd1 :=register(io.rs1)
    io.rd2 :=register(io.rs2)
    when(io.regwrite === 1.U){
        when(io.writereg === "b00000".U){
            register(io.writereg) := 0.S
        }.otherwise{
            register(io.writereg) := io.writedata
        }
    }
}


package riscv
import chisel3._
import chisel3.util._
class JALRIO extends Bundle{
    val addr = Input ( UInt (32.W ) )
    val pc = Input(UInt(32.W))
    val out = Output(UInt(32.W))
}
class JALR extends Module {
    val io = IO (new JALRIO())
    io.out := (io.pc + io.addr) & 0xFFFFFFFL.U

    

}

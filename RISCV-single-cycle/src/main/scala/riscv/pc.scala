package riscv
import chisel3._
import chisel3.util._
class pcIO extends Bundle{
    val addr = Input ( UInt (32.W ) )
    val pc_out = Output(UInt(32.W))
    val pc_out4 =Output(UInt(32.W))
}
class pc extends Module {
    val io = IO (new pcIO())
    val reg = RegInit(0.U(4.W))
    reg:=io.addr
    io.pc_out:=reg
    io.pc_out4:=reg + 4.U
    

}

package riscv
import chisel3._
import chisel3.util._

class memoryIO extends Bundle{
    val w_enable = Input ( Bool () )
    val r_enable = Input(Bool())
    val addr = Input ( UInt (8. W ) )
    val data =Input(UInt(32.W))
    val output =Output(UInt(32.W))
}
class memory extends Module {
    val io = IO (new memoryIO())
    val mem = Mem(32, UInt ( 32 . W ) )
    when (io.w_enable === 1.B){
        mem.write(io.addr,io.data)
        io.output:=0.U
    }.elsewhen(io.r_enable === 1.B){
        io.output:=mem.read(io.addr)
    }.otherwise{
        io.output:=0.U
    }
    
    
}
